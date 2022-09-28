/*include the header file*/
#include <iostream>
#include <conio.h>

using namespace std;

/*student class read*/
class student
{
    public:
    int rno;
    char name[20];
    void getdata()
    {
        /*get the data from the user*/
        cout << "Enter RollNo :-\t";
        cin >> rno;
        cout << "Enter Name :-\t";
        cin >> name;
    }
};

/*student class write*/
class marks : public student
{
    public:
        int m1,m2,m3,tot;
        float per;
        void getmarks()
        {
            /*get the marks from the user*/
            getdata();
            cout << "Enter Marks 1 :-\t";
            cin >> m1;
            cout << "Enter Marks 2 :-\t";
            cin >> m2;
            cout << "Enter Marks 3 :-\t";
            cin >> m3;
        }

        /*function to calculate total and percentage*/
        void display()
        {
            getmarks();
            cout << "Roll Not \t Name \t Marks1 \t Marks2 \t Marks3 \t Total \t Percentage";
            cout << rno<<"\t"<<name<<"\t"<<m1<<"\t"<<m2<<"\t"<<m3<<"\t"<<tot<<"\t"<<per;
        }
};

/*main function*/
int main()
{
    student std;
    clrscr();
    std.getmarks();
    std.display();
    getch();
}
