/*include the library*/
#include <iostream>

using namespace std;

/*class*/
class BaseClass
{
    public:
        void disp()
        {
            cout << "Function of Parent Class";
        }
};

/*class*/
class DerivedClass : public BaseClass
{
    public:
        void disp()
        {
            cout << "Function of Child Class";
        }
};

/*main function*/
int main()
{
    DerivedClass obj = DerivedClass();
    obj.disp();
    return 0;
}