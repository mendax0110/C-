// include the header file
#include <Windows.h>
#include <stdio.h>
#include <starg.h>
#include <utils.h>
#include <vm.h>
#include <vector>
#include <sstream>
#include <string>

// use the standard namespace
using namespace std;

// main function
int main(int argc, char **argv)
{
    bool verbose = false;
    wstring script_path = Utils::GetExecutablePath();

    for(int i = 0; i < argc; i++)
    {
        string argument = argv[i];

        if(argument == "--verbose")
        {
            verbose = true;
        }

        size_t ivyExt = argument.find(".ivy");
        if(ivyExt != -1)
        {
            size_t isDrive = argument.find(":");
            wstring path(argument.begin(), argument.end());

            if(isDrive != -1)
            {
                script_path = path;
            }
            else
            {
                script_path = Utils::GetExecutablePath() + L"\\" + path;
            }
        }
    }

    // create a new VM
    VM * vm = new VM(scipt_path, verbose);
    vm->Run();
    SetConsoleTextAttribute(Utils::hConsole, Utils::CONSOLE_DEFAULT);

    return 0;
}

