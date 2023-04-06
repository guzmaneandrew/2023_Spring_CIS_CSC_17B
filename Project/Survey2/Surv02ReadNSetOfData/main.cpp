/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v2) Read in N set of information for N survey questions
 * ie:multiple responses
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
const int SSIZE=5;     //max number of survey questions in a survey

//Structure Definitions
struct SurveyQuestion {
    char question[QRSIZE]; //Question
    vector<array<char, QRSIZE> > responses;       //Responses for each question
    int numResponses;   //number of responses
};

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    int numQuestions;
    vector<SurveyQuestion> questions;    //vector of survey questions
    
    //Enter input for 1 question, multiple responses
    cout<<"Enter Number of Questions"<<endl;
    cin>>numQuestions;
    cin.ignore();
    for(int i=0;i<numQuestions;i++) {
        SurveyQuestion surveyQ;
        cout << "Enter Question: ";
        cin.getline(surveyQ.question, QRSIZE - 1);

        cout << "Enter Number of Responses: ";
        cin >> surveyQ.numResponses;
        cin.ignore();

        surveyQ.responses.resize(surveyQ.numResponses); // Resize the vector to hold numResponses

        for (int j = 0; j < surveyQ.numResponses; j++) {
            cout << "Enter Response " << j + 1 << ": ";
            cin.getline(surveyQ.responses[j].data(), QRSIZE - 1);
        }
        
        questions.push_back(surveyQ);
    }
   

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    //Display questions
    for(int i=0;i<numQuestions;i++) {
        cout << "Question: "<<questions[i].question<<endl;
        cout << "Number of Responses: "<<questions[i].numResponses<<endl;
        cout<<"Responses: "<<endl;
        for (int j = 0; j < questions[i].numResponses; j++) {
            cout << j + 1 << ") "<<questions[i].responses[j].data()<<endl;
        }
    }

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

