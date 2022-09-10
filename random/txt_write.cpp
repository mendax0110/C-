/*include the libraries*/
#include <iostream>
#include <fstream>

using namespace std;

/*main function*/
int main()
{
    ofstream myfile("testfile.txt");

    if(myfile.is_open())
    {
        /*write to the file*/
        myfile << "First Input for the File.\n";
        myfile << "Second Input for the File.\n";
        myfile << "Third Input for the File.\n";

        /*close the file*/
        myfile.close();
    }
    else
    {
        /*if the file is not open*/
        cout << "Unable to open the testfile.txt";
    }

    return 0;
}
