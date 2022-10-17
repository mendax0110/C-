// include the header file
#include <iostream>

using namespace std;

// define the class
class STUDIOS
{
    public:
        // pure virtual function
        virtual void studio() = 0;

        // normal member function
        void studio_name()
        {
            cout << "This is a studio." << endl;
        }
};

// define the derived class
class STUDIOS1 : public STUDIOS
{
    public:
        void studio()
        {
            cout << "This is a studio1." << endl;
        }
};

// main function
int main()
{
    STUDIOS1 obj;
    obj.studio();
    obj.studio_name();

    return 0;
}
