/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v11) Class in .h file
 */

//System Libraries
//User Libraries
#include "Headers.h"
#include "Survey.h"

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    char title[TSIZE];
    int numSurv,numQ;
    
    cout<<"Enter Title: ";
    cin.getline(title, TSIZE);
    cout<<"Enter Number of Questions: ";
    cin>>numQ;
    cin.ignore();
    Survey survey(title,numQ);
    survey.display();

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

//ADMIN
    //Access to surveyDB
    //Create a survey
    //Read surveys from surveyDB to vector
    //Update surveys
    //Delete survey (change survey status)

    //Access to userDB
    //Create user
    //Read user
    //Update user
    //Delete user (change status to inactive)

    //Access to adminDB
    //Create admin
    //Read admin
    //Update admin
    //Delete admin (change status to inactive)
//
 
//USER 
    //Access to userDB - ONLY THEIR INFO
    //Read user 
    //Update user       
    //Delete user (change status to inactive)
    
    //Access to userSurvDB - ONLY THEIR INFO
    //Read userSurveys from userSurveyDB to vector
    //Update survey
    //Delete survey (change status to inactive)