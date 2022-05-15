#include <iostream>

using namespace std;

class A
{
    //private by default
    string data = "Data";   //original data defined in the base class
    public:
    virtual void display()  //virtual function defined in the base
    class
    {
        cout << "The data is : " << data << endl;
    }
};

class B: public A
{
    string value = "VFM"; //virtual function redefined in the derived class
    public:
    void display()
    {
        cout << "The data is : " << value << endl;
    }
};

int main()
{
    cout << "Welcome to virtual funcion memory!" << endl << endl;

    A *a;
    B b;
    a = &b;
    a-> display();  //changes reflected in the original data by function call

    return 0;
}
