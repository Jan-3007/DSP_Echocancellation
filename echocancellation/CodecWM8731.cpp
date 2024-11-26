#include "global.h"




CodecWM8731 g_codec;





CodecWM8731::CodecWM8731()
{
    init();
}


void
CodecWM8731::init()
{
    // Activate I2C interface to CODEC and configure CODEC registers
	CodecInit(c_samp_freq, c_audio_source);
}



