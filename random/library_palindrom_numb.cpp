// include the header files
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// function to check if the number is palindrome or not
int main()
{
    int number, remainder;
    
    // take the input from the user
    cout << "Enter a number: ";
    cin >> number;

    // storing string value in s1
    string s1 = to_string(number);
    // copy contents of s1 to s2
    string s2 = s1;
    // reverse the string s2
    reverse(s2.begin(), s2.end());

    // check if s1 and s2 are equal
    if(s1 == s2)
        // if equal, then the number is palindrome
        cout << "The number is a palindrome.";
    else
        // if not equal, then the number is not palindrome
        cout << "The number is not a palindrome.";
    
    // return 0 to indicate normal termination
    return 0;
}