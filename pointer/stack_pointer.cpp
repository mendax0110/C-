/*include the header files*/
#include <iostream>
#include <stdexcept>

template<typename T>

/*Stack class*/
class Stack
{
    /*public members*/
    public:
        void push(T elem)
        {
            auto n = new Node;

            /*check if the memory is allocated*/
            n->elem = elem;
            n->prev = last;
            last    = n;
            _size++;
        }

        T& peek()
        {
            if(empty())
            {
                /*print error message*/
                throw std::underflow_error("stack is empty, nothing to peek");
            }

            return last->elem;
        }

        T pop()
        {
            if(empty())
            {
                /*print error message*/
                throw std::underflow_error("stack is empty, nothing to pop");
            }

            /*get the element*/
            auto n = this->last;
            this->last = n->prev;
            auto el = n->elem;

            _size--;
            delete n;

            return el;
        }

        /*check if stack is empty*/
        const int size() const{return _size;}
        const bool empty() const{return _size == 0;}

    /*private members*/
    private:
        struct Node
        {
            T elem;
            Node* prev;
        };

        Node* last = nullptr;
        int _size  = 0;
};

/*main function*/
int main()
{
    Stack<int> stack;
    
    /*print the stack size*/
    std::cout << "stack is currently empty: " << stack.empty() << std::endl;

    /*push elements into the stack*/
    stack.push(1);
    stack.push(2);

    /*print the stack size*/
    std::cout << "Stack size is currently: " << stack.size() << std::endl;
    std::cout << "Pop: " << stack.pop() << ", peek: " << stack.peek() << ", pop: " << stack.pop() << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;

    return 0;
}