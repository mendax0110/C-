/*include the header file*/
#include <iostream>

using namespace std;

/*class of the shape*/
class shape
{
    protected:
        float l;
    public:
        void getData()
        {
            cin >> l;
        }

        virtual float calculateArea() = 0;
};

/*class of the square*/
class square : public shape
{
    public:
        float calculateArea()
        {
            return l * l;
        }
};

/*class of the circle*/
class circle : public shape
{
    public:
        float calculateArea()
        {
            return 3.14 * l * l;
        }
};

/*main function*/
int main()
{
    square s;
    circle c;

    cout << "Enter the length to calculate the square area: ";
    s.getData();

    cout << "Area of the square is " << s.calculateArea();
    cout << "\nEnter the radius to calculate the circle area: ";
    c.getData();

    cout << "Area of the circle is " << c.calculateArea();

    return 0; 
}