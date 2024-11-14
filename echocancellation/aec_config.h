#pragma once



//------------------------------
//
// General
//
//------------------------------

// number of samples per block
constexpr uint16_t c_block_size = 8;



//------------------------------
//
// LMS Filter
//
//------------------------------

constexpr uint16_t c_num_taps = 32;
// 0 <= mu <= 2
constexpr float32_t c_mu = 1;



