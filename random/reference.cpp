// include the header file
#include <iostream>

// use the standard namespace
using namespace std;

// 
void function(int & zahl2)
{
    // print the result
    cout << "Adresse der Zahl2: " << zahl2 << endl;
    zahl2 *= 2;
}

// main function
int main()
{
    int zahl1 = 5;

    // print the result, before the function call
    cout << "Zahl1 vor der Funktion: " << zahl1 << endl;
    cout << "Adresse der Zahl1: " << &zahl1 << endl;
    // call the function
    function(zahl1);
    // print the result, after the function call
    cout << "Zahl1 nach der Funktion: " << zahl1 << endl;
}
