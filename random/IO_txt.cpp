/*include the header file*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*main function: create a stream object and open the file,
*then read or write to the file
*/
int main()
{
    string line;

    /*create the output stream to write to the file
     *append the new lines to the end of the file
     */
    ofstream myfile1("example.txt", ios::app);

    if(myfile1.is_open())
    {
        myfile1 << "This is the first Input for the 'example.txt' file.\n";
        myfile1 << "This is the second Input for the 'example.txt' file.\n";
        myfile1.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    /*create the input stream to read from the file*/
    ifstream myfile2("example.txt");

    /*the file is open, the creating of ifstream takes place now*/
    if(myfile2.is_open())
    {
        /*read the file line by line*/
        while(getline(myfile2, line))
        {
            cout << line << endl;
        }
        myfile2.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    return 0;
}