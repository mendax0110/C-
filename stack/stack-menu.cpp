/*include the header file*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

using namespace std;

/*define the structure*/
struct node
{
    int data;
    node *link;
};

/*add to the stack*/
node *push(node *top, int val);
/*remove from the stack*/
node *pop(node *top, int &val);
/*display the stack*/
void show_stack(node *top);

/*main logic*/
int main()
{
    node *top;
    int val;
    int choice;
    char opt = 'Y';
    top = NULL;

    do
    {
        cout << "\n\t\t Main Menu";
        cout << "\n\t1. Addition to the stack";
        cout << "\n\t2. Removal from the stack";
        cout << "\n\t3. Display the stack";
        cout << "\n\t4. Exit the Menu";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                do
                {
                    cout << "Enter the value to be added to the stack: ";
                    cin >> val;
                    top = push(top, val);
                    cout << "\nDo you want to add another value to the stack? (Y/N): ";
                    cin >> opt;
                }
                while(toupper(opt) == 'Y');
                break;

            case 2:
                opt = 'Y';
                do
                {
                    top = pop(top, val);
                    if(val != -1)
                    {
                        cout << "The value removed from the stack is: " << val;
                        cout << "\nDo you want to remove another value from the stack? (Y/N): ";
                        cin >> opt;
                    }
                }
                while(toupper(opt) == 'Y');
                break;

            case 3:
                show_stack(top);
                break;

            case 4:
                exit(0);
        }
    }
    while(choice != 4);
}

/*function for add stack element*/
node *push(node *top, int val)
{
    node *temp;
    temp = new node;
    temp->data = val;
    temp->link = NULL;
    
    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->link = top;
        top = temp;
    }
    return top;
}

/*function for remove stack element*/
node *pop(node *top, int &val)
{
    node *temp;
    if(top == NULL)
    {
        cout << "\nStack is empty";
        val = -1;
    }
    else
    {
        temp = top;
        top = top->link;
        val = temp->data;
        temp->link = NULL;
        delete temp;
    }
    return (top);
}

/*function for display stack*/
void show_stack(node *top)
{
    node *temp;
    temp = top;
    cout << "The values in the stack are: ";

    while(temp != NULL)
    {
        cout << "\n" << temp->data;
        temp = temp->link;
    }
}