// include the header file
#include <iostream>

using namespace std;

// main function
int main()
{
    int numOne, numTwo, lcm, hcf, a, b, temp;

    // take input from user
    cout << "Enter two numbers: ";
    cin >> numOne >> numTwo;

    // assign the value of numOne and numTwo to a and b
    a = numOne;
    b = numTwo;

    // find the LCM
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    // assign the value of a to hcf
    hcf = a;

    // find the LCM
    lcm = (numOne * numTwo) / hcf;

    // print the LCM and HCF
    cout << "\nLCM (" << numOne << ", " << numTwo << ") = " << lcm;
    cout << "\nHCF (" << numOne << ", " << numTwo << ") = " << hcf;
    cout << endl;

    // return the value
    return 0;
}