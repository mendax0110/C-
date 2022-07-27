/*include the library*/
#include <iostream>

using namespace std;

class Add
{
    public:
    /*parameterized constructor*/
    Add(int num1, int num2)
    {
        cout << (num1 + num2) << endl;
    }
};

/*main function*/
int main(void)
{
    /*implicit call to the constructor*/
    Add obj1(10, 20);
    /*is known as explicit call to the constructor*/
    Add obj2(50, 60);

    return 0;
}
