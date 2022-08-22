/*include the library*/
#include <iostream>

using namespace std;

/*declare the function*/
void function(int & zahl2)
{
    /*output the result*/
    cout << "Adresse zahl2: " << &zahl2 << endl;
    zahl2 *= 2;
}

/*declare the main function*/
int main()
{
    int zahl1 = 5;
    /*output the result before the function call*/
    cout << "Zahl1 vor der Funktion: " << zahl1 << endl;
    cout << "Adresse zahl1: " << &zahl1 << endl;
    function(zahl1);
    /*output the result after the function call*/
    cout << "Zahl1 nach der Funktion: " << zahl1 << endl;
}
