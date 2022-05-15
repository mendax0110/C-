#include <iostream.h>
#include <conio.h>

class student
{
    public:
    int rno;
    char name[20];
    void getdata()
    {
        cout<<"Enter RollNo :-\t";
        cin>>rno;
        cout<<"Enter Name :-\t";
        cin>>name;
    }

};
class marks : public student
{
public:
        int m1,m2,m3,tot;
        float per;
        void getmarks()
        {
            getdata();
            cout<<"Enter Marks 1 :-\t";
            cin>>m1;
            cout<<"Enter Marks 2 :-\t";
            cin>>m2;
            cout<<"Enter Marks 3 :-\t";
            cin>>m3;
        }
        void display()
        {
            getmarks();
            cout<<"Roll Not \t Name \t Marks1 \t Marks2 \t Marks3 \t Total \t Percentage";

            cout<<rno<<"\t"<<name<<"\t"<<m1<<"\t"<<m2<<"\t"<<m3<<"\t"<<tot<<"\t"<<per;
        }
};
void main()
{
    student std;
    clrscr();
    std.getmarks();
    std.display();
    getch();
}
