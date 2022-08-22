#include <avr/io.h>
#include <math.h>
#include <windows.h>

HANDLE hCom[2];

/***************************************************/

void port_initialierung(char port_name[], DWORD baudrate, BYTE byte_groesse, BYTE anz_stopbits)
{
    DCB interface_parameter;
    COMMTIMEOUTS timeout_einstellungen;
    static int cnt = 0;

    hCom[++cnt] = CreateFileA(
        port_name,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    GetCommState(hCom, & interface_parameter);
    interface_parameter.DCBlength = sizeof(interface_parameter);
    interface_parameter.BaudRate = baudrate;
    interface_parameter.Bytesize = byte_groesse;
    interface_parameter.Stopbits = anz_stopbits;
    interface_parameter.Parity = NOPARITY;
    SetCommState(hCom, & interface_parameter);

    timeout_einstellungen.ReadIntervalTimeout = 100;
    timeout_einstellungen.ReadTotalTimeoutMultiplier = 100;
    timeout_einstellungen.ReadTotalTimeoutConstant = 100;
    timeout_einstellungen.WriteTotalTimeoutMultiplier = 100;
    timeout_einstellungen.WriteTotalTimeoutConstant = 100;
    SetCommTimeouts(hCom, & timeout_einstellungen);
}

/***********************************************************************/
void port_schliessen(int port)
{
    CloseHandle(hCom[port]);
}

/***********************************************************************/

void zeichen_senden(int port, char zeichen)
{
    DWORD i;

    WriteFile(hcom[port], & zeichen, 1, &i, NULL);
}

/***********************************************************************/

char zeichen_empfangen(int port)
{
    char    zeichen;
    DWORD   i;

    ReadFile(hcom[port], & zeichen, 1, &i, NULL);

    return zeichen;
}

/**********************************************************************/

#define COM 0
#define COM 1

int main(void)
{
    char gelesenes_zeichen[2];

    port_initialierung("COM0", 9600, 8, 1);
    port_initialierung("COM1", 9600, 8, 1);

    zeichen_senden(COM1, 'Übertragung');

    gelesenes_zeichen[0] = zeichen_empfangen(COM0);
    gelesenes_zeichen[1] = '\0';

    MessageBoxA(NULL, gelesenes_zeichen, "", MB_OK);

    port_schliessen(COM0);
    port_schliessen(COM1);

    return 0;
}
