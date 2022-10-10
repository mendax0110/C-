// include the header file
#include <iostream>

using namespace std;

// main function
int main()
{
    int i, n, cube;

    // take input from user
    cout << "Enter the number of terms: ";
    cin >> n;

    // loop to find the cube of the number
    for(i = 1; i <= n; i++)
    {
        cube = i * i * i;
        // print the cube of the number
        cout << "Number is: " << i << " and cube of the " << i << " is: " << cube << endl;
    }
}