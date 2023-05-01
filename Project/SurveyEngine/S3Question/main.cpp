/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 6:29 PM
 * Purpose: v3) Class in Main
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries
#include "Headers.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

struct ResponseInfo {
    char respOption[QRSIZE];
};

struct QuestionInfo {
    char question[QRSIZE];
    int typeInt;
    int numRespOptions;
    ResponseInfo *respInfo;
};

struct Questions {
    int numQuestions;
    QuestionInfo *questInfo;
};

class CQuestion {
private:
    Questions *questions;   //Pointer to dynamically allocated Questions structure
public:
    CQuestion();
    ~CQuestion();
    void display();
    int getNumQ() const { return questions->numQuestions; }
    QuestionInfo *getQInfo() const { return questions->questInfo; }
    char *getQuestion(int n) const { return questions->questInfo[n].question; }
    int getType() const { return questions->questInfo->typeInt; }
    int getNumResp() const { return questions->questInfo->numRespOptions; }
    ResponseInfo *getRespInfo() const { return questions->questInfo->respInfo; }
    char *getRespOption(int n) const { return questions->questInfo->respInfo[n].respOption; }
};

CQuestion::CQuestion() {
    questions = new Questions;

    cout << "Enter Number of Questions: ";
    cin >> questions->numQuestions;
    cin.ignore();

    questions->questInfo= new QuestionInfo[questions->numQuestions];

    for (int i = 0; i < questions->numQuestions; i++) {
        cout << "Enter Question " << i + 1 << ": ";
        cin.getline(questions->questInfo[i].question, QRSIZE);

        cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
        cin >> questions->questInfo[i].typeInt;


        cout << "Enter Number of Response Options: ";
        cin >> questions->questInfo[i].numRespOptions;
        cin.ignore();

        questions->questInfo[i].respInfo = new ResponseInfo[questions->questInfo[i].numRespOptions];
        for (int j = 0; j < questions->questInfo[i].numRespOptions; j++) {
            cout << "Enter Response Option " << j + 1 << ": ";
            cin.getline(questions->questInfo[i].respInfo[j].respOption, QRSIZE);
        }
    }
}

void CQuestion::display() {
    for (int i = 0; i < questions->numQuestions; i++) {
        cout << endl;
        cout << "Question: " << questions->questInfo[i].question << endl;
        cout << "Number of Response Options: " << questions->questInfo[i].numRespOptions << endl;
        for (int j = 0; j < questions->questInfo[i].numRespOptions; j++) {
            cout << left;
            cout << setw(3) << j + 1 << ") " << questions->questInfo[i].respInfo[j].respOption << endl;
        }
    }
}

CQuestion::~CQuestion() {
    for (int i = 0; i < questions->numQuestions; i++) {
        delete [] questions->questInfo[i].respInfo;
    }
    delete []questions->questInfo;
    delete questions;
}



//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    CQuestion cquestion;        //Instance of the CQuestion class

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean Up the Dynamic Stuff;

    //Exit 
    return 0;
}