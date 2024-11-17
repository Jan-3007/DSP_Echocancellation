#include "global.h"
#include "CircularBuffer.h"



void 
CircularBuffer::reset()
{
    read_ptr_ = write_ptr_ = buffer_start_;
    buffer_full_ = false;
}


bool
CircularBuffer::write_sample(float32_t sample)
{
    if(buffer_full_)
    {
        return false;
    }

    // copy sample into buffer
    *write_ptr_++ = sample;                            

    // check if end of buffer is reached
    if(write_ptr_ == buffer_limit_)
    {
        write_ptr_ = buffer_start_;
    }

    if(write_ptr_ == read_ptr_)
    {
        // buffer full
        buffer_full_ = true;
    }

    return true;
}


bool
CircularBuffer::read_sample(float32_t& sample)
{
    if(is_empty())
    {
        // buffer empty
        return false;
    }

    // copy sample
    sample = *read_ptr_++;

    // check if end of buffer is reached
    if(read_ptr_ == buffer_limit_)
    {
        read_ptr_ = buffer_start_;
    }

    buffer_full_ = false;

    return true;
}


bool 
CircularBuffer::read_block(float32_t output[])
{
    // check if buffer has at least one block
    if(num_blocks_readable() == 0)
    {
        return false;
    }

    // copy data from buffer to sample_block
    for(size_t n = block_size_; n > 0; n--)
    {
        // copy sample
        *output++ = *read_ptr_++;

        // check if end of buffer is reached
        if(read_ptr_ == buffer_limit_)
        {
            read_ptr_ = buffer_start_;
        }
    }

    buffer_full_ = false;

    return true;
}


bool 
CircularBuffer::write_block(const float32_t input[])
{
    // check if buffer has at least one writeable block
    if(num_blocks_writeable() == 0)
    {
        return false;
    }

    // copy data from sample_block to buffer
    for(size_t n = block_size_; n > 0; n--)
    {
        // copy sample
        *write_ptr_++ = *input++;

        // check if end of buffer is reached
        if(write_ptr_ == buffer_limit_)
        {
            write_ptr_ = buffer_start_;
        }
    }

    if(write_ptr_ == read_ptr_)
    {
        // buffer full
        buffer_full_ = true;
    }

    return true;
}


bool
CircularBuffer::discard_block()
{
    // check if buffer has at least one block
    if(num_blocks_readable() > 0)
    {
        for(size_t n = block_size_; n > 0; n--)
        {
            read_ptr_++;
            
            // check if end of buffer is reached
            if(read_ptr_ == buffer_limit_)
            {
                read_ptr_ = buffer_start_;
            }
        }

        buffer_full_ = false;

        return true;
    }

    return false;
}


bool 
CircularBuffer::discard_sample()
{
    // check if buffer has at least one sample
    if(!is_empty())
    {
        read_ptr_++;
        
        // check if end of buffer is reached
        if(read_ptr_ == buffer_limit_)
        {
            read_ptr_ = buffer_start_;
        }

        buffer_full_ = false;
        
        return true;
    }

    return false;
}


size_t 
CircularBuffer::num_blocks_readable()
{
    return ( num_samples_readable() / block_size_ );
}


size_t CircularBuffer::num_blocks_writeable()
{
    return ( num_samples_writeable() / block_size_ );
}


size_t 
CircularBuffer::num_samples_readable()
{
    if(buffer_full_)
    {
        return get_buffer_size();
    }

    if(write_ptr_ >= read_ptr_)
    {
        return (write_ptr_ - read_ptr_);
    }
    else
    {
        return ( get_buffer_size() - (read_ptr_ - write_ptr_) );
    }
}


size_t 
CircularBuffer::num_samples_writeable()
{
    if(buffer_full_)
    {
        return 0;
    }

    if(write_ptr_ >= read_ptr_)
    {
        return ( get_buffer_size() - (write_ptr_ - read_ptr_) );
    }
    else
    {
        return (read_ptr_ - write_ptr_);
    }
}
