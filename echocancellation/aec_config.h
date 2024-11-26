#pragma once



//------------------------------
//
// General
//
//------------------------------

// number of samples per block
constexpr uint32_t c_block_size = 24;


//------------------------------
//
// DMA / DSTC
//
//------------------------------

// 1 - 256 and multiples of 256 (e.g. 512, 768, 1024, ...)
constexpr uint32_t c_dstc_buffer_size = 512; 


//------------------------------
//
// circular buffer
//
//------------------------------

// number of blocks the buffer can hold
constexpr uint32_t c_num_blocks = 3;


//------------------------------
//
// CFAR
//
//------------------------------

// count of cells refer to one side only
constexpr float32_t c_threshold_factor = 1;
constexpr uint32_t c_num_guard_cells = 1;
constexpr uint32_t c_num_ref_cells = 2;

constexpr float32_t c_alpha = 1;


//------------------------------
//
// LMS Filter
//
//------------------------------

constexpr uint32_t c_num_taps = 32;
// 0 <= mu <= 2
constexpr float32_t c_mu = 1;


//------------------------------
//
// Codec WM8731
//
//------------------------------

constexpr sampling_rate c_samp_freq = hz48000;
// DAC input: line_in, mic_in
constexpr audio_input c_audio_source = line_in;

// I2S instance
#define C_I2S_INSTANCE      I2S0

// I2S operating mode: intr, dma, poll
constexpr uint32_t c_i2s_op_mode = intr;




