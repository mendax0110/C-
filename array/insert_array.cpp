/*include the library*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int arr[6], i, elem;

    /*insert the arrays*/
    cout << "Enter max 5 Array elements: ";

    for(i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    /*insert the element*/
    cout << "\nEnter the element to be inserted: ";
    cin >> elem;
    arr[i] = elem;

    /*display the array*/
    cout << "\nThe array after insertion is: \n";

    for(i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }

    return 0;

}