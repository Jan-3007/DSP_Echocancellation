#pragma once



//------------------------------
//
// General
//
//------------------------------

// number of samples per block
// @48kHz   -> 48 samples/block = 1 ms sampling time
//          -> 96 samples/block = 2 ms sampling time
//          -> 140 samples/block = 5 ms sampling time
constexpr uint32_t c_block_size = 48;

// number of blocks to delay reference signal
// current hardware setup requires a delay of about 80 ms
// @1 ms sampling time -> delay blocks = 80
// @2 ms sampling time -> delay blocks = 40
// @5 ms sampling time -> delay blocks = 16
constexpr uint32_t c_delay_blocks = 90;



//------------------------------
//
// Codec WM8731
//
//------------------------------

// sampling frequency
constexpr sampling_rate c_samp_freq = hz48000;

// DAC input: line_in, mic_in
// line_in -> 2 channels
// mic_in -> 1 channel
constexpr audio_input c_audio_source = line_in;



//------------------------------
//
// RX/TX DMA FIFO
//
//------------------------------

// number of blocks the buffer can hold
constexpr uint32_t c_fifo_size_blocks = 3;


//------------------------------
//
// LMS Filter
//
//------------------------------

constexpr uint32_t c_num_taps = 4096*4;

// 0 <= mu <= 2
constexpr float32_t c_mu = 0.02;






