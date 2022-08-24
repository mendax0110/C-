/*include the header file*/
#include <iostream>
#include <iomanip>

using namespace std;

int binarySearch(int[], int, int, int, int);
void printHeader(int);
void printRow(int[], int, int, int, int);

/*main function*/
int main()
{
    const int arraySize = 15;
    int a[arraySize], key, result;

    for(int i = 0; i < arraySize; i++)
    {
        a[i] = 2 * i;
    }

    cout << "Enter a number 0-28: ";
    cin >> key;

    printHeader(arraySize);
    result = binarySearch(a, key, 0, arraySize - 1, arraySize);

    if(result != -1)
    {
        cout << "The number " << key << " is in position " << result << endl;
    }
    else
    {
        cout << "The number " << key << " is not in the array" << endl;
    }
    
    return 0;
}

/*binary search function*/
int binarySearch(int b[], int searchKey, int low, int high, int size)
{
    int middle;

    while(low <= high)
    {
        middle = (low + high) / 2;

        printRow(b, low, middle, high, size);

        if(searchKey == b[middle])
        {
            return middle;
        }
        else if(searchKey < b[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    return -1;
}

/*print the header*/
void printHeader(int size)
{
    cout << "\nSubscript:\n";

    for(int i = 0; i < size; i++)
    {
        cout << setw(3) << i << " ";
        cout << "\n";
    }

    for(int i = 1; i <= 4 * size; i++)
    {
        cout << "-";
        cout << endl;
    }
}

/*print the row*/
void printRow(int b[], int low, int mid, int high, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(i < low || i > high)
        {
            cout << "   ";
        }
        else if(i == mid)
        {
            cout << setw(3) << b[i] << "*";
        }
        else
        {
            cout << setw(3) << b[i] << " ";
        }

        cout << endl;
    }
}