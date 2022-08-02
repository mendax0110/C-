/*include the libraries*/
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

/*namespace*/
using std::cout;
using std::endl;
using std::string;
using std::hex;
using std::stringstream;

/*main function*/
int main()
{
    string s1 = "Convert this string into hexadecimal";
    string s2;

    /*convert string to hexadecimal*/
    cout << "string: " << s1 << endl;
    cout << "hex:";

    for(const auto &item : s1)
    {
        /*convert each character to hexadecimal*/
        cout << hex << int(item);
    }

    cout << endl;

    return EXIT_SUCCESS;
}