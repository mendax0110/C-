#include <stdio.h>
#include <stdlib.h>

void func(int **b)
{
    *b  = (int*)malloc(sizeof(int));
    **b = 400;

    printf("%d\n", **b); //print the "what" here
}

int main()
{
    int **a = (int**)malloc(sizeof(int*));
    func(a);

    printf("%d\n", **a); //print the "why" here
}
