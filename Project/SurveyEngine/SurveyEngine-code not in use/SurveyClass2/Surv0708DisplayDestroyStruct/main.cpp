/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v7 and v8) Display and destroy structures in function
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
const int TSIZE = 50;   //max size of title
const int RSIZE = 10; //max number of response options per question
const int SSIZE = 10; //max number of survey questions in a survey

//Structure Definitions

struct SurveyQInfo {
    string question; //Question
    string responses[QRSIZE];    //Responses
    int numResponses; //number of responses
};

//Function Prototypes
SurveyQInfo *fillDat(int &);        //Fill
void display(SurveyQInfo *,int);    //Display
void destroy(SurveyQInfo *);        //Delete memory

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
    } while (numQuestions > SSIZE);
    
    //Map the Inputs to the Outputs
    srvQInfo=fillDat(numQuestions);
    
    //Display the Inputs and Outputs
    display(srvQInfo,numQuestions);

    //Clean Up the Dynamic Stuff
    destroy(srvQInfo);

    //Exit 
    return 0;
}

SurveyQInfo *fillDat(int &nQuestions) {
    SurveyQInfo *srvQInfo=new SurveyQInfo[nQuestions];

    for (int i = 0; i < nQuestions; i++) {
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

    return srvQInfo;
}

void display(SurveyQInfo *srvQInfo,int nQuestions) {
    //Display questions
    for (int i = 0; i < nQuestions; i++) {
        cout << endl;
        cout << "Question " << i + 1 << ": " << srvQInfo[i].question << endl;
        for (int j = 0; j < srvQInfo[i].numResponses; j++) {
            cout << left;
            cout << setw(2) << j + 1 << ") ";
            cout << srvQInfo[i].responses[j] << endl;
        }
    }
}

void destroy(SurveyQInfo *srvQInfo) {
    delete []srvQInfo;
}