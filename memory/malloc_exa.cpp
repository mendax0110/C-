// include the header files
#include <stdio.h>
#include <stdlib.h>

// function to allocate memory
void func(int **b)
{
    // allocate memory dynamically
    *b  = (int *)malloc(sizeof(int));
    **b = 10;

    // print the value of b
    printf("Value of b is %d\n", **b);
}

// main function
int main()
{
    // declare a pointer
    int **a;

    // allocate memory dynamically
    a = (int **)malloc(sizeof(int *));

    // call the function
    func(a);

    // print the value of a
    printf("Value of a is %d\n", **a);

    // free the memory
    free(*a);

    return 0;
}