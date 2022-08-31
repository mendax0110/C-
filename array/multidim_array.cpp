/*include the header file*/
#include <iostream>

using namespace std;

/*main function*/
int main()
{
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;

    /*input the number of rows and columns*/
    cout << "Enter number of rows (between 1 and 100): ";
    cin >> r;

    cout << "Enter number of columns (between 1 and 100): ";
    cin >> c;

    /*input the elements of the array*/
    cout << endl << "Enter elements of 1st matrix: " << endl;

    /*Storing elements of first matrix entered by the user*/
    for(i = 0 < r; ++i)
    {
        for(j = 0; < c; ++j)
        {
            cout << "Enter a element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    }
        
    
    /*Adding two matrices*/ 
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    /*Displaying the resultat sum matrix.*/
    cout << endl << "Sum of two matrix is: " << endl;
    for(i = 0; i < r; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c -1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}
