// include the header files
#include <iostream>

// use the standard namespace
using namespace std;

// function
void function(int* zahl2)
{
    // print the value of the pointer
    cout << "Address of number2: " << &zahl2 << endl;
    *zahl2 *= 2;
}

// main function
int main()
{
    // declare a variable
    int zahl1 = 10;

    // print the value of the variable
    cout << "Value of number1: " << zahl1 << endl;
    // print the address of the variable
    cout << "Address of number1: " << &zahl1 << endl;

    // call the function
    function(&zahl1);
    
    // print the value of the variable
    cout << "Value of number1: " << zahl1 << endl;
    // print the address of the variable
    cout << "Address of number1: " << &zahl1 << endl;
    
    // return 0
    return 0;
}