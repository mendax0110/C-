// include the necessary headers
#include <iostream>
#include <Windows.h>

int main()
{
    // Enumerate the available serial ports
    auto ports = EnumSerialPorts();
    for (const auto& port : ports)
    {
        std::cout << port << std::endl;
    }

    // Open a serial port
    auto hPort = CreateFile("COM3", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hPort == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to open serial port" << std::endl;
        return 1;
    }

    // Configure the serial port
    DCB dcb;
    memset(&dcb, 0, sizeof(dcb));
    dcb.DCBlength = sizeof(dcb);
    dcb.BaudRate = CBR_9600;
    dcb.Parity = NOPARITY;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    if (!SetCommState(hPort, &dcb))
    {
        std::cerr << "Failed to configure serial port" << std::endl;
        return 1;
    }

    // Send data over the serial port
    std::string data = "DATA, IN, THE, SERIAL, PORT";
    DWORD bytesWritten;
    if (!WriteFile(hPort, data.c_str(), data.size(), &bytesWritten, NULL))
    {
        std::cerr << "Failed to write data to serial port" << std::endl;
        return 1;
    }

    // Receive data from the serial port
    char buffer[1024];
    DWORD bytesRead;
    if (!ReadFile(hPort, buffer, sizeof(buffer), &bytesRead, NULL))
    {
        std::cerr << "Failed to read data from serial port" << std::endl;
        return 1;
    }

    // Print the received data
    std::cout << "Received: " << std::string(buffer, bytesRead) << std::endl;

    // Close the serial port
    CloseHandle(hPort);

    return 0;
}
