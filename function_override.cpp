#include <iostream>
using namespace std;

class BaseClass{
    public:
        void disp(){
            cout << "Funtion of Parent Class";
        }
};
class DerivedClass : public BaseClass{
    public:
        void disp(){
            cout << "Function of Child Class";
        }
};
int main(){
    DerivedClass obj = DerivedClass();
    obj.disp();
    return 0;
}
