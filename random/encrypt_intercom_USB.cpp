// include the header files
#include <iostream>
#include <fstream>
#include <stdio.h>

// use the standard namespace
using namespace std;

// main function
int main()
{
    char fileName[30], ch;
    fstream fps, fpt;
    
    // get the file name
    cout << "Enter the name of file to be encrypted: ";
    gets(fileName);
    fps.open(fileName, fstream::in);

    // open the file in read mode
    if(!fps)
    {
        cout << "\nError Occured, Opening the Source File (to Read)!";
        return 0;
    }
    fpt.open("temp.txt", fstream::out);
    if(!fpt)
    {
        cout << "\nError Occured, Opening/Creating the tmp File!";
        return 0;
    }
    while(fps >> noskipws >> ch)
    {
        ch = ch + 100;
        fpt << ch;
    }
    fps.close();
    fpt.close();
    fps.open(fileName, fstream::out);
    if(!fps)
    {
        cout << "\nError Occured, Opening the Source File (to Write)!";
        return 0;
    }
    fpt.open("temp.txt", fstream::in);
    if(!fpt)
    {
        cout << "\nError Occured, Opening the tmp File!";
        return 0;
    }
    while(fpt >> noskipws >> ch)
    {
        fps << ch;
    }
    fps.close();
    fpt.close();

    // print the message
    cout << "\nFile Encrypted Successfully!";
    cout << endl;

    return 0;
}