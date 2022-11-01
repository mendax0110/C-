// include the header file
#include <iostream>
#include <fstream>
#include <string>

// using standard namespace
using namespace std;

/* main function: create a stream object and open the fiel
 * read the file and print the content
 * close the file
 */

int main()
{
    string line;

    /* create the output stream to write to the file
     * append the new lines to the end of the file
     */

    ofstream myfile1("example.txt", ios::app);

    // check if the file is open
    if(myfile1.is_open())
    {
        // write to the file
        myfile1 << "This is the first Input for the 'example.txt' file.\n";
        myfile1 << "This is the second Input for the 'example.txt' file.\n";
        myfile1.close();
    }
    else
    {
        // if the file is not open
        cout << "Unable to open the file.\n";
    }

    /* create the input stream to read from the file
     * read the file line by line
     */
     ifstream myfile2("example.txt");

     // if the file is open, the creating of ifstream object is successful
    if(myfile2.is_open())
    {
        // read the file line by line
        while(getline(myfile2, line))
        {
            // print the content
            cout << line << endl;
        }
        myfile2.close();
    }
    else
    {
        // if the file is not open
        cout << "Unable to open the file.\n";
    }

    // return 0
    return 0;
}