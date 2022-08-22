/*include the librarys*/
#include <iostream>

using namespace std;

void funktion(int* zahl2)
{
	cout << "Adresse zahl2: " << &zahl2 << endl;
	*zahl2 *= 2;
}

int main()
{
	int zahl1 = 5;
	cout << "Zahl vor der Funktion: " << zahl1 << endl;
	cout << "Adresse: " << &zahl1 << endl;
	funktion (&zahl1);
	cout << "Zahl1 nach der Funktion: " << zahl1 << endl;
}
