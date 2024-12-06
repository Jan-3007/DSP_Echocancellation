#pragma once






class AEC
{
protected:
    // LMS filter
    LMSFilter lms_;

    // flag for de-/activating the AEC
    bool aec_active_ {true};
    bool button_pressed {false};

    uint32_t input_block_[c_block_size];
    float32_t right_input_block_[c_block_size];
    float32_t right_input_block_delayed_[c_block_size];
    float32_t left_input_block_[c_block_size];

    uint32_t output_block_[c_block_size];
    float32_t right_output_block_[c_block_size];
    float32_t left_output_block_[c_block_size];
//    float32_t float_output_block_[c_block_size];

    // buffer for reference delay
    float32_t delay_buffer_space_[c_block_size * c_delay_blocks];
    CircularBuffer<float32_t> delay_buffer_{c_block_size, delay_buffer_space_};


public:
    // ctor
    AEC();

    void
    init();

    void
    run();

    static
    void
    create_instance();

protected:
    void
    update_aec_flag();

    void
    process_aec();

    void
    loopback();

    void
    mic_passthrough();

    void
    convert_input();

    void
    convert_output();

    void 
    convert_output_LR();


    void
    check_errors();

    void
    update_led();    
};


extern AEC* g_aec;

