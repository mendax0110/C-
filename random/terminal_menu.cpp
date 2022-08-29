/*include the header file*/
#include <iostream>
#include <cstdlib>

using namespace std;

void menu();
void mainMenu();
void optionsMenu();
void options();
int MyChoice01 = 0;
int MyChoice02 = 3;

/*menu function*/
void menu()
{
    do
    {
        MyChoice02 = 0;
        mainMenu();

        switch(MyChoice01)
        {
            case 1:
                cout << "Starting the options menu....\n";
                break;

            case 2:
                options();
                break;

            case 3:
                break;
        }

    }while(MyChoice01 != 3); 

}

/*options to choose*/
void options(void)
{
    do
    {
        optionsMenu();
        
        switch(MyChoice02)
        {
            case 1:
                cout << "This category displays the value: OUTPUT1\n";
                break;

            case 2:
                cout << "This category displays the value: OUTPUT2\n";
                break;

            case 3:
                break;

            default:
                break;
        }       
					 
    } while(MyChoice02 != 3);
    
}

/*main menu*/
void mainMenu(void)
{
    cout << "Main Menu\n";
    cout << "1. Start the options menu\n";
    cout << "2. Options\n";
    cout << "3. Exit the program\n";
    cout << "Please enter your choice: ";
						   
    cin >> MyChoice01;
}

/*options menu*/
void optionsMenu(void)
{
    cout << "Options Menu\n";
    cout << "1. Category 1\n";
    cout << "2. Category 2\n";
    cout << "3. Exit the menu\n";
    cout << "Please enter your choice: ";
						   
    cin >> MyChoice02;
}

/*main function*/
int main(int argc, char** argv)
{
    menu();
    return 0;
}
