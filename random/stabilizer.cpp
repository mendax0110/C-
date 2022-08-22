/*include the header file*/
#include "mbed.h"
#include <cmath>
    
Ticker toggle_led_ticker; //led blinker
Ticker toggle_readandwrite_ticker; //read and write

AnalogIn    analog_value1(PA_0); //analog input
AnalogIn    analog_value2(PA_1); //analog input
AnalogOut   analog_output1(PA_4); //analog output
AnalogOut   analog_output2(PA_5); //analog output
DigitalOut  myled(PC_3); //led
InterruptIN callback(USER_BUTTON); //button

int RANGE           = 65535; //16 bit DAC in software
int CYCLE           = 200;   //milliseconds 5 khz
float VRANGE        = 3.3;  
int TWO             = 2;
int ZERO            = 0;
float BUFFER        = 0.25; //0-1
float PMPDGAIN      = 16.5; //PD2 16
int CMDGAIN         = 50;   //50 ma/V
float SLOPE         = 1.252;//mW/mA
int THRESHOLD       = 35;   //mA
float THETARATIO    = 1;    //0-1

bool status = true;

void toggle_led()
{
    myled = !myled;
}

/*read and write function*/
float Vcmd, Vpd, Vnp, Vnn, diff;

void toggle_readandwrite()
{
    Vcmd = VRANGE * analog_value1.read(); //read analog input
    Vpd = VRANGE * analog_value2.read(); //read analog input

    if((TWO * Vcmd * CMDGAIN - THRESHOLD) > ZERO) 
    {
        diff = TWO * Vcmd - ((Vpd * PMPDGAIN / (SLOPE * THETARATIO)) + THRESHOLD / CMDGAIN);
    }
    else
    {
        diff = ZERO;
    }

    if(diff > ZERO)
    {
        Vnp = BUFFER * fabs(diff * RANGE / VRANGE);
        Vnn = ZERO;
    }
    else
    {
        Vnp = ZERO;
        Vnn = BUFFER * fabs(diff * RANGE / VRANGE) / TWO;
    }

    my_output.write_u16(Vnp); //write analog output
    my_output2.write_u16(Vnn); //write analog output
}

/*button control*/
void pressed()
{
    status = !status;

    if(status)
    {
        /*read and write cycle on*/
        toggle_readandwrite_ticker.attach_us(&toggle_readandwrite, CYCLE);

        /*led blinker on*/
        toggle_led_ticker.attach_us(&toggle_led, 0.1);
    }
    else
    {
        /*read and write cycle off*/
        toggle_readandwrite_ticker.detach();
        my_output1.write_u16(0);
        my_output2.write_u16(0);

        /*led blinker off*/
        toggle_led_ticker.detach();
        myled = 0;
    }
}

/*main function*/
int main()
{
    /*set the button*/
    callback.fall(&pressed);

    while(1)
    {
        /*do nothing*/
    }
}