// include the libraries
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// find elements having at-least two greater elements
void findElements(int arr[], int n)
{
    // get the user input
    cout << "\nElements which have at-least two greater elements are: ";

    // traverse the array
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        var = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                count++;
            }
            if(var >= 2)
            {
                cout << arr[i] << " ";
            }
        }
    }
}

// main function
int main()
{
    int arr[100], n, i;

    // get the user input
    cout << "Enter the number of elements: ";
    cin >> n;

    // get the user input
    cout << "Enter the elements: ";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // get the user input
    cout << "Elements are: ";
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    greater_elements(arr, n);

    return 0;
}