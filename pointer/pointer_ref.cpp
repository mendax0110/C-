// include the header file
#include <iostream>

// use the standard namespace
using namespace std;

// declare the function
void function(int & num2)
{
    cout << "The address of num2 is: " << &num2 << endl;
    num2 *= 2;
}

// main function
int main()
{
    int num1 = 5;

    // call the function
    cout << "The address of num1 is: " << &num1 << endl;
    cout << "The value of num1 is: " << num1 << endl;
    function(num1);

    // print the value of num1
    cout << "The value of num1 is: " << num1 << endl;
}