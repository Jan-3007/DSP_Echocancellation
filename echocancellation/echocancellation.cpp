#include "global.h"





int main()
{
    // workaround for the startup script not supporting C++
    CodecWM8731::create_instance();
    I2S_DSTC::create_instance();
    AEC::create_instance();

    // GPIO port configuration for 3 color LED, user button and test pin
	GpioInit();

    IF_DEBUG(Uart0Init(115200));
    IF_DEBUG(debug_printf("AEC: %s, %s\n", __DATE__, __TIME__));
    IF_DEBUG(debug_printf("Taps: %u\n", c_num_taps));


    g_aec->init();
    g_aec->run();


    
    return 0;
}

