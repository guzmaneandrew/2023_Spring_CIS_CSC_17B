/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 10:44 PM
 * Purpose: v1) Modify previous Survey class 
 * implementation to use Question class
 */

//System Libraries
#include "Headers.h"
#include "Question.h"
#include "Survey.h"

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
void writeToFile(const Survey&);
//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Initial Variables
    string title;
    int numQs;
    
    cout<<"Enter Survey Title: ";
    getline(cin,title);
    cout<<"Enter Number of Questions: ";
    cin>>numQs;
    cin.ignore();
    
    //Map the Inputs to the Outputs
    Survey *survey=new Survey(title,numQs);
    
    //Display the Inputs and Outputs
    survey->display();
    
    survey->updateQuestion(0);
    survey->display();

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

void writeToFile(Survey& survey) {
    ofstream outFile("SurveyInfo.dat", ios::binary);

    // Write the Survey title to the file
    outFile.write(survey.title, TSIZE);

    // Write the number of questions to the file
    outFile.write(reinterpret_cast<const char*>(&survey.numQuestions), sizeof(int));

    // Loop through the questions and write each one to the file
    for (int i = 0; i < survey.numQuestions; i++) {
        QuestionInfo* qInfo = survey.getQuestions()[i].getQInfo();

        // Write the QuestionInfo struct to the file
        outFile.write(reinterpret_cast<const char*>(qInfo), sizeof(QuestionInfo));

        // Loop through the ResponseInfo structs and write each one to the file
        for (int j = 0; j < qInfo->numRespOptions; j++) {
            outFile.write(qInfo->respInfo[j].respOption, QRSIZE);
        }
    }

    outFile.close();
}


