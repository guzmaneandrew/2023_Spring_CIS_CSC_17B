/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v3 and v4) Format the results and static structure array
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
const int TSIZE = 50;
const int RSIZE = 10; //max number of response options per question
const int SSIZE = 5; //max number of survey questions in a survey

//Structure Definitions

struct SurveyQuestion {
    string question; //Question
    string responses[RSIZE];    //Responses
    int numResponses; //number of responses
};

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    int numQuestions;
    vector<SurveyQuestion> questions; //vector of survey questions

    //Enter input for 1 question, multiple responses
    do {
        cout << "Enter Number of Questions(up to 10): ";
        cin >> numQuestions;
        cin.ignore();
    } while (numQuestions > 10);

    for (int i = 0; i < numQuestions; i++) {
        cout << endl;
        SurveyQuestion surveyQ;
        cout << "Enter Question " << i + 1 << ": ";
        getline(cin, surveyQ.question);

        do {
            cout << "Enter Number of Responses (up to 10): ";
            cin >> surveyQ.numResponses;
            cin.ignore();
        } while (surveyQ.numResponses > 10);

        cout << surveyQ.numResponses << endl;

        for (int j = 0; j < surveyQ.numResponses; j++) {
            cout << "Enter Response " << j + 1 << ": ";
            getline(cin, surveyQ.responses[j]);
        }

        questions.push_back(surveyQ);

    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    //Display questions
    for (int i = 0; i < numQuestions; i++) {
        cout << endl;
        cout << "Question " << i + 1 << ": " << questions[i].question << endl;
        for (int j = 0; j < questions[i].numResponses; j++) {
            cout << left;
            cout << setw(2) << j + 1 << ") ";
            cout << questions[i].responses[j] << endl;
        }
    }

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

