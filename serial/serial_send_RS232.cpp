/*include the header file*/
#include <iostream>
#include <windows.h>

/*define the baudrate and delay time*/
#define BAUD 9600
#define DELAY_TIME 100

/*define the serial port name*/
const char* STUDYOS = "STUDY - OS";

/*define the serial port handle*/
void setup() 
{
    Serial.begin(BAUD);
}

/*define the serial port send function*/
void loop() 
{
    Serial.println(STUDYOS);
    delay(DELAY_TIME);
}
