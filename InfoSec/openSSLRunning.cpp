#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string command = "ps -ef | grep openssl | grep -v grep | wc -l";

    int result = system(command.c_str());

    if(result == 0)
    {
        cout << "OpenSSL is not running" << endl;
    }
    else
    {
        cout << "OpenSSL is running" << endl;
    }

    command = "ps -eLf | awk '{printf \"%s %s %s %s %s %s %s\n\", $1, $2, $3, $4, $5, $6, $7}'";
    result = system(command.c_str());

    // check if thread is running
   if(result == 0)
    {
        cout << "OpenSSL thread is not running" << endl;
    }
    else
    {
        cout << "OpenSSL thread is running" << endl;
    }

    return 0;

}
