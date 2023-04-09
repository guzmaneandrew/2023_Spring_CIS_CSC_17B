/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 10:44 PM
 * Purpose: v1) Modify previous Survey class 
 * implementation to use Question class
 */

//System Libraries
#include "Headers.h"
#include "Question.h"
#include "Survey.h"

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Initial Variables
    string title;
    int numQs;
    
    cout<<"Enter Survey Title: ";
    getline(cin,title);
    cout<<"Enter Number of Questions: ";
    cin>>numQs;
    cin.ignore();
    
    //Map the Inputs to the Outputs
    Survey *survey=new Survey(title,numQs);
    
    //Display the Inputs and Outputs
    survey->display();
    
    survey->updateQuestion(0);
    survey->display();

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

