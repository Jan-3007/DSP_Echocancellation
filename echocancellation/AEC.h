#pragma once






class AEC
{
protected:
    // LMS filter
    LMSFilter lms_;

    // flag for de-/activating the AEC
    bool aec_active_ {false};
    bool button_pressed {false};

    uint32_t input_block_[c_block_size];
    float32_t right_input_block_[c_block_size];
    float32_t left_input_block_[c_block_size];

    uint32_t output_block_[c_block_size];
    float32_t float_output_block_[c_block_size];


public:
    void
    init();

    void
    run();

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
    check_errors();

    void
    update_led();    
};

