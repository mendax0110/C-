#include <iostream>
#include <vector>

using namespace std;

//function to find odd integer
int oddInteger(vector <int> a)
{
    int result=0;
    for (unsigned int i = 0; i < a.size(); i++)
    {
        result = result^a[i];   
    }
    return result;
}

//main function to test code
int main()  {
    int n;
    //input total number of elements
    cin >> n;
    vector<int> a(n);

    //read n numbers
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    } 

    //find and print result
    int result = oddInteger(a);
    cout << result << endl;

    return 0;
}
