/*include the libraries*/
#include <iostream>
#include <vector>

using namespace std;

/*function to find odd number*/
int oddInteger(vector <int> a)
{
    int result = 0;

    for(unsigned int i = 0; i < a.size(); i++)
    {
        result = result ^ a[i];
    }
    return result;
}

/*main function for the code to run*/
int main()
{
    int n;

    /*input the number of elements in the vector*/
    cin >> n;
    vector <int> a(n);

    /*read n elements from the user*/
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*find and print the odd number*/
    int result = oddInteger(a);
    cout << result << endl;

    return 0;
}
