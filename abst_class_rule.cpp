#include <iostream>

using namespace std;
class STUDIOS{
    public:
    //pure virtual function
    virtual void sound() = 0;

    //normal member function
    void sleeping() {
        cout << "Sleeping";
    }
};
class LINUX: public STUDIOS{
    public:
        void sound() {
            cout << "BEEP" << endl;
        }
};
int main(){
    LINUX obj;
    obj.sound();
    obj.sleeping();
    return 0;
}

