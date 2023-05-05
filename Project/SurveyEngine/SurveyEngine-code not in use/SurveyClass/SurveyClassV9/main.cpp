/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 4:50 PM
 * Purpose: v9) Survey class using SurveyQuestion
 * instead of strings
 */

//System Libraries

//User Libraries
#include "Headers.h"
#include "Survey.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int num1,num2;
    string title,q,r;
    vector<SurveyQuestion> qs;
    
    //Read information for SurveyInfo struct
    cout<<"Enter Survey Title: ";
    getline(cin,title);
    cout<<"Enter Number of Questions: ";
    cin>>num1;
    for(int i=0;i<num1;i++) {
        //Read information for SurveyQuestion struct
        cin.ignore();
        cout<<"Enter Question "<<i+1<<": ";
        getline(cin,q);
        SurveyQuestion surveyQ;
        surveyQ.question=q;
        cout<<"Enter question type: ";
        cin>>num2;
        surveyQ.questionType=static_cast<QType>(num2);
        cout<<"Enter number of responses: ";
        cin>>surveyQ.numResponses;
        cin.ignore();
        for(int j=0;j<surveyQ.numResponses;j++) {
            cout<<"Enter Response "<<j+1<<": ";
            getline(cin,r);
            surveyQ.responses.push_back(r);
        }
        qs.push_back(surveyQ);
        cout<<endl;
    }
    
    Survey *survey1=new Survey(title,num1,qs);        //Create an instance of the CSurvey class
   
    //Initialize Variables
    
    //Display the Inputs and Outputs
    survey1->display();
    survey1->writeToFile(survey1);
    
    Survey *survey2=new Survey;
    survey2->readFromFile();
    
    //Clean Up the Dynamic Stuff
    

    //Exit 
    return 0;
}