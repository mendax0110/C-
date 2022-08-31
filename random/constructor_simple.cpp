/*include the header file*/
#include <iostream>

using namespace std;

/*constructor class*/
class construct
{
    public:
        int num;
        char ch;

        construct()
        {
            num = 100;
            ch  = 'A';
        }
};

/*main function*/
int main()
{
    construct obj;

    cout << "num: " << obj.num << endl;
    cout << "ch: "  << obj.ch;

    return 0;
}