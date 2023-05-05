/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 5:47 PM
 * Purpose: v2) Read in N set of data
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

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int nUsers;
    string email,username;
    const int SIZE=10;
    char password[SIZE];
    int input=0;

    //Initial Variables
    
    //Map the Inputs to the Outputs
    cout<<"Enter the Number of Users: ";
    cin>>nUsers;
    cin.ignore();
    for(int i=0;i<nUsers;i++) {
        cout<<"User "<<i+1<<" Information"<<endl;
        cout<<"Enter Email Address: ";
        cin>>email;
        cout<<"Enter Username: ";
        cin>>username;
        cin.ignore();
        cout<<"Enter Password: ";
        cin.getline(password,SIZE-1);
        
        //Display the Inputs and Outputs
        cout<<"_______________"<<endl;
        cout<<"User "<<i+1<<" Information"<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;  
        cout<<"_______________"<<endl;
    }



    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

