#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>

// Mutex to synchronize access to the vector of threads
std::mutex thread_mutex;

// Vector to store the threads
std::vector<std::thread> threads;

// Function to start a new instance of winspice.exe in a separate thread
void start_winspice()
{
    // Lock the mutex to synchronize access to the vector of threads
    std::lock_guard<std::mutex> lock(thread_mutex);

    // Create a new thread to run the winspice process
    threads.emplace_back([]() {
        std::system("C:\\Program Files (x86)\\OuseTech\\WinSpice\\winspice3.exe");
    });
}

// Function to stop a specific instance of winspice.exe
void stop_winspice(int index)
{
    // Lock the mutex to synchronize access to the vector of threads
    std::lock_guard<std::mutex> lock(thread_mutex);

    // Check if the index is valid
    if (index < 0 || index >= threads.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    // Check if the thread is joinable
    if (threads[index].joinable()) {
        // Detach the thread
        threads[index].detach();
    }
}

// Function to kill a specific instance of winspice.exe
void kill_winspice(int index)
{
    // Lock the mutex to synchronize access to the vector of threads
    std::lock_guard<std::mutex> lock(thread_mutex);

    // Check if the index is valid
    if (index < 0 || index >= threads.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    // Check if the thread is joinable
    if (threads[index].joinable()) {
        // Terminate the thread
        std::terminate();
    }
}

// Function to restart a specific instance of winspice.exe
void restart_winspice(int index)
{
    // Lock the mutex to synchronize access to the vector of threads
    std::lock_guard<std::mutex> lock(thread_mutex);

    // Check if the index is valid
    if (index < 0 || index >= threads.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    // Check if the thread is joinable
    if (threads[index].joinable()) {
        // Detach the thread
        threads[index].detach();
    }

    // Create a new thread to run the winspice process
    threads[index] = std::thread([]() {
        std::system("C:\\Program Files (x86)\\OuseTech\\WinSpice\\winspice3.exe");
    });
}

// Main function
int main()
{
    // Start a new instance of winspice.exe
    start_winspice();

    // Wait for user input
    std::string input;
    std::cin >> input;

    // Stop the first instance of winspice.exe
    stop_winspice(0);

    // Wait for user input
    std::cin >> input;

    // Kill the first instance of winspice.exe
    kill_winspice(0);

    // Wait for user input
    std::cin >> input;

    // Restart the first instance of winspice.exe
    restart_winspice(0);

    // Wait for user input
    std::cin >> input;

    // Stop all instances of winspice.exe
    for (int i = 0; i < threads.size(); i++) {
        stop_winspice(i);
    }

    // Wait for user input
    std::cin >> input;

    // Kill all instances of winspice.exe
    for (int i = 0; i < threads.size(); i++) {
        kill_winspice(i);
    }

    // Wait for user input
    std::cin >> input;

    // Restart all instances of winspice.exe
    for (int i = 0; i < threads.size(); i++) {
        restart_winspice(i);
    }

    // Wait for user input
    std::cin >> input;
}