/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v9) Class in main
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

struct SurveyQInfo {
    string question; //Question
    string responses[RSIZE]; //Responses
    int numResponses; //number of responses
};

class SurveyQ {
private:
    SurveyQInfo surveyQ; //pointer to dynamic SurveyQInfo struct

public:

    SurveyQ() {
        cout << endl;
        cout << "Enter Question: ";
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
    }

    ~SurveyQ() {
//        delete surveyQ;
    }

    void display() {
        //Display question
        cout << endl;
        cout << "Question: " << surveyQ.question << endl;
        for (int j = 0; j < surveyQ.numResponses; j++) {
            cout << left;
            cout << setw(2) << j + 1 << ") ";
            cout << surveyQ.responses[j] << endl;
        }
    }

    void setQuestion(string q) {
        surveyQ.question=q;
    }
    
    void setResponse(string r,int i) {
        surveyQ.responses[i]=r;
    }
    
    void deleteResponse(int i) {
    if (i >= 0 && i < surveyQ.numResponses) {
        //go through vector after index of deleted response and shift to the left by 1
        for (int j = i; j < surveyQ.numResponses - 1; j++) {
            surveyQ.responses[j] = surveyQ.responses[j + 1];
        }
        surveyQ.numResponses--;    //decrement number of responses
    }
}
};

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    SurveyQ survQ;

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    survQ.display();
    survQ.deleteResponse(3);
    survQ.display();
    survQ.deleteResponse(6);
    survQ.display();
    
    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}