/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 4:50 PM
 * Purpose: v8) Class in separate .h and .cpp files
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

//Function Prototypes
char dispMenu();
void createUsers();

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    CSurvey csurvey;        //Create an instance of the CSurvey class
    
    //Initialize Variables
    
    //Display the Inputs and Outputs
    csurvey.display();
    
    //Clean Up the Dynamic Stuff
    

    //Exit 
    return 0;
}

char dispMenu() {
    char choice;
    
    cout<<"Press 1: Admin Login"<<endl;
    cout<<"Press 2: User Login"<<endl;
    cout<<"Press 3: Create Admin Account"<<endl;
    cout<<"Press 4: Create User Account"<<endl;
    
    cin>>choice;
    return choice;
}

void createUsers() {
    string email,password;
    int nUsers;
            
    cout<<"Enter the Number of Users: ";
    cin>>nUsers;
    cout<<"Number of Users: "<<nUsers<<endl;
    
    for(int i=0;i<nUsers;i++) {
        cout<<endl<<"User "<<i+1<<endl;
        cout<<"Enter Email Address: ";
        cin>>email;
        cout<<"Enter Password: ";
        cin>>password;
        
        //Display the Inputs and Outputs
        cout<<left<<endl;
        cout<<setw(12)<<"Email: "<<email<<endl;
        cout<<setw(12)<<"Password: "<<password<<endl<<endl; 
    }
}

