/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SurveyEngine.h
 * Author: andrewguzman
 *
 * Created on April 13, 2023, 10:48 PM
 */

#include "User.h"
#include "Admin.h"

#ifndef SURVEYENGINE_H
#define SURVEYENGINE_H

class SurveyEngine {
private:
    bool isAdmin;
    bool loggedIn;
    string username;
    string password;
public:

    SurveyEngine() {
        loggedIn=false;
        isAdmin=false;
        
        do {
            //Main menu, login/registration prompt
            mainMenu();
            if (loggedIn) {
                if (isAdmin) {
                    Admin admin(username, password);
                } else {
                    User user;
                    user.setUsrInfo(username, password);
                    user.prompt();
                }
            }
        } while (!loggedIn);
    }

    void mainMenu() {
        char input = ' ';
        bool validUsr, validAdmn;

        do {
            cout << "R) To Register \t L) To Log In" << endl;
            cin >> input;
        } while (input != 'R' && input != 'r' && input != 'L' && input != 'l');

        if (input == 'R' || input == 'r') {
            cout << "REGISTER" << endl;
            do {
                //Prompt for username
                cout << "Enter New Username (6 to 10 Characters): ";
                cin >> username;
                while (username.length() < 6 || username.length() > 10) {
                    cout << "Username Does Not Meet Character Requirement." << endl;
                    cout << "Enter New Username (6 to 10 Characters): ";
                    cin >> username;
                }
                //Check if username already exists
                if (validtName())
                    cout << "Account Already Exists" << endl;
            } while (username.length() < 6 || username.length() > 10 ||
                    validtName());

            do {
                //Prompt for password
                cout << "Enter New Password (8 to 12 Characters): ";
                cin >> password;
                while (password.length() < 8 || password.length() > 12) {
                    cout << "Password Does Not Meet Character Requirement" << endl;
                    cout << "Enter New Password (8 to 12 Characters): ";
                    cin >> password;
                }
            } while (password.length() < 8 || password.length() > 12);

            regUsr();
            cout << "Account Successfully Created." << endl;
        } else if (input == 'L' || input == 'l') {
            cout << "LOGIN" << endl;
            cout << "Enter Username : ";
            cin >> username;
            cout << "Enter Password : ";
            cin >> password;

            login();
        }
    }
    
    void login() {
        bool validUsr = validtUsr();
        bool validAdmn = validtAdmn();
        
        if (validUsr) {
            cout << validUsr << endl;
            loggedIn = true;
            isAdmin = false;
        } else if (validAdmn) {
            cout << validAdmn << endl;
            loggedIn = true;
            isAdmin = true;
        } else if (!validUsr || !validAdmn) {
            loggedIn = false;
            isAdmin = false;
            cout << "You've Entered an Invalid Username or Password" << endl;
        } 
    }

    void regUsr() {
        //Add user to user DB
        UserInfo newUser;
        strcpy(newUser.username, username.c_str());
        strcpy(newUser.password, password.c_str());

        fstream userDB("UserInfo.dat", ios::in | ios::app | ios::binary);
        userDB.seekp(ios::app);
        userDB.write(reinterpret_cast<char *> (&newUser), sizeof (newUser));
        userDB.close();
    }

    bool validtUsr() {
        fstream userDB("UserInfo.dat", ios::in | ios::app | ios::binary);
        UserInfo temp;

        userDB.seekg(ios::beg);
        while (userDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
            if (strcmp(temp.username, username.c_str()) == 0 &&
                    strcmp(temp.password, password.c_str()) == 0) {
                return true;
            }
        }
        userDB.close();
        return false;
    }

    bool validtName() {
        fstream userDB("UserInfo.dat", ios::in | ios::app | ios::binary);
        UserInfo temp;

        userDB.seekg(ios::beg);
        while (userDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
            if (strcmp(temp.username, username.c_str()) == 0) {
                return true;
            }
        }
        userDB.close();
        return false;
    }

    bool validtAdmn() {
        fstream adminDB("AdminInfo.dat", ios::in | ios::app | ios::binary);
        AdminInfo temp;

        adminDB.seekg(ios::beg);
        while (adminDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
            if (strcmp(temp.username, username.c_str()) == 0 &&
                    strcmp(temp.password, password.c_str()) == 0) {
                return true;
            }
        }
        adminDB.close();
        return false;
    }

};

//    if (false) {
//        Admin admin(username,password);
//    } else {
//        User user;
//        user.setUsrInfo(username, password);
//        user.prompt();
//    }

//register for a USER account (not an option for admin)
//validate registration info - ensure an account doesn't already exist
//login to an admin or user account
//validate admin login
//validate user login

#endif /* SURVEYENGINE_H */

