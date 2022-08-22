/*include the library*/
#include <iostream>

using namespace std;

/*declare the function*/
void function(int& num2)
{
    cout << "address of num2: " << &num2 << endl;
    num2 *= 2;
}

/*declare the main function*/
int main()
{
    int num1 = 5;
    /*call the function*/
    cout << "num1 of function: " << num1 << endl;
    cout << "address of num1: "  << &num1 << endl;
    function(num1);
    cout << "num1 after function: " << num1 << endl;
}