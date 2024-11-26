#include "global.h"




void
AEC::init()
{
    g_codec.init();

    g_i2s_dstc.init();
}


void
AEC::run()
{
    // LED_G on
	gpio_set(LED_G, LOW);		

    while(true)
    {
        update_aec_flag();



        if(aec_active_)
        {
//            arm_q31_to_float();
//            arm_float_to_q31();
        }
        

    }



}


void 
AEC::update_aec_flag()
{
    if( USER_BUTTON == 0)
    {
        if(aec_active_)
        {
            aec_active_ = false;
        }
        else
        {
            aec_active_ = true;
        }
    }
}



