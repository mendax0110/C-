#include <windows.h>
#include <process.h>
#include <iostream>

using namespace std;

void Func1(void *);
void Func2(void *);

CRITICAL_SECTION Section;   // This will act as Mutex

int main()
{
    InitializeCriticalSection(&Section);

    //Synchronous calling
    cout << "\nSynchronous calling" << endl;
    Func1(0);
    Func2(0);

    //Asynchronous calling
    cout << "\nAsynchronous calling" << endl;
    HANDLE hThreads[2];

    //Create two threads and start them
    hThreads[0] = (HANDLE)_beginthread(Func1, 0, NULL);
    hThreads[1] = (HANDLE)_beginthread(Func2, 0, NULL);

    //Make sure that both the threads have finished before going further
    WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);

    //This is done after all threads have finished processing
    DeleteCriticalSection(&Section);

    cout << "Main exit" << endl;
    return 0;
}

void Func1(void *P)
{
    int Count;

    for (Count = 10; Count > 0; Count--)
    {
        EnterCriticalSection(&Section);
        cout << "Func2 loop" << Count << endl;
        LeaveCriticalSection(&Section);
        Sleep(1000);
    }
    return;
}
