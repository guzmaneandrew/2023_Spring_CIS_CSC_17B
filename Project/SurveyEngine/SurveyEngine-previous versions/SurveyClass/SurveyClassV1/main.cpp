/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 28, 2023 @ 10:31 AM
 * Purpose: v1) Read in 1 set of data
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int nUsers;
    string email;
    const char SIZE=20; //Max size of username and password
    char username[SIZE];
    char password[SIZE];

    //Initial Variables
    cout<<"Enter the number of users: ";
    cin>>nUsers;
    cin.ignore();
    cout<<"Enter email address: ";
    cin>>email;
    cout<<"Enter username: ";
    cin.ignore();
    cin.getline(username,SIZE-1);
    cout<<"Enter password: ";
    cin.getline(password,SIZE-1);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"Email: "<<email<<endl;
    cout<<"Username: "<<username<<endl;
    cout<<"Password: "<<password<<endl;

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

