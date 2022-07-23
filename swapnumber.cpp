/*include the library*/
#include <iostream>

using namespace std;

/*declare the function*/
void cyclicSwap(int *a, int *b, int *c);

/*main function*/
int main()
{
    int a, b, c;

    /*input the value*/
    cout << "Enter value of a, b and c respectively: ";
    cin >> a >> b >> c;

    /*call the function*/
    cout << "Value before swapping: " << endl;
    cout << "a, b and c respectively are: " << a << ", " << b << ", " << c << endl;
    
    cyclicSwap(&a, &b, &c);
    /*call the function*/
    cout << "Value after swapping number in cyclic manner: " << endl;
    cout << "a, b and c respectively are: " << a << ", " << b << ", " << c << endl;

    return 0;
}

void cyclicSwap(int *a, int *b, int *c)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}

