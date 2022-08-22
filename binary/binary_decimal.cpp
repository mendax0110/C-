/*include the libraries*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long int i, no;
    int x, y = 0;

    /*give the binary number*/
    cout << "Enter a binary number: ";
    cin >> no;
    /*convert the binary number to decimal*/
    cout << "\nThe decimal equivalent of " << no << " is: ";

    for(i = 0; no != 0; i++)
    {
        x = no % 10;
        y = y + x * pow(2, i);
        no = no / 10;
    }

    cout << y;
    return 0;
}