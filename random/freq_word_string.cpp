/*include the library*/
#include <iostream>
#include <stdio.h>

using namespace std;

/*main function*/
int main()
{
    char str[200], word[20];
    int i = 0, j, temp, countW = 0, chk;

    /*input the string*/
    cout << "Enter the string: ";
    gets(str);
    cout << "Enter the word: ";
    gets(word);

    while(str[i] != '\0')
    {
        temp = i;
        j = 0;

        while(word[j] != '\0')
        {
            if(str[i] == word[j])
                i++;
                j++;
        }

        chk = i -temp;
        if(chk == j)
            countW++;
            i = temp;
            i++;
    }

    /*output the result*/
    cout << "\nOccurance of the word: " << countW;
    cout << endl;

    return 0;
}