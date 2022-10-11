// include the header file
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// main function
int main()
{
    int num, n;

    // take input from user
    cout << "Enter the number: ";
    cin >> num;

    // take input from user
    cout << "Enter the bit position: ";
    cin >> n;

    // print the result
    cout << "The " << n << "th bit is " << ((num >> (n - 1)) & 1) << endl;

    return 0;
}