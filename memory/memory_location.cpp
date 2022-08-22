/*include the library*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int anzahl;

    std::cout << "Array-Gr\224\341e: ";
    std::cin >> anzahl;

    int* zahlen = new int[anzahl];
    
    /*insert the numbers*/
    for(int i = 0; i < anzahl; i++)
    {
        std::cout << "Geben Sie einen Wert ein: ";
        std::cin >> zahlen[i];
    }
    
    /*print the numbers*/
    std::cout << "Gespeicherte Werte: " << std::endl;
    
    /*print the numbers*/
    for(int i = 0; i < anzahl; i++)
    {
        std::cout << zahlen[i] << " ";
    }

    delete[] zahlen;
}