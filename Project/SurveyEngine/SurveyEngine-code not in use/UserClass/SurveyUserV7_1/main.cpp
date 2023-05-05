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
#include "User.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only


//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    User *user=new User;
    
    //Initial Variables
    
    //Map the Inputs to the Outputs
    
   //Display the Inputs and Outputs 

    //Clean Up the Dynamic Stuff
    
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