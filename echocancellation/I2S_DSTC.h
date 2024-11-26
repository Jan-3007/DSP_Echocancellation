#pragma once



class I2S_DSTC
{
protected:

    // TX buffer
    int32_t tx_buffer_space_[c_block_size * c_num_blocks];
    CircularBuffer<int32_t> tx_buffer_{c_block_size, tx_buffer_space_};

    // RX buffer
    int32_t rx_buffer_space_[c_block_size * c_num_blocks];
    CircularBuffer<int32_t> rx_buffer_{c_block_size, rx_buffer_space_};

    // DSTC descriptors
    stc_dstc_des0123456_t dstc_desc_[2];
    stc_dstc_des0123456_t& tx_desc_ {dstc_desc_[0]};
    stc_dstc_des0123456_t& rx_desc_ {dstc_desc_[1]};


public:
    // ctor
    I2S_DSTC();

    void
    init();

    
    
protected:
    void
    init_dstc();

    void
    init_i2s();


    void
    isr_tx();

    void
    isr_rx();

    static
    void
    isr_tx_static();

    static
    void
    isr_rx_static();

};



extern I2S_DSTC g_i2s_dstc;


