// include the libraries
#include <iostream>
#include <math.h>

// use the standard namespace
using namespace std;

// main function
int main()
{
    long int i, no;
    int x, y = 0;

    // get a binary number from the user
    cout << "Enter a binary number: ";
    cin >> no;

    // print the decimal number
    cout << "\nThe decimal dequivalent of " << no << " is: ";

    // cconvert the binary number to decimal
    for(i = 0; no != 0; i++)
    {
        x %= 10;
        y = y + x * pow(2, i);
        no /= 10;
    }

    // print the decimal number
    cout << y << endl;

    return 0;
}