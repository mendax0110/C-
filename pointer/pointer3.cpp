/*include the library*/
#include <iostream>

using namespace std;

/*void function*/
void function(int* zahl2)
{
    /*print the value of the pointer*/
    cout << "Adresse von zahl2: " << &zahl2 << endl;
    *zahl2 *= 2;
}

/*main function*/
int main()
{
    int zahl1 = 5;

    /*print the value of the pointer*/
    cout << "Zahl1 von der Funktion: " << zahl1 << endl;
    cout << "Adresse: " << &zahl1 << endl;
    function(&zahl1);
    cout << "Zahl1 von der Funktion: " << zahl1 << endl;
}

