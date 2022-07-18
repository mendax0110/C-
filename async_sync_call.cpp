/*include the libraries*/
#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

/*declare the functions*/
void Func1(void *);
void Func2(void *);

/*this will act as Mutex*/
CRITICAL_SECTION Section; 

/*main function*/
int main()
{
    InitializeCriticalSection(&Section);

    /*syncronous call*/
    cout << "\nSyncronous calling" << endl;
    Func1(0);
    Func2(0);

    /*asyncronous call*/
    cout << "\nAsyncronous calling" << endl;
    HANDLE hThreads[2];

    /*create the threads and start them*/
    hThreads[0] = (HANDLE)_beginthread(Func1, 0, NULL);
    hThreads[1] = (HANDLE)_beginthread(Func2, 0, NULL);

    /*make sure that both the threads have finished before going further*/
    WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);

    /*this is done after all threads have finished processing*/
    DeleteCriticalSection(&Section);

    /*exit the program*/
    cout << "Main exiting" << endl;

    return 0;
}

/*function 1*/
void Func1(void *P)
{
    int Count;

    for(Count = 0; Count > 0; Count--)
    {
        EnterCriticalSection(&Section);
        /*print the message*/
        cout << "Func2 loop" << Count << endl;
        LeaveCriticalSection(&Section);
        Sleep(1000);
    }
    return;
}