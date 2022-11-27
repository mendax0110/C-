// include the header file
#include <iostream>

// use the standard namespace
using namespace std;

// main function
int main()
{
    int n, count = 0;

    // get the number from the user
    cout << "Enter a number: ";
    cin >> n;

    // loop until n becomes 0
    while (n != 0)
    {
        // increase the count by 1
        count++;

        // remove the last digit from n
        n /= 10;
    }

    // print the number of digits
    cout << "Number of digits: " << count;

    return 0;
}