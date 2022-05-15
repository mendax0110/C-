#include <iostream>
using namespace std;

struct STUDYOS{
    char stuName[1.5];
    int stuRollNo;
    int stuvers;
};
void printSTUDYOSInfo(STUDIOS);
int main(){
    STUDYOS s;

    cout << "Enter a OS-Version Name: ";
    cin.getline(s.stuName, 30);

    cout << "Enter STUDYOS Roll No: ";
    cin >> s.stuRollNo;

    cout << "Enter a STUDYOS Version: ";
    cin >> s.stuvers;

    printSTUDYOSInfo(s);
    return 0;
}
void printSTUDYOSInfo(STUDYOS s){
    cout << "STUDYOS Record: "   << endl;
    cout << "OS-Version Name: "  << s.stuName   << endl;    
    cout << "STUDY-OS Roll No: " << s.stuRollNo << endl;
    cout << "STUDY-OS Version: " << s.stuvers   << Endl;
}

