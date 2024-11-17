#pragma once


// C++
#include <stdio.h>


// PDL
extern "C"
{
#include <platform.h>
#include <utils.h>
}


// CMSIS-DSP
#include "arm_math.h"


// custom
#include "debug_utils.h"
#include "aec_utils.h"
#include "aec_config.h"
#include "CircularBuffer.h"
#include "CFAR.h"
#include "LMSFilter.h"



