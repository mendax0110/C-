// include the header file
#include <iostream>
#include <string>

// define the baudrate, delaytime and the led
#define BAUDRATE 9600
#define DELAYTIME 1000
#define LED 13

String receivedString;

// read and write the serial port
void setup()
{
    // initialize the serial port
    if(Serial.available() > 0)
    {
        // read the serial port
        receivedString = Serial.readStringUntil('\n');
    }

    // initialize the serial port
    if(receivedString.equals("ON"))
    {
        // turn on the led
        digitalWrite(LED, HIGH);
    }
    else if(receivedString.equals("OFF"))
    {
        // turn off the led
        digitalWrite(LED, LOW);
    }
}