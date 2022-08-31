/*include the header file*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int num, rem, temp, rev = 0, noOfDigit = 0, arr[10], i;

    /*input the number*/
    cout << "Enter the Number: ";
    cin >> num;

    temp = num;

    while (temp > 0)
    {
        temp = temp / 10;
        noOfDigit++;
    }

    temp = num;

    while (temp > 0)
    {
        rem = temp%10;
        rev = (rev * 10) + rem;
        temp = temp / 10;
    }
    for (i = 0; i < noOfDigit; i++)
    {
        rem = rev%10;
        arr[i] = rem;
        rev = rev / 10;
    }
    if (noOfDigit == 1)
    {
        /*output the number, or the number is a single digit*/
        cout << "\nIt is a Single-digit Number!";
        cout << "\nTry again with a Number with Two or more Digits!";
    }
    else if (noOfDigit == 2)
    {
        temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;

        /*output the number, or the number is a two digit*/
        cout << "\nFirst and Last Digit Interchanged Successfully!";
        cout << "\n \nNew Number = " << arr[0] << arr[1];
    }
    else
    {
        i = 0;
        temp = arr[i];
        arr[i] = arr[noOfDigit - 1];
        arr[noOfDigit - 1] = temp;
        /*output the number, or the number is a three digit*/
        cout << "\nFirst and Last Digit Interchanged Successfully!";
        cout << "\n \nNew Number = ";

        for (i = 0; i < noOfDigit; i++)
        {
            cout << arr[i];
        }    
    }
    
    cout << endl;
    return 0;
}
