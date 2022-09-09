/*include the libraries*/
#include <iostream>
#include <Windows.h>

using namespace std;

/*main function*/
int main()
{
    /*store the value, which we read from the process*/
    int readTest = 0;

    HWND hwnd = FindWindowA(NULL, "test.exe");

    /*check if the HWND found the window*/
    if(hwnd == NULL)
    {
        cout << "Error: HWND not found." << endl;
        Sleep(2000);
        exit(-1);
    }
    else
    {
        /*a 32-bit unsigned integer, DWORD use to store hexadecimal*/
        DWORD procID;
        GetWindowThreadProcessId(hwnd, &procID);
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

        if(procID == NULL)
        {
            cout << "Error: procID not found." << endl;
            Sleep(2000);
            exit(-1);
        }
        else
        {
            /*read the mem, 03007640 is the address to read from*/
            ReadProcessMemory(handle, (PBYTE*)0x03007640, &readTest, sizeof(readTest), 0);
            cout << "Value: " << readTest << endl;
            Sleep(2000);
        }
    }
}