/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 10:44 PM
 * Purpose: v9) User class
 */
//System Libraries
#include "Headers.h"
#include "Admin.h"
#include "User.h"

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Initial Variables
    //Welcome menu
    //Prompt to login/register
    string username,password;
    char login = ' ';
    
    cout << "Welcome" << endl;
    do {
        char input;
        cout << "R) To Register \t L) To Log In" << endl;
        cin >> input;
        login = input;
    } while (login != 'R' && login != 'r' && login != 'L' && login != 'l');

    if (login == 'R' || login == 'r') {
        cout << "REGISTER" << endl;
        cout << "Enter Username : ";
        cin >> username;
        cout << "Enter Password : ";
        cin >> password;
    } else if (login == 'L' || login == 'l') {
        cout << "LOGIN" << endl;
        cout << "Enter Username : ";
        cin >> username;
        cout << "Enter Password : ";
        cin >> password;
    }

    if (false) {
        Admin admin;
    } else {
        User user;
        user.setUsrInfo(username,password);
        user.prompt();
    }
    //If login
    //Check if login as admin or user
    //If Admin
    //Admin admin
    //else if user
    //User user
    //Else if register
    //Add info to UserInfo.dat
    //Registration successful

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

