// include the necessary headers
#include <iostream>
#include <thread>
#include <chrono>

// The function to run the program
void runProgam(const std::string& program)
{
    // Start the program
    std::system(program.c_str());
}

// The main function
int main()
{
    std::cout << "Enter the name of the program you want to run: ";
    std::string programName;
    std::cin >> programName;

    // Create a thread to run the program
    std::thread programThread(runProgam, programName);

    // Wait for the thread to finish
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Kill the thread
    programThread.join();

    return 0;
}