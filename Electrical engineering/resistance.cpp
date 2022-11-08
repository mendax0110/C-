// include the header file
#include <iostream>

// use the standard namespace
using namespace std;

// main function
int main()
{
    // declare variables
    float voltage;
    float ampere;

    // ask for voltage
    cout << "Please enter the voltage: ";
    cin >> voltage;

    // ask for ampere
    cout << "Please enter the ampere: ";
    cin >> ampere;

    // calculate resistance
    float resistance = voltage / ampere;

    // print the result
    cout << "The resistance is: " << resistance << endl;

    // return 0
    return 0;
}