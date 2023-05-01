/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v5 ) Dynamic structure
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
#include <vector>     //Vector library
using namespace std; //Libraries compiled under std

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int QRSIZE = 100; //max size of question and response
const int TSIZE = 50;
const int RSIZE = 10; //max number of response options per question
const int SSIZE = 5; //max number of survey questions in a survey

//Structure Definitions

struct SurveyQInfo {
    string question; //Question
    string responses[RSIZE];    //Responses
    int numResponses; //number of responses
};

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    SurveyQInfo *srvQInfo;
    int numQuestions;

    //Enter input for 1 question, multiple responses
    do {
        cout << "Enter Number of Questions(up to 10): ";
        cin >> numQuestions;
        cin.ignore();
    } while (numQuestions > 10);
    
    srvQInfo=new SurveyQInfo[numQuestions];

    for (int i = 0; i < numQuestions; i++) {
        cout << endl;
        cout << "Enter Question " << i + 1 << ": ";
        getline(cin, srvQInfo[i].question);

        do {
            cout << "Enter Number of Responses (up to 10): ";
            cin >> srvQInfo[i].numResponses;
            cin.ignore();
        } while (srvQInfo[i].numResponses > 10);

        cout << srvQInfo[i].numResponses << endl;

        for (int j = 0; j < srvQInfo[i].numResponses; j++) {
            cout << "Enter Response " << j + 1 << ": ";
            getline(cin, srvQInfo[i].responses[j]);
        }

    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    //Display questions
    for (int i = 0; i < numQuestions; i++) {
        cout << endl;
        cout << "Question " << i + 1 << ": " << srvQInfo[i].question << endl;
        for (int j = 0; j < srvQInfo[i].numResponses; j++) {
            cout << left;
            cout << setw(2) << j + 1 << ") ";
            cout << srvQInfo[i].responses[j] << endl;
        }
    }

    //Clean Up the Dynamic Stuff
    delete []srvQInfo;

    //Exit 
    return 0;
}

