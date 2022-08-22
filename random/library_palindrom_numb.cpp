#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int number, remainder;
    cin >> number;
    
    string s1 = to_string(number);  //storing string value in s1
    string s2 = s1;                 //copy contents of s1
    reverse(s2.begin(), s2.end());  //reversing the complete string s2

    if (s1==s2)
    cout << "palindrome";
    else
    cout << "not a palindrome";
    return 0;
}

