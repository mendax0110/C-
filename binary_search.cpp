/*include the library*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int i, arr[10], num, first, last, middle;

    /*input the array*/
    cout << "Enter 10 Elements (in ascending order): ";

    for(i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    /*input the number to be searched*/
    cout << "\nEnter the number to be searched: ";
    cin >> num;

    /*find the first element*/
    first = 0;
    /*find the last element*/
    last = 9;
    /*find the middle element*/
    middle = (first + last) / 2;

    while(first <= last)
    {
        if(arr[middle] < num)
    
            first = middle + 1;

        else if(arr[middle] == num)
        {
            /*print the position of the number*/
            cout << "\nThe number, " << num << ", is found at index " << middle + 1;
            break;
        }
        else

            last = middle - 1;
            middle = (first + last) / 2;
    }

    if(first > last)
    
        /*if the number is not found*/
        cout << "\nThe number, " << num << ", is not found in the array";
        cout << endl;

    return 0;
}