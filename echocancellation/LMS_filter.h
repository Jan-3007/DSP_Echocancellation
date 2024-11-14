#pragma once



class LMS_filter
{
protected:

    // coefficients are stored in time reversed order
    float32_t coeffs[ c_num_taps ];
//    float32_t data[ (c_num_taps + c_block_size - 1) * sizeof(float32_t) ];
    float32_t data[ (c_num_taps + (c_block_size - 1)) ];


public:
    aec_status
    init();

    aec_status
    process(
        const float32_t* source,        // points to the block of input data
        const float32_t* reference,     // points to the block of reference data
        float32_t* output,              // points to the block of output data
        float32_t* error                // points to the block of error data
        );


protected:
    aec_status
    prepare_next_process();
};

