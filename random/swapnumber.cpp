// include the header file
#include <iostream>

// use the standard namespace
using namespace std;

void cyclic(int *a, int *b, int *c);

// main function
int main()
{   
    // declare variables
    int a, b, c;

    // get the input from the user
    cout << "Enter the value of a, b and c respectively: ";
    cin >> a >> b >> c;

    // display the values before swapping
    cout << "The value of a, b and c before swapping are: " << endl;
    cout << "a, b and c respectively: " << a << ", " << b << ", " << c << endl;

    // call the function
    cyclic(&a, &b, &c);

    // display the result after swapping
    cout << "The value after swapping number in cyclic order are: " << endl;
    cout << "a, b and c respectively: " << a << ", " << b << ", " << c << endl;

    return 0;
}

// function definition
void cyclic(int *a, int *b, int *c)
{
    int temp;

    // swap the values
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

    