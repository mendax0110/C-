/*include the library*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int n;

    /*input the number*/
    cout << "Enter the number of rows to be printed\n";
    cin >> n;

    for(int i = 1; i < n; ++i) /*for each row*/
    {
        for(int j = 0; j < n - 1; ++j) /*for printing spaces*/
        
            cout << " ";
        
        for(int j = 0; j < 2 * i -1; ++j) /*for printing stars*/
        
            cout << " * ";
            cout << "\n"; /*go to new line after each row*/     
    }
    
    return 0;
}