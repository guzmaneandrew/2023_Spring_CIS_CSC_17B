/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v1) Read in 1 set of information for 1 survey question
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
#include <vector>     //Vector library
#include <array>      //Array library
using namespace std; //Libraries compiled under std

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int QRSIZE=100;   //max size of question and response
const int TSIZE=50;
const int RSIZE=10;    //max number of response options per question
const int SSIZE=20;     //max number of survey questions in a survey

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    const int QRSIZE=50; //Maximum size of question and response
    char question[QRSIZE]; //Question
    char response[QRSIZE]; //Survey question response
    
    //Initialize Variables
    //Enter input for 1 question
    cout<<"Enter Question: ";
    cin.getline(question,QRSIZE-1);
    cout<<"Enter Response for This Question: ";
    cin.getline(response,QRSIZE-1);


    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"Question: "<<question<<endl;
    cout<<"Response: "<<response<<endl;

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

