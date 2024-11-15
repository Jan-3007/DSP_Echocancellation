#pragma once




class CircularBuffer
{
protected:
    float32_t buffer[c_num_blocks * c_block_size];
    float32_t* read_ptr {buffer};
    float32_t* write_ptr {buffer};

public:
    // ctor
    CircularBuffer();

    aec_status
    init();

    aec_status
    write_sample(const float32_t& sample);

    aec_status
    read_block(float32_t sample_block[c_block_size]);                 // TODO: caller must supply array for values

    // check if a block of samples can be read
    bool
    empty();

protected:

};

