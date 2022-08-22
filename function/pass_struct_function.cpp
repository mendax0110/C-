/*include the library*/
#include <iostream>

using namespace std;

/*define the structure*/
struct STUDYOS
{
    char stuName[30];
    int stuRollNo;
    int stuvers;
};

void printSTUDYOSInfo(STUDYOS);

/*main function*/
int main()
{
    STUDYOS s;

    /*input the data*/
    cout << "Enter a OS-version name: ";
    cin.getline(s.stuName, 30);

    /*input the data*/
    cout << "Enter a OS-version roll no: ";
    cin >> s.stuRollNo;
    
    /*input the data*/
    cout << "Enter a STUDYOS version: ";
    cin >> s.stuvers;

    printSTUDYOSInfo(s);

    return 0;
}

/*function to print the STUDYOS info*/
void printSTUDYOSInfo(STUDYOS s)
{
    cout << "STUDYOS Record: "     << endl;
    cout << "OS-version name: "    << s.stuName     << endl;
    cout << "OS-version roll no: " << s.stuRollNo   << endl;
    cout << "STUDYOS version: "    << s.stuvers     << endl;
}