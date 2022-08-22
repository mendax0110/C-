/*include the libraries*/
#include <iostream>
#include <vector>
#include <stdlib.h>

/*define the class*/
class RandomDeref
{
    public:
        int a;
        double b;
        std::string c;
        RandomDeref() : a(5), b(42.0), c("test") {}
};

/*main function*/
int main(int argc, char* argv[])
{
    int n;
    
    if(argc > 1)
    {
        n = atoi(argv[1]);
    }
    else
    {
        n = 10;
    }

    /*create the vector, soil up the memory space*/
    std::vector<RandomDeref*> foo;
    for(unsigned i = 0; i < 10 * n; i++)
    {
        foo.push_back(new RandomDeref());
    }

    for(unsigned i = 0; i < 10 * n; i++)
    {
        delete foo[i];
    }

    std::vector<double> b(1);
    std::vector<double>::iterator it;

    for(it = b.begin(); it < b.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Done" << std::endl;

    int fooInt = 42;

    double *fooDouble = reinterpret_cast<double*>(&fooInt);
    std::cout << "fooInt = " << fooInt << std::endl << "fooDouble = " << *fooDouble << std::endl;
}