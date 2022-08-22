/*include the library*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*main function*/
int main()
{
    int num, n;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the bit number you wish to obtain: ";
    cin >> n;

    cout << "Answer: " << (1 & (num >> (n - 1)));
}
