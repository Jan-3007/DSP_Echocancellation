#pragma once



//------------------------------
//
// General
//
//------------------------------

// number of samples per block
constexpr uint32_t c_block_size = 8;


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



