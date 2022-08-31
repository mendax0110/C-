/*include the header files*/
#include <iostream>
#include <string>
#include <Windows.h>
#include <WinBase.h>
#include <stdio.h>
#include <tchar.h>

using namespace std;

HANDLE hCom;

/*two functions setting and reading flags*/
DWORD sendData(const char* data, DWORD size)
{
    DWORD numberOfBytesWritten;

    WriteFile(hCom, data, size, &numberOfBytesWritten, 0);

    return numberOfBytesWritten;
}

/*set the bit*/
void PrintCommState(DCB dcb)
{
    /*print the DCB structure values*/
    _tprintf(TEXT("\nBaudrate = %d, ByteSize = %d, Parity = %d, StopBits = %d\n"),
            dcb.BaudRate, dcb.ByteSize, dcb.Parity, dcb.StopBits);

}

/*initialize the COM port*/
int init_usb()
{
    DCB dcb;
    BOOL fSuccess;

    /*for COM port which are greater then 9*/
    TCHAR const *pcCommPort = TEXT("\\\\.\\COM28");

    /*open the COM port*/
    hCom = CreateFile(pcCommPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if(hCom == INVALID_HANDLE_VALUE)
    {
        /*handle the error*/
        printf("CreateFile failed with error %d.\n", GetLastError());

        return(1);
    }

    /*initialize the DCB structure*/
    ZeroMemory(&dcb, sizeof(DCB));
    dcb.DCBlength = sizeof(DCB);

    /*build on the current config by first retrieving it*/
    fSuccess = GetCommState(hCom, &dcb);

    if(!fSuccess)
    {
        /*handle the error*/
        printf("GetCommState failed with error %d.\n", GetLastError());
        CloseHandle(hCom);
        return(2);
    }

    /*output tp the console the current state of the COM port*/
    PrintCommState(dcb);

    /*fill in the DCB values and set the com state:*/
    dcb.BaudRate = CBR_38400;
    dcb.ByteSize = 8;
    dcb.Parity   = NOPARITY;
    dcb.StopBits = ONESTOPBIT; 

    fSuccess = SetCommState(hCom, &dcb);

    if(!fSuccess)
    {
        /*handle the error*/
        printf("SetCommState failed with error %d.\n", GetLastError());
        CloseHandle(hCom);
        return(3);
    }

    /*get the comm config again*/
    fSuccess = GetCommState(hCom, &dcb);

    if(!fSuccess)
    {
        /*handle the error*/
        printf("GetCommState failed with error %d.\n", GetLastError());
        CloseHandle(hCom);
        return(2);
    }

    /*print the COM state*/
    PrintCommState(dcb);
    
    _tprintf(TEXT("Serial port %s successfully reconfigured.\n"), pcCommPort);
    
    return(0);
}

/*main function*/
int main(int argc, char** argv)
{
    init_usb();

    char const *ch = "MD2X1Y4N";
    int size = sendData(ch, sizeof("MD2X1Y4N"));

    if(size != sizeof("MD2X1Y4N"))
    {
        /*print the error in the sending data*/
        printf("Error in sending data.\n");
    }
    else
    {
        /*print the success in the sending data*/
        printf("%d sent .Sent succeeded.\n", size);
    }

    return 0;
}