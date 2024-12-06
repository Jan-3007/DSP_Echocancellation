#include "global.h"
#include "AEC.h"


AEC* g_aec;


AEC::AEC()
{
}


void AEC::init()
{
    lms_.init();

    g_codec->init();

    g_i2s_dstc->init();

    for(uint32_t i = c_delay_blocks; i > 0; i--)
    {
        delay_buffer_.fill_block(0);
    }
}


void
AEC::run()
{
    update_led();


    constexpr uint32_t button_divider = 1000;
    uint32_t btn_cnt = button_divider;

    constexpr uint32_t monitor_divider = 10*1000*1000;
    uint32_t monitor_cnt = monitor_divider;
    
    // start I2S and DSTC
    g_i2s_dstc->start();

    // main loop
    while(true)
    {
#if 0
        loopback();
#else

        if(aec_active_)
        {
            process_aec();
        }
        else
        {
            mic_passthrough();
        }
#endif
#if 1
        if(0 == --btn_cnt)
        {
            btn_cnt = button_divider;
            update_aec_flag();
        }

        if(0 == --monitor_cnt)
        {
            monitor_cnt = monitor_divider;
            check_errors();
        }
#endif
    }
}


void 
AEC::create_instance()
{
    static AEC aec_instance;
    g_aec = &aec_instance;
}


void 
AEC::update_aec_flag()
{
    if(button_pressed)
    {
        if(gpio_get(USER_BUTTON) != 0)
        {
            button_pressed = false;
        }
    }
    else
    {
        if(gpio_get(USER_BUTTON) == 0)
        {
            button_pressed = true;

            if(aec_active_)
            {
                aec_active_ = false;
                update_led();
                IF_DEBUG(debug_printf("AEC off\n"));

            }
            else
            {
                aec_active_ = true;
                update_led();
                IF_DEBUG(debug_printf("AEC on\n"));
            }
        }
    }
}


void 
AEC::update_led()
{
    if(aec_active_)
    {
        // LED_R off
        gpio_set(LED_R, HIGH);
        // LED_G off
        gpio_set(LED_G, HIGH);
        // LED_B on
        gpio_set(LED_B, LOW);
    }
    else
    {
        // LED_R off
        gpio_set(LED_R, HIGH);
        // LED_B off
        gpio_set(LED_B, HIGH);
        // LED_G on
        gpio_set(LED_G, LOW);
    }
}


void 
AEC::process_aec()
{
    // try to read input
    if(g_i2s_dstc->read_rx_block(input_block_) == false)
    {
        return;
    }
    
    convert_input();

    delay_buffer_.read_block(right_input_block_delayed_);
    delay_buffer_.write_block(right_input_block_);

    // process input
    lms_.process(
        right_input_block_delayed_,             // source = reference signal
        left_input_block_,                      // reference  = microphone
        right_output_block_,                    // output = FIR out
        left_output_block_                      // error = output
        );

    convert_output();
//    convert_output_LR();

    // write output
    g_i2s_dstc->write_tx_block(output_block_);
}


void 
AEC::mic_passthrough()
{
    if(g_i2s_dstc->read_rx_block(input_block_) == false)
    {
        return;
    }
    
    convert_input();

    // output = input L
    for(uint32_t i = 0; i < c_block_size; i++)
    {
//        left_output_block_[i] = right_input_block_[i];
        left_output_block_[i] = left_input_block_[i];
    }

    convert_output();

    g_i2s_dstc->write_tx_block(output_block_);
}


void 
AEC::loopback()
{
    if(g_i2s_dstc->read_rx_block(input_block_) == false)
    {
        return;
    }
    
    // reading block was successful

    // copy input to output
    uint32_t* input = input_block_;
    uint32_t* output = output_block_;
    for(uint32_t i = c_block_size; i > 0; i--)
    {
        *output++ = *input++;
    }

    g_i2s_dstc->write_tx_block(output_block_);
}


void 
AEC::convert_input()
{
    // split channels and convert to float
    const uint32_t* input = input_block_;
    for(uint32_t i = 0; i < c_block_size; i++)
    {
        uint32_t tmp = *input++;
        // right = LSB
        // left = MSB
        int16_t right = static_cast<int16_t>(tmp);
        int16_t left = static_cast<int16_t>(tmp >> 16);

        float32_t right_f = static_cast<float32_t>(right) / 32768.0f;
        float32_t left_f = static_cast<float32_t>(left) / 32768.0f;

        right_input_block_[i] = right_f;
        left_input_block_[i] = left_f;
    }
}


void 
AEC::convert_output()
{
    // convert to int and combine channels
    uint32_t* output = output_block_;
    for(uint32_t i = 0; i < c_block_size; i++)
    {
//        float32_t smp_f = right_output_block_[i];
        float32_t smp_f = left_output_block_[i];

        int16_t smp_i = static_cast<int16_t>( __SSAT( static_cast<int32_t>(smp_f * 32768.0f), 16) );

        uint32_t smp_u = static_cast<uint16_t>(smp_i);

        // duplicate signal on right and left channels
        uint32_t tmp = (smp_u << 16) | smp_u;
        *output++ = tmp;
    }
}


void 
AEC::convert_output_LR()
{
    // convert to int and combine channels
    uint32_t* output = output_block_;
    for(uint32_t i = 0; i < c_block_size; i++)
    {
        float32_t smp_l = left_output_block_[i];
        float32_t smp_r = right_output_block_[i];

        int16_t smp_l_i = static_cast<int16_t>( __SSAT( static_cast<int32_t>(smp_l * 32768.0f), 16) );
        int16_t smp_r_i = static_cast<int16_t>( __SSAT( static_cast<int32_t>(smp_r * 32768.0f), 16) );

        uint32_t smp_l_u = static_cast<uint16_t>(smp_l_i);
        uint32_t smp_r_u = static_cast<uint16_t>(smp_r_i);

        // duplicate signal on right and left channels
        uint32_t tmp = (smp_l_u << 16) | smp_r_u;
        *output++ = tmp;
    }
}


void 
AEC::check_errors()
{
    I2S_DSTC::Errors errors;

    g_i2s_dstc->capture_errors(errors);

    if(errors.tx_buffer_overrun > 0)
    {
        IF_DEBUG(debug_printf("tx_buffer_overrun = %u\n", errors.tx_buffer_overrun));
    }
    if(errors.tx_buffer_underrun > 0)
    {
        IF_DEBUG(debug_printf("tx_buffer_underrun = %u\n", errors.tx_buffer_underrun));
    }
    if(errors.rx_buffer_overrun > 0)
    {
        IF_DEBUG(debug_printf("rx_buffer_overrun = %u\n", errors.rx_buffer_overrun));
    }
// rx underrun is not an error
#if 0
    if(errors.rx_buffer_underrun > 0)
    {
        IF_DEBUG(debug_printf("rx_buffer_underrun = %u\n", errors.rx_buffer_underrun));
    }
#endif
}


