/*include the header file*/
#include <stdio.h>
#include <math.h>
#include <conio.h>

using namespace std;

/*main function*/
int main()
{
    float root1, root2;	   
    float a, b, c;
    float det;
    /*input the value of a, b, c*/
    printf("Enter the coefficients of the quadratic equation: ");
    /*scanf the value of a, b, c*/
    scanf("%f %f %f", &a, &b, &c);

    /*calculate the determinant*/
    if(a * b * c == 0)
    {
        printf("Can't solve the equation");
    }
    else
    {
        det = b * b - 4 * a * c;

        if(det == 0)
        {
            root1 = root2 - b / (2 * a);
            printf("\nThe roots are %f and %f\n", root1, root2);
        }
        else if(det > 0)
        {
            root1 = (-b + sqrt(det)) / (2 * a);
            root2 = (-b - sqrt(det)) / (2 * a);
            printf("\nThe roots are %f and %f\n", root1, root2);
        }
        else
        {
            float real, img;
            real = -b / (2 * a);
            img = sqrt(abs(det)) / (2 * a);

            printf("\nThe roots are %f + %fi and %f - %fi\n", real, img, real, img);
        }
    }
    _getch();
}

