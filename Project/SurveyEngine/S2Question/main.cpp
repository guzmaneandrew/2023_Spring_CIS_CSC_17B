/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 6:29 PM
 * Purpose: v2) Fill, display, destroy struct in a function,structure in a structure
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

//Function Prototypes
Questions *fillDat();
void display(Questions *);
void destroy(Questions *);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    Questions *questions;

    //Initial Variables
    questions = fillDat();

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    display(questions);

    //Clean Up the Dynamic Stuff
    destroy(questions);

    //Exit 
    return 0;
}

Questions *fillDat() {
    Questions *questions = new Questions;

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

    return questions;
}

void display(Questions *questions) {
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

void destroy(Questions *questions) {
    for (int i = 0; i < questions->numQuestions; i++) {
        delete [] questions->questInfo[i].respInfo;
    }
    delete []questions->questInfo;
    delete questions;
}