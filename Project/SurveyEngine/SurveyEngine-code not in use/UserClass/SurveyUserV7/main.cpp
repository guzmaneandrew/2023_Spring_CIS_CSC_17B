/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 7:35 PM
 * Purpose: v7) Class in main. Structures in .h files
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries
#include "CSurvey.h"
#include "Users.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
class CUsers {
private:
    Users *usersDB;   //Pointer to dynamically allocated Users structure
public:
    CUsers();       //Constructor
    ~CUsers();      //Destructor
    void display(); //Display
};

//Function Prototypes
void dispMenu();
Users *createUsers();    //Fill structure
void display(Users *);    //Display users
void destroy(Users *);          //De-allocate memory

CUsers::CUsers() {
    usersDB=new Users;
    
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
}

void CUsers::display() {
    cout<<"User Information"<<endl;
    for(int i=0;i<usersDB->numUsers;i++) {
        cout<<"User "<<i+1<<endl;
        cout<<"Username: "<<usersDB->users[i].username<<endl;
        cout<<"Password: "<<usersDB->users[i].password<<endl;  
        cout<<endl;
    }
    cout<<endl;
}

CUsers::~CUsers() {
    delete []usersDB;
}

void dispMenu() {
    cout<<"Press 1: Admin Login"<<endl;
    cout<<"Press 2: User Login"<<endl;
    cout<<"Press 3: Create Admin Account"<<endl;
    cout<<"Press 4: Create User Account"<<endl;
}

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    CUsers cusers;      //Create an instance of the CUsers class
    
    //Initial Variables

    //Map the Inputs to the Outputs
    
   //Display the Inputs and Outputs 
    cusers.display();

    //Clean Up the Dynamic Stuff
    
    //Exit 
    return 0;
}