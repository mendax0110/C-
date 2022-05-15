#include <avr/io.h>
#include <math.h>
#include <windows>
#include <stdio.h>
#include <bios.h>
#include <conio.h>

//connection to serial port
seralib serial;
if (serial.openDevice("COM0", 115200) !=1) 
    return 1;

//set DTR and unset RTS
serial.DTR(true);
serial.RTS(false);

//loop forever and display the pin status
while (1)
{
    //read and display the status of each pin (DTR should be 1, RTS should be 0)
    printf("4-DTR = %d\t", serial.isDTR());
    printf("7-RTS = %d\t", serial.isRTS());

    printf("1-DCD = %d\t", serial.isDCD());
    printf("8-CTS = %d\t", serial.isCTS());
    printf("6-DSR = %d\t", serial.isDSR());
    printf("9-RING = %d\n", serial.isRI());
}

