/*include the header files*/
#include <stdio.h>
#include <stdlib.h>

/*function to allocate memory*/
void func(int **b)
{
    *b  = (int*)malloc(sizeof(int));
    **b = 10;

    /*print the value of b*/
    printf("%d\n", **b);
}

/*main function*/
int main()
{
    int **a = (int**)malloc(sizeof(int*));
    func(a);

    /*print the value of a*/
    printf("%d\n", **a);
}
