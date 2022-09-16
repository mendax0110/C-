/*include the header file*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    /*declare variables*/
    float voltage;
    float ampere;

    /*get input from user*/
    cout << "Please enter the voltage: ";
    cin >> voltage;

    cout << "Please enter the ampere: ";
    cin >> ampere;

    /*calculate the resistance*/
    float resistance = voltage / ampere;

    /*print the result*/
    cout << "The resistance is: " << resistance << endl;

    return 0;
}