/*include the header files*/
#include <iostream>
#include <new>

using namespace std;

/*main function for the dynamic memory allocation*/
int main()
{
    int i, n;
    int *p;

    /*get the number of elements*/
    cout << "Enter number of elements: ";
    cin >> i;

    p = new(nothrow) int[i];

    if(p == nullptr)
    {   
        /*if the memory allocation fails*/
        cout << "Error: the dnyamic memory allocation failed";
    }
    else
    {
        for(n = 0; n < i; n++)
        {   
            /*get the elements*/
            cout << "Enter the number: ";
            cin >> p[n];
        }

        /*print the elements*/
        cout << "The numbers you have entered are: ";

        for(n = 0; n < 1; n++)
        {
            cout << p[n] << ", ";
        }

        delete[] p;
    }

    return 0;
}