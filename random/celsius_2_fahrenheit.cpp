// include the header file
#include <iostream>

// use the standard namespace
using namespace std;

// main function
int main()
{
    float c;

    // get the input from the user
    cout << "Enter temperature in Celsius: ";
    cin >> c;

    // convert the temperature
    // calculate the first part of the formula
    float f = (c * 9 / 5); 
    // add the second part of the formula
    f += 32;

    // display the result
    cout << c << " degree Celsius = " << f << " degree Fahrenheit" << endl;
}