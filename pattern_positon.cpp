#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number of rows to be printed\n"; 
    cin >> n;

    for (int i = 1; i < n; ++i) 	//for each row
    {
        for (int j = 0; j < n - 1; ++j) //for printing spaces
            cout << " ";
        for (int j = 0; j < 2 * i - 1; ++j) //for printing star
            cout << " * ";
            cout << "\n";   //going to new line after completing one row
    }
    return 0;
}
