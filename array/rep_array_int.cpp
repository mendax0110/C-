/*include the library*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*main function*/
int main()
{
    int array[100], n, i;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "\nEnter the elements of the array: ";

    for(i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Original array: ";

    for(int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    /*selecting an element from the array*/
    for(int i = 0; i < n; i++)
    {
        /*traversing to check the repetition*/
        for(int j = i + 1; j < n; j++)
        {
            if(array[i] == array[j])
            {
                cout << "\nFirst repetition of integer is " << array[i];
            }
            else
            {
                cout << "\nNo repetition of integer";
            }

            return 0;
        }
    }
}