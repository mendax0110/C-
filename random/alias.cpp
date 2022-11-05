/*include the header file*/
#include <iostream>

/*using standard namespace*/
using namespace std;

int &function(void)
{
    static int a = 0;

    /*return the reference of a*/
    cout << "a == " << a << endl;

    return a;
}

/*main function*/
int main()
{
    /*the alias for y is now x and y*/
    int x = 3, &y = x, z;

    /*print the value of x*/
    cout << "x = " << x << endl << "y = " << y << endl;
    
    y = 7;
    /*print the value of x and y*/
    cout << "x = " << x << endl << "y = " << y << endl;

    /*now perform the aliasing*/
    z = y;

    cout << "Z = " << z;

    cout << "\nA function returning a reference: \n\n";

    /*call the function*/
    function();
    function()  = 5;
    function() += 5;
    function();

    /*give input(enter) to exit the program*/
    cout << "\n\nNow press ENTER to exit the program.\n";
    cin.get();

    return 0;
}