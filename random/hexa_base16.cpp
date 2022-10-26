// include the libary
#include <iostream>

using namespace std;

string base16(int n);

// main function
int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Base 16 is: " << base16(a) << endl;
}

// function to convert to base 16
char digit16(int digit)
{
    if(digit >= 10)
    {
        return 'A' + digit - 10;
    }
    else
    {
        return '0' + digit;
    }
}

// print the base 16
string base16(int n)
{
    string result = "";
    int digit;
    while(n > 0)
    {
        digit = n % 16;
        result = digit16(digit) + result;
        n /= 16;
    }
    return result;
}