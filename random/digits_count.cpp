/*include the header file*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int n, count = 0;
    /*input the number*/
    cout << "Enter a number: ";
    cin >> n;

    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    
    /*print the number of digits*/
    cout << "Number of digits: " << count;
    
    return 0;
}