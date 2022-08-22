#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "wsc.h"

//Send command string & wait for response

int SendCommand(int Port, int Baud, char * Command, char * Buffer, int bufLen)
{
    int code;
    //reset (open) port (with 1024 TX & RX buffers)
    code = SioReset(Port, 1024, 1024);
    //error? (negative return codes are errors)
    if (code < 0) return code;
    //send baud rate
    code = SioBaud(Port, Baud);
    if (code < 0) return code;
    //send string
    code = SioPuts(Port, Command, strlen(Command));
    if (code < 0) return code;
    //wait up to 250 ms for a response
    if (SioWaitFor (Port, 250) < 0) return code;
    //allow time for entire response (depends on serial device)
    Sleep(1);
    //return data
    return SioGets(Port, Buffer, Buflen);
}
