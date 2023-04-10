/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 6:29 PM
 * Purpose: V1) Read input...to..Dynamic structure
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
//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    QuestionInfo *questInfo;
    int numQuestions; //Number of questions and responses

    //Initial Variables
    cout << "Enter Number of Questions: ";
    cin >> numQuestions;
    cin.ignore();

    questInfo = new QuestionInfo[numQuestions];

    for (int i = 0; i < numQuestions; i++) {
        cout << "Enter Question " << i + 1 << ": ";
        cin.getline(questInfo[i].question, QRSIZE);

        cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
        cin >> questInfo[i].typeInt;


        cout << "Enter Number of Response Options: ";
        cin >> questInfo[i].numRespOptions;
        cin.ignore();
        
        questInfo[i].respInfo = new ResponseInfo[questInfo[i].numRespOptions];
        for (int j = 0; j < questInfo[i].numRespOptions; j++) {
            cout << "Enter Response Option " << j + 1 << ": ";
            cin.getline(questInfo[i].respInfo[j].respOption, QRSIZE);
        }
    }


    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    for (int i = 0; i < numQuestions; i++) {
        cout << endl;
        cout << "Question: " << questInfo[i].question << endl;
        cout << "Number of Response Options: " << questInfo[i].numRespOptions << endl;
        for (int j = 0; j < questInfo[i].numRespOptions; j++) {
            cout << left;
            cout << setw(3) << j + 1 << ") " << questInfo[i].respInfo[j].respOption << endl;
        }
    }


    //Clean Up the Dynamic Stuff

    for(int i=0;i<numQuestions;i++) {
        delete [] questInfo[i].respInfo;
    }
    delete []questInfo;

    //Exit 
    return 0;
}

