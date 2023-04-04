/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 7:24 PM
 * Purpose: v6) Structure in a structure
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries
#include "CSurvey.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
struct UserInfo {
    string username;
    string password;
};

//Function Prototypes
void dispMenu();
Users *fillDat(int &);       //Fill structure
void display(Users*);    //Display users
void destroy(Users*);        //Destroy users

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    Users *users;
    
    //Initial Variables
    usersDB=fillDat();
    
    //Map the Inputs to the Outputs
    
   //Display the Inputs and Outputs 
    display(users);

    //Clean Up the Dynamic Stuff
    destroy(users);
    
    //Exit 
    return 0;
}

Users *fillDat() {
    Users *usersDB=new Users;
    
    cout<<"Enter Number of Users: ";
    cin>>usersDB->numUsers;
    
    usersDB->users=new UserInfo[usersDB->numUsers];
    
    for(int i=0;i<usersDB->numUsers;i++) {
        cout<<left;
        cout<<endl<<"User "<<i+1<<" Information"<<endl;
        cout<<"Enter Username: ";
        cin>>usersDB->users[i].username;
        cin.ignore();
        cout<<"Enter Password: ";
        cin>>usersDB->users[i].password;
    }
    cout<<endl;
    
    return usersDB;
}

void display(Users *usersDB) {
    cout<<"User Information"<<endl;
    for(int i=0;i<usersDB->numUsers;i++) {
        cout<<"User "<<i+1<<endl;
        cout<<"Username: "<<usersDB->users[i].username<<endl;
        cout<<"Password: "<<usersDB->users[i].password<<endl;  
        cout<<endl;
    }
    cout<<endl;
}

void destroy(Users *usersDB) {
    delete []usersDB;
}

void dispMenu() {
    cout<<"Press 1: Admin Login"<<endl;
    cout<<"Press 2: User Login"<<endl;
    cout<<"Press 3: Create Admin Account"<<endl;
    cout<<"Press 4: Create User Account"<<endl;
}