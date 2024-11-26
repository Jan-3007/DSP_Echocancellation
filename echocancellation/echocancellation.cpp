#include "global.h"





int main()
{
    // GPIO port configuration for 3 color LED, user button and test pin
	GpioInit();

    IF_DEBUG(Uart0Init(115200));
    IF_DEBUG(debug_printf("AEC: %s, %s\n", __DATE__, __TIME__));


    static AEC aec;
    aec.init();
    aec.run();


    return 0;
}

