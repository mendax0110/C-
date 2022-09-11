/*include the header files*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*login class*/
int login()
{
    string username, password, un, pw;

    /*ask for username*/
    cout << "Enter your username: ";
    cin >> username;
    
    /*ask for password*/
    cout << "Enter your password: ";
    cin >> password;

    /*open the file*/
    ifstream read("DATABASE.txt");

    /*read the file*/
    getline(read, un);
    getline(read, pw);

    /*check if the username and password are correct*/
    if(username == un && password == pw)
    {
        cout << "Login successful" << endl;
        return 1;
    }
    else
    {
        cout << "Login failed" << endl;
        return 0;
    }
}

/*main function*/
int main()
{
    int choice;

    /*ask for the choice of the user*/
    cout << "1:Register a new account\n2:Login to your account\ntypr 1 or 2: ";
    cin >> choice;

    if(choice == 1)
    {
        string username, password;

        /*ask for a new username*/
        cout << "Select a new username: ";
        cin >> username;

        /*ask for a new password*/
        cout << "Select a new password: ";
        cin >> password;
        
        /*open the file*/
        ofstream file;
        file.open("DATABASE.txt");

        /*write the username and password to the file*/
        file << username << endl << password;

        /*close the file*/
        file.close();

        /*login*/
        cout << "Registration successful" << endl;

        main();
    }
    else if(choice == 2)
    {
        int status = login();

        /*check if the login was successful*/
        if(!status)
        {
            cout << "Do you want to try again?\n1:Yes\n2:No\nType 1 or 2: ";
            cin >> choice;
            system("PAUSE");
        }
        else
        {
            cout << "Welcome to the system" << endl;
            system("PAUSE");
            return 1;
        }
    }
}