#include "global.h"


// ctor
LMSFilter::LMSFilter()
{
}


aec_status
LMSFilter::init()
{
    // clear the state buffer
//    memset(data, 0, (c_num_taps + (c_block_size - 1)) * sizeof(float32_t));
    for(auto i : data)
    {
        i = 0;
    }

    return SUCCESS;
}


aec_status 
LMSFilter::process(
    const float32_t* source,        // points to the block of input data
    const float32_t* reference,     // points to the block of reference data
    float32_t* output,              // points to the block of output data
    float32_t* error                // points to the block of error data
    )
{
    // init pointer
    float32_t* current_data = data;
    float32_t* new_data = &data[c_num_taps - 1];
    float32_t* coeff_ptr = coeffs;

    // TODO: add sizes of arrays to params and compare them against config values?

    // process data and append samples from source to data    
    for(uint16_t sample_cnt = c_block_size; sample_cnt > 0; sample_cnt--)
    {
        // copy new sample into the data buffer, included here to avoid another loop
        *new_data++ = *source++;


        // FIR-filter: apply coefficients to data
        float32_t acc = 0;
        for(uint16_t tap_cnt = c_num_taps; tap_cnt > 0; tap_cnt--)
        {
            // utilize DSP funcionality of the Cortex-M4
            // multiply-accumulate
            acc += (*current_data++) * (*coeff_ptr++);
        }
        // store result in output
        *output++ = acc;


        // compute error
        float32_t e = *reference++ - acc;
        *error++ = e;


        // compute weight
        float32_t weight = e * c_mu;


        // reset data and coefficients pointer
        current_data = data;
        coeff_ptr = coeffs;


        // apply weight to coefficients
        for(uint16_t tap_cnt = c_num_taps; tap_cnt > 0; tap_cnt--)
        {
            // utilize DSP funcionality of the Cortex-M4
            // multiply-accumulate
            *coeff_ptr += weight * (*current_data++);           // TODO: What is () for?
            coeff_ptr++;
        }
    }

    prepare_next_process();

    return SUCCESS;
}


aec_status 
LMSFilter::prepare_next_process()
{
    // init pointer
    float32_t* current_data = data;
    float32_t* new_data = &data[c_num_taps - 1];

    // copy appended data to front of data
    // alternative: implement a circular buffer                 // TODO: better performance?
    for(uint16_t tap_cnt = c_num_taps; tap_cnt > 0; tap_cnt--)
    {
        *current_data++ = *new_data++;
    }

    return SUCCESS;
}


