/*include the header files*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*define the datatypes*/
string decimal2binary();
int binary2decimal();
void user_menu();

/*the main function*/
int main()
{
    bool flag;
    char choice = true;

    do
    {
        user_menu();
        cin >> choice;

        switch(choice)
        {
            case '1':
                cout << decimal2binary();
                break;
            case '2':
                cout << binary2decimal();
                break;
            case '3':
                flag = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(flag);
}

/*convert a binary number to a decimal number*/
int binary2decimal()
{
    string toconvert;

    cout << "Enter a binary number: ";
    cin >> toconvert;

    int decimal = 0;

    for(int i = 0; i < toconvert.length(); i++)
    {
        if(toconvert[i] == '1')
        {
            decimal += pow(2, toconvert.length() - i - 1);
        }
    }

    return decimal;
}

/*convert a decimal number to a binary number*/
string decimal2binary()
{
    int toconvert;

    cout << "Enter a decimal number: ";
    cin >> toconvert;

    string binary, revbinary;

    while(toconvert >= 1)
    {
        if(toconvert % 2 == 0)
        {
            binary = "0" + binary;
        }
        else
        {
            binary = "1" + binary;
        }

        toconvert /= 2;
    }

    for(int i = binary.length(); i >= 0; i--)
    {
        revbinary += binary[i];
    }

    return binary;
}

/*display the user menu*/
void user_menu()
{
    cout << "1. Convert decimal to binary" << endl;
    cout << "2. Convert binary to decimal" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}
