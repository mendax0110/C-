/*include the header file*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void BubbleSort(int [], const int);
int BinarySearch(const int ArrayName[], const int ArraySize, const int SearchKey, const int FromIndex, const int ToIndex);
void ShowArray(const int [], const int, const int);

/*main function*/
int main()
{
    const int ArraySize = 90;
    int Array1[ArraySize];
    int SearchFor, Result;

    /*enter the integer to search for*/
    cout << "Enter an integer between 10 and 99 to search for: ";
    cin >> SearchFor;
    cout << "\n";

    srand(time(NULL));
    
    for(int i = 0; i < ArraySize; i++)
    {
        Array1[i] = rand() % 90 + 10;
    }

    BubbleSort(Array1, ArraySize);
    Result = BinarySearch(Array1, ArraySize, SearchFor, 0, ArraySize - 1);
    ShowArray(Array1, ArraySize, Result);

    return 0;
}

/*bubble sort function*/
void BubbleSort(int Array1[], const int ArraySize)
{
    for(int i = 0; i < ArraySize-1; i++)
    {
        for(int j = 0; j < ArraySize-1; j++)
        {
            if(Array1[j] < Array1[j+1])
            {
                int hold = Array1[j];
                Array1[j] = Array1[j+1];
                Array1[j+1] = hold;
            }
        }
    }
}

/*binary search function*/
int BinarySearch(const int ArrayName[], const int ArraySize, const int SearchKey, const int FromIndex, const int ToIndex)
{
    int SearchResult, MiIndex;

    if(ToIndex - FromIndex == 1)
    {
        if(SearchKey == ArrayName[FromIndex])
        {
            SearchResult = FromIndex;
        }
        else if(SearchKey == ArrayName[ToIndex])
        {
            SearchResult = ToIndex;
        }
        else
        {
            SearchResult = -1;
        }
    }
    else
    {
        MiIndex = (FromIndex + ToIndex) / 2;

        if(SearchKey == ArrayName[MiIndex])
        {
            SearchResult = MiIndex;
        }
        else if(SearchKey > ArrayName[MiIndex])
        {
            SearchResult = BinarySearch(ArrayName, ArraySize, SearchKey, FromIndex, MiIndex);
        }
        else if(SearchKey < ArrayName[MiIndex])
        {
            SearchResult = BinarySearch(ArrayName, ArraySize, SearchKey, MiIndex, ToIndex);
        }
    }

    return SearchResult;
}

/*show array function*/
void ShowArray(const int ArrayName[], const int ArraySize, const int Index)
{
    for(int i = 0; i < ArraySize; i++)
    {
        cout << ArrayName[i];

        if(i == Index)
        {
            cout << "* ";
        }
        else
        {
            cout << " ";
        }

        if((i+1 % 10) == 0)
        {
            cout << endl;
        }
    }

    cout << "\n\n";

    if(Index < 0)
    {
        cout << "The integer was not found in the array.\n";
    }
    else
    {
        cout << "The integer was found at index " << Index << ".\n";
    }
    
    cout << "\n";
}

