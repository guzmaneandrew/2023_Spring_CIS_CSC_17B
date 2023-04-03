/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 28, 2023 @ 10:31 AM
 * Purpose: v2) Read in N sets of data
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
    string email,password;
    const char QSIZE=81;    //Max size of question
    char question[QSIZE];   
    int numQs,numOpts=4;      //Number of questions,options
    string optns[numOpts];
    
    //Initial Variables
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
        cout<<"Email: "<<email<<endl;
        cout<<"Password: "<<password<<endl<<endl; 
    }
    
    cin.ignore();
    cout<<"Enter a Survey Question: ";
    cin.getline(question,QSIZE-1);

    for(int i=0;i<numOpts;i++) {
        cout<<"Enter Response Option "<<i+1<<": ";
        cin>>optns[i];
    }
    
    cout<<"Survey Question: "<<question<<endl;
    for(int i=0;i<numOpts;i++) {
        cout<<optns[i]<<endl;
    }

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}