/*include the header file*/
#include <iostream>
		  
using namespace std;

/*define the matrix class*/
class matrix
{
    int a[5][5];

    public:
        void getdata(int n);
        void displaydata(int n);
        friend matrix operator+(matrix A, matrix B);
};

/*getdata function*/
void matrix::getdata(int n)
{
    int i, j;

    cout << "\nEnter " << n*n << " elements\n";

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

/*displaydata function*/
void matrix::displaydata(int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        cout << "\n";

        for(j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }

        cout << "\n";
    }
}

/*overload the + operator*/
matrix operator +(matrix a, matrix b)
{
    int i, j, n;

    cout << "Enter the size of the matrix you have entered:";
    cin >> n;
    cout << "\nThe sum of the two matrices is: \n";
    matrix temp;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            temp.a[i][j] = a.a[i][j] + b.a[i][j];
        }
    }

    return (temp);
}

/*main function*/
int main()
{
    matrix A, B, C;

    int n;

    cout << "Enter the size of the matrix:";
    cin >> n;

    A.getdata(n);
    B.getdata(n);

			  
    cout << "\nThe first matrix is:";
			  
	   
    A.displaydata(n);
 

    cout << "\nThe second matrix is:";
    B.displaydata(n);

    C = A + B;
    C.displaydata(n);
}