/*include the library*/
#include <iostream>

/*define the main function*/
#define uint unsigned int

using namespace std;

uint makeReverseBCD(uint num);

/*main function */
int main()
{
    uint n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "BCD is: " << makeReverseBCD(n) << endl;
}

/*function to make the reverse BCD*/
uint reverseBinary(uint num)
{
    uint result = 0;

    for(uint digits = 4; digits > 0; num /= 2, --digits)
    {
        result = result * 10 + num % 2;
    }

    return result;
}

/*using the normal operator and uint
 *using bitwise operators to make the reverse BCD
 */
uint makeReverseBCD(uint num)
{
    uint BCD = 0;

    for(; num > 0; num /= 10)
    {
        BCD = BCD * 10000 + reverseBinary(num % 10 + 3);
    }

    return BCD;
}