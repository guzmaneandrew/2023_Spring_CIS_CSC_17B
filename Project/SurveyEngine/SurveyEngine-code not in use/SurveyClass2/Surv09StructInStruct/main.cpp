/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v9) Struct in a struct
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
const int QRSIZE = 100; //max size of question and response
const int TSIZE = 50; //max size of title
const int RSIZE = 10; //max number of response options per question
const int SSIZE = 10; //max number of survey questions in a survey

//Structure Definitions

struct SurveyQInfo {
    string question; //Question
    string responses[QRSIZE]; //Responses
    int numResponses; //number of responses
};

struct SurveyInfo {
    int numQuestions; //Number of questions
    string title; //Title of survey
    vector<SurveyQInfo> questions; //questions in Survey
};

//Function Prototypes
SurveyInfo *fillDat(); //Fill
void display(SurveyInfo *); //Display
void destroy(SurveyInfo *); //Delete memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    SurveyInfo *survey;

    //Map the Inputs to the Outputs
    survey = fillDat();

    //Display the Inputs and Outputs
    display(survey);


    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

SurveyInfo *fillDat() {
    SurveyInfo *survey = new SurveyInfo; //Declare pointer to SurveyInfo object

    do {
        cout << "Enter Number of Questions(up to 10): ";
        cin >> survey->numQuestions;
        cin.ignore();
    } while (survey->numQuestions > SSIZE);

    for (int i = 0; i < survey->numQuestions; i++) {
        cout << endl;
        cout << "Enter Question " << i + 1 << ": ";
        SurveyQInfo survQ;
        cin.ignore();
        survey->questions.push_back(survQ);
        
        do {
            cout << "Enter Number of Responses (up to 10): ";
            cin >> survey->questions[i].numResponses;
            cin.ignore();
        } while (survey->questions[i].numResponses > 10);

        for (int j = 0; j < survey->questions[i].numResponses; j++) {
            cout << "Enter Response " << j + 1 << ": ";
            getline(cin, survey->questions[i].responses[j]);
        }
    }
    
    return survey;
}

void display(SurveyInfo *survey) {
    //Display questions
    for (int i = 0; i < survey->numQuestions; i++) {
        cout << endl;
        cout << "Question " << i + 1 << ": " << survey->questions[i].question << endl;
        for (int j = 0; j < survey->questions[i].numResponses; j++) {
            cout << left;
            cout << setw(2) << j + 1 << ") ";
            cout << survey->questions[i].responses[j] << endl;
        }
    }
}

void destroy(SurveyInfo* survey) {
    delete []survey;
}