/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 7, 2023 @ 9:29 PM
 * Purpose: Create one survey
 */

//System Libraries
#include "Headers.h"

//User Libraries
#include "Survey.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
void saveToBin(Survey);
Survey createSurvey(char[], int);
void readSurveys();
void updateSurveys();
void deleteSurveys();

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    char title[TSIZE];
    int numQs;
    vector<Survey> surveys;
    vector<SurveyQInfo> surveyQs;
    Survey survey;

    //Create 1 survey
    for(int i=0;i<numSurvs;i++) {
        cout << "Enter Title: ";
        cin.getline(title, TSIZE);
        cout << "Enter Number of Questions: ";
        cin>>numQs;
        cin.ignore();
        survey.setTitle(title);
        survey.setNumQuestions(numQs);
        //Create survey questions for the survey
        for (int i = 0; i < numQs; i++) {
            SurveyQInfo surveyQ;
            cout << "Enter Question: ";
            cin.getline(surveyQ.question, QRSIZE);
            cout << "Enter Response Option 1: ";
            cin.getline(surveyQ.respOpt1, QRSIZE);
            cout << "Enter Response Option 2: ";
            cin.getline(surveyQ.respOpt2, QRSIZE);
            cout << "Enter Response Option 3: ";
            cin.getline(surveyQ.respOpt3, QRSIZE);
            cout << "Enter Response Option 4: ";
            cin.getline(surveyQ.respOpt4, QRSIZE);
            cout << "Enter Response Option 5: ";
            cin.getline(surveyQ.respOpt5, QRSIZE);
            surveyQs.push_back(surveyQ);
        }
        survey.setQuestions(surveyQs);
        //Save 1 survey to binary
        survey.saveToBin();        
    }

    cout << "Reading from binary..." << endl;
    readSurveys(surveys);

    //Display 1 survey

    //Clean Up the Dynamic Stuff


    //Exit 
    return 0;
}

Survey createSurvey(char title[], int numQs) {

}

void saveToBin(Survey survey) {
}

void readSurveys() {
    ifstream surveyDB("SurveyInfo.dat", ios::in | ios::binary);
    adminDB.seekg(ios::beg);
    if (!surveyDB) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    // Read the title - 50 bytes
    char title[TSIZE];
    surveyDB.read(title, sizeof (title));
    cout << "Title: " << title << endl << endl;

    // Read the number of questions - 4 bytes
    int numQuestions;
    surveyDB.read(reinterpret_cast<char*> (&numQuestions), sizeof (numQuestions));
    cout << "Number of questions: " << numQuestions << endl << endl;

    // Read the status - 1 byte
    bool status;
    surveyDB.read(reinterpret_cast<char*> (&status), sizeof (status));
    cout << "Active: " << boolalpha << status << endl << endl;

    // Read the number of SurveyQuestion structs - 4 bytes
    int numSurvQ;
    surveyDB.read(reinterpret_cast<char*> (&numSurvQ), sizeof (numSurvQ));
    cout << "Number of SurveyQuestion structs: " << numSurvQ << endl << endl;

    // Read the survey questions vector
    for (int i = 0; i < numSurvQ; i++) {
        SurveyQInfo q;

        // Read the question string - 100 bytes
        surveyDB.read(q.question, sizeof (q.question));
        cout << "Question " << i + 1 << ": " << q.question << endl;

        // Read the respOptions - 5 * (100 bytes)
        surveyDB.read(q.respOpt1, sizeof (q.respOpt1));
        cout << "Response option 1: " << q.respOpt1 << endl;

        surveyDB.read(q.respOpt2, sizeof (q.respOpt2));
        cout << "Response option 2: " << q.respOpt2 << endl;

        surveyDB.read(q.respOpt3, sizeof (q.respOpt3));
        cout << "Response option 3: " << q.respOpt3 << endl;

        surveyDB.read(q.respOpt4, sizeof (q.respOpt4));
        cout << "Response option 4: " << q.respOpt4 << endl;

        surveyDB.read(q.respOpt5, sizeof (q.respOpt5));
        cout << "Response option 5: " << q.respOpt5 << endl;
    }
    surveyDB.close();
}

void updateSurveys() {

}

void deleteSurveys() {

}

//ADMIN
//Access to surveyDB
//Create a survey
//Read surveys from surveyDB to vector
//Update surveys
//Delete survey (change survey status)

//Access to userDB
//Create user
//Read user
//Update user
//Delete user (change status to inactive)

//Access to adminDB
//Create admin
//Read admin
//Update admin
//Delete admin (change status to inactive)
//