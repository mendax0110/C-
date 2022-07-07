/*include the library*/
#include <iostream>

using namespace std;

/*main int function*/
int main()
{
    int octal[100], i = 1, j;
    long dno, temp;

    /*input the decimal number*/
    cout << "Enter the decimal number: ";
    cin >> dno;
    temp = dno;

    /*convert the decimal number to octal*/
    while(temp != 0)
    {
        octal[i++] = temp % 8;
        temp /= 8;
    }

    /*output the octal number*/
    cout << "Equivalent octal number is: ";

    for(j = i - 1; j > 0; j--)
    {
        cout << octal[j];
    }

    return 0;   
}