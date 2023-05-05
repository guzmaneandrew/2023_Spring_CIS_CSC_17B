/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 7:53 PM
 * Purpose: v8) Class in separate .h and .cpp files
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries
#include "SurveyEngine.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
void dispMenu();

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    string username,password;
    User user;      //Create an instance of the CUsers class
    
    //Initial Variables
    cout<<"Enter Username: "<<endl;
    cin.getline(username,MAXSIZE);
    cout<<"Enter Password: "<<endl;
    cin.getline(password,MAXSIZE);

    //Map the Inputs to the Outputs
    user.setInfo(username,password);
   //Display the Inputs and Outputs 
    user.displayInfo();

    //Clean Up the Dynamic Stuff
    
    //Exit 
    return 0;
}

void dispMenu() {
    cout<<"Press 1: Admin Login"<<endl;
    cout<<"Press 2: User Login"<<endl;
    cout<<"Press 3: Create Admin Account"<<endl;
    cout<<"Press 4: Create User Account"<<endl;
}