/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 5:47 PM
 * Purpose: v1) Read in 1 set of data
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

    //Initial Variables
    cout<<"Enter the number of users: ";
    cin>>nUsers;
    cin.ignore();
    cout<<"Enter email address: ";
    cin>>email;
    cout<<"Enter username: ";
    cin>>username;
    cin.ignore();
    cout<<"Enter password: ";
    cin.getline(password,SIZE-1);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Password: "<<password<<endl;

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

