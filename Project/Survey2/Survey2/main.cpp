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
void writeToFile(Survey*);
//void readFromFile(Survey*);
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
    
//    writeToFile(survey);
    
//    Survey *newSurv=new Survey();
//    readFromFile(newSurv);
//    newSurv->display();

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

void writeToFile(Survey* survey) {
    ofstream outFile("SurveyInfo.dat", ios::binary);

    // Write the Survey title to the file
    outFile.write(survey->getTitle(), TSIZE);

    // Write the number of questions to the file
    int numQs=survey->getNumQs();
    outFile.write(reinterpret_cast<const char*>(&numQs), sizeof(int));

    // Loop through the questions and write each one to the file
    for (int i = 0; i < numQs; i++) {
        QuestionInfo* qInfo = survey->getQuestions()[i].getQInfo();

        // Write the QuestionInfo struct to the file
        outFile.write(reinterpret_cast<const char*>(qInfo), sizeof(QuestionInfo));

        // Loop through the ResponseInfo structs and write each one to the file
        for (int j = 0; j < qInfo->numRespOptions; j++) {
            outFile.write(qInfo->respInfo[j].respOption, QRSIZE);
        }
    }

    outFile.close();
}

//void readFromFile(Survey* survey) {
//    ifstream inFile("SurveyInfo.dat", ios::binary);
//
//    // Read the Survey title from the file
//    char title[TSIZE];
//    inFile.read(title, TSIZE);
//    survey->setTitle(title);
//
//    // Read the number of questions from the file
//    int numQs;
//    inFile.read(reinterpret_cast<char*>(&numQs), sizeof(int));
//    survey->setNumQs(numQs);
//
//    // Loop through the questions and read each one from the file
//    for (int i = 0; i < numQs; i++) {
//        QuestionInfo* qInfo = new QuestionInfo;
//
//        // Read the QuestionInfo struct from the file
//        inFile.read(reinterpret_cast<char*>(qInfo), sizeof(QuestionInfo));
//
//        // Create a new Question object and set its QuestionInfo struct
//        Question* question = new Question();
//        question->setQInfo(qInfo);
//
//        // Loop through the ResponseInfo structs and read each one from the file
//        ResponseInfo* respInfo = new ResponseInfo[qInfo->numRespOptions];
//        for (int j = 0; j < qInfo->numRespOptions; j++) {
//            inFile.read(respInfo[j].respOption, QRSIZE);
//        }
//        question->setRespInfo(respInfo);
//
//        // Add the Question to the Survey's array of questions
//        survey->getQuestions()[i] = *question;
//    }
//
//    inFile.close();
//}
//


