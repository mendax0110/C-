/*include the header files*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

/*main function*/
int main()
{
    stack<string> textStack;

    int opNumber;
    int opSelect;

    string str;

    /*use the stack to store the previous element
     *use the string as a dynamic array
     */
    cin >> opNumber;

    for(int i = 0; i < opNumber; i++)
    {
        cin >> opSelect;

        /*check the selector
         *insert the character
         */
        if(opSelect == 1)
        {
            string insertStr;
            cin >> insertStr;
            textStack.push(str);
            str += insertStr;
        }

        /*delete the n character*/
        else if(opSelect == 2)
        {
            int deleteStack;
            cin >> deleteStack;
            textStack.push(str);
            str.erase(str.size() - deleteStack);
        }
        /*print the n character*/
        else if(opSelect == 3)
        {
            int printStack;
            cin >> printStack;
            cout << str[printStack -1] << endl;
        }
        /*reset the previous element*/
        else
        {
            str = textStack.top();
            textStack.pop();
        }
    }
    return 0;
}