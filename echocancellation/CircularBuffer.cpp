#include "global.h"


// ctor
CircularBuffer::CircularBuffer()
{
}


aec_status
CircularBuffer::write_sample(const float32_t& sample)
{
    if( (write_ptr++) == read_ptr)
    {
        // buffer full
        IF_DEBUG(debug_printf("circ. buffer full\n"));
        return BUFFER_ERROR;
    }

    // copy sample into buffer
    *write_ptr = sample;                            // TODO: track number of copied samples -> if == block size -> interrupt/flag to run Filter

    // move write pointer forward
    ( (write_ptr++) == (buffer + 1) ) ? (write_ptr = buffer) : (write_ptr++);              // TODO: pointer arithmetic, move buffer ptr forward by size of buffer
    
    return SUCCESS;
}


aec_status 
CircularBuffer::read_block(float32_t sample_block[c_block_size])
{
    float32_t* temp_ptr = sample_block;

    // copy data from buffer to sample_block
    for(uint16_t n = 0; n < c_block_size; n++)
    {
        // check if buffer is empty
        if(empty())
        {
            // buffer empty
            IF_DEBUG(debug_printf("circ. buffer empty\n"));
            return BUFFER_ERROR;
        }

        // copy sample
        *temp_ptr++ = *read_ptr;

        // move read pointer forward
        ( (read_ptr++) == (buffer + 1) ) ? (read_ptr = buffer) : (read_ptr++);              // TODO: pointer arithmetic, move buffer ptr forward by size of buffer
    }

    return aec_status();
}


bool 
CircularBuffer::empty()
{
    ptrdiff_t diff = write_ptr - read_ptr;

    return (diff <= c_block_size && diff >= (-c_block_size));
}
