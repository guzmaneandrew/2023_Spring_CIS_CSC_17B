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

    string username, password;
    char login = ' ';

//    cout << "Welcome" << endl;
//    do {
//        char input;
//        cout << "R) To Register \t L) To Log In" << endl;
//        cin >> input;
//        login = input;
//    } while (login != 'R' && login != 'r' && login != 'L' && login != 'l');
//
//    if (login == 'R' || login == 'r') {
//        cout << "REGISTER" << endl;
//        cout << "Enter Username : ";
//        cin >> username;
//        cout << "Enter Password : ";
//        cin >> password;
//    } else if (login == 'L' || login == 'l') {
//        cout << "LOGIN" << endl;
//        cout << "Enter Username : ";
//        cin >> username;
//        cout << "Enter Password : ";
//        cin >> password;
//    }

    cout << "LOGIN" << endl;
    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;

    if (false) {
        Admin admin(username,password);
    } else {
        User user;
        user.setUsrInfo(username, password);
        user.prompt();
    }

    //Exit 
    return 0;
}

//register for a USER account (not an option for admin)
    //validate registration info - ensure an account doesn't already exist
//login to an admin or user account
//validate admin login
//validate user login