#include <iostream>
using namespace std;

class construct{
    public:
        int num;
        char ch;

        construct(){
            num = 100; ch = 'A';
        }
};
int main(){
    construct obj;

    cout << "num: " << obj.num << endl;
    cout << "ch: " << obj.ch;
    return 0;
}
