/*include the library*/
#include <iostream>

using namespace std;

/*define the class*/
class Stack_overflow{};
class Stack_underflow{};

/*define the stack class*/
class Stack
{
    public:
        Stack(int sz) : sz{sz}, top{-1}, elem{new int[sz]} {};
        ~Stack() { delete[] elem; };
        bool empty();
        void push(int * x);
        int* pop();
    
    private:
        int* elem;
        int top;
        int sz;
};

/*define the function*/
bool Stack::empty()
{
    if(top < 0)
        return true;
    else
        return false;
}

/*push the element into the stack*/
void Stack::push(int* x)
{
    if(top+1 >= sz)
        throw Stack_overflow();
    else
    {
        top++;
        elem[top] = *x;
    }
}

/*pop the element*/
int* Stack::pop()
{
    if(empty())
        throw Stack_underflow();
    else
    {
        int* x = new int;
        *x = elem[top];
        top--;
        return x;
    }
}

/*main function*/
int main()
{
    Stack s{2};
    int a = 5;
    int b = 7;
    s.push(&a);
    s.push(&b);
    int* y = s.pop();
    cout << *y << endl;
    y = s.pop();
    cout << *y << endl;

    return 0;
}