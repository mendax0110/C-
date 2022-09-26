// include the header files
#include <iostream>

using namespace std;

// main function
int main()
{
    int n;

    // read the size of the matrix
    cout << "Enter the size of the square-matrix:\n";
    cin >> n;

    int a[n][n];

    // read the elements of the matrix
    cout << "Enter the matrix row-wise:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int ctr = 1;
    // check if the matrix is symmetric
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                ctr = 0;
                break;
            }
        }

        if(ctr == 0)
        {
            break;
        }
    }

    if(ctr)
    {
        // the matrix is symmetric
        cout << "The matrix is symmetric.\n";
    }
    else
    {
        ctr = 1;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(a[i][j] != -a[j][i])
                {
                    ctr = 0;
                    break;
                }
            }

            if(ctr == 0)
            {
                break;
            }
        }
    }

    if(ctr)
    {
        // the matrix is skew-symmetric
        cout << "The matrix is skew-symmetric.\n";
    }
    else
    {
        // the matrix is neither symmetric nor skew-symmetric
        cout << "The matrix is neither symmetric nor skew-symmetric.\n";
    }
    return 0;
}