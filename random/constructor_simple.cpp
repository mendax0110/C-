// include the header file
#include <iostream>

// use standard namespace
using namespace std;

// constructor class
class construct
{
    public:

        int num;
        char ch;

        construct()
        {
            num = 100;
            ch = 'A';
        }
};

// main function
int main()
{
    construct obj;

    // print the values
    cout << "num = " << obj.num << endl;
    cout << "ch = " << obj.ch << endl;

    return 0;
}