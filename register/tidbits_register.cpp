#include <iostream>

using namespace std;

int main()
{
    int i = 123;
    auto int j = 456;
    register int k = 789;

    cout<<"Address of i = " << &j << ", Value = " << j << endl;
    cout<<"Address of j = " << &j << ", Value = " << j << endl;
    cout<<"Address of k = " << &k << ", Value = " << k << endl;

    return 0;
}
