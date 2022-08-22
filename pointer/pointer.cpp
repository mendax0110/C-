/*include the library*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int a[3] = {1, 2, 3};

    /*for loop*/
    for (int i = 0; i < 3; i++)
    {
        /*print the value of a[i]*/
        cout << a[i] << endl;
        cout << &a[i] << endl << endl;
    }

    /*pointer*/
    cout << endl << endl;

    for(int input  : a)
    {
        /*print the input*/
        cout << input << endl;
        cout << &input << endl << endl;
    }
}
