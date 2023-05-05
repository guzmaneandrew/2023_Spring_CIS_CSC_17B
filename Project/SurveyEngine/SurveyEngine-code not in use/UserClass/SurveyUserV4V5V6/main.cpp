/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 6:48 PM
 * Purpose: v4)Create static structure
 *          v5) Fill and display structure in functions
 *          v6) Destroy structure in function
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
    int numSurveys;
    bool active;
};

//Function Prototypes
void dispMenu();
UserInfo *fillDat(int &);       //Fill structure
void display(UserInfo*,int);    //Display users
void destroy(UserInfo*);        //Destroy users

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    UserInfo *users;
    int numUsers;
    
    //Initial Variables
    users=nullptr;
    numUsers=0;
    
    do {
        cout<<"Enter the Number of Users to Create Accounts For (up to 10): ";
        cin>>numUsers;
        cin.ignore();    
    } while(numUsers>MAX);
    
    //Map the Inputs to the Outputs
    users=fillDat(numUsers);
    
   //Display the Inputs and Outputs 
    display(users,numUsers);

    //Clean Up the Dynamic Stuff
    destroy(users);
    
    //Exit 
    return 0;
}

UserInfo *fillDat(int &numUsers) {
    UserInfo *usrInfo=new UserInfo[numUsers];
    
    for(int i=0;i<numUsers;i++) {
        cout<<left;
        cout<<endl<<"User "<<i+1<<" Information"<<endl;
        cout<<"Enter Username: ";
        cin>>usrInfo[i].username;
        cin.ignore();
        cout<<"Enter Password: ";
        cin>>usrInfo[i].password;
    }
    cout<<endl;
    
    return usrInfo;
}

void display(UserInfo *usrInfo,int numUsers) {
    cout<<"User Information"<<endl;
    for(int i=0;i<numUsers;i++) {
        cout<<"User "<<i+1<<endl;
        cout<<"Username: "<<usrInfo[i].username<<endl;
        cout<<"Password: "<<usrInfo[i].password<<endl;  
        cout<<endl;
    }
    cout<<endl;
}

void destroy(UserInfo *usrInfo) {
    delete []usrInfo;
}

void dispMenu() {
    cout<<"Press 1: Admin Login"<<endl;
    cout<<"Press 2: User Login"<<endl;
    cout<<"Press 3: Create Admin Account"<<endl;
    cout<<"Press 4: Create User Account"<<endl;
}