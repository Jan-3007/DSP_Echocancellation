#pragma once




class CircularBuffer
{
protected:
    float32_t* buffer_start_;
    float32_t* buffer_limit_;
    float32_t* read_ptr_;
    float32_t* write_ptr_;
    size_t block_size_;
    bool buffer_full_ {false};

public:
    // ctor
    // buffer_size is number of float items
    CircularBuffer(size_t block_size, float32_t buffer[], size_t buffer_size)
        : buffer_start_ {buffer}, buffer_limit_ {buffer + buffer_size}, read_ptr_ {buffer}, write_ptr_ {buffer}, block_size_ {block_size}
        {}

    template <size_t N>
    CircularBuffer(size_t block_size, float32_t (&buffer)[N])
        : buffer_start_ {buffer}, buffer_limit_ {buffer + N}, read_ptr_ {buffer}, write_ptr_ {buffer}, block_size_ {block_size}
        {}

    size_t
    get_buffer_size() const
        {
            return (buffer_limit_ - buffer_start_);
        }

    size_t
    get_block_size() const
        {
            return block_size_;
        }

    bool
    is_empty() const
        {
            return (read_ptr_ == write_ptr_ && !buffer_full_);
        }

    bool
    is_full() const
        {
            return buffer_full_;
        }

    void
    reset();

    // returns false if buffer is full
    bool
    write_sample(float32_t sample);

    // returns false if buffer is empty
    bool
    read_sample(float32_t& sample);

    // output buffer must be at least of block size
    // returns false if no block can be read
    bool
    read_block(float32_t output[]);

    bool
    write_block(const float32_t input[]);

    bool
    discard_block();

    bool
    discard_sample();

    size_t
    num_blocks_readable();

    size_t
    num_blocks_writeable();

    size_t
    num_samples_readable();

    size_t
    num_samples_writeable();


protected:

};

