/*include the libraries*/
#include <iostream>
#include <dirent.h>

using namespace std;

/*main function*/
int main()
{
    struct dirent *d;
    DIR *dr;
    dr = opendir(" . ");
    
    /*list files in the current directory*/
    if(dr != NULL)
    {
        /*read the files in the current directory*/
        cout << "List of Files & Folders:-\n";

        for(d = readdir(dr); d != NULL; d = readdir(dr))
        {
            cout << d-> d_name << endl;
        }
        closedir(dr);
    }
    else
    {
        /*error*/
        cout << "\nError Occured!";
        cout << endl;
    }

    return 0;
}