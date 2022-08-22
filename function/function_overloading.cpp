/*include the header file*/
#include <iostream>

using namespace std;

/*class of the addition*/
class Addition {
    public:
        int sum(int num1, int num2) {
            return num1 + num2;
        }
        int sum(int num1, int num2, int num3) {
            return num1 + num2 + num3;
        }
};

/*main function*/
int main(void) {
    Addition obj;
    cout << obj.sum(20, 15) << endl;
    cout << obj.sum(81, 100, 10);
    return 0;
}
