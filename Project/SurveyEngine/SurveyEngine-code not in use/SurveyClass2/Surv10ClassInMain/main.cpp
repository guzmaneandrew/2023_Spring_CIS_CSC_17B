/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 4:39 PM
 * Purpose: v10) Class in Main
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
const int TSIZE = 50; //max size of title
const int RSIZE = 10; //max number of response options per question
const int SSIZE = 10; //max number of info questions in a info

//Structure Definitions

struct SurveyQInfo {
    string question; //Question
    string responses[QRSIZE]; //Responses
    int numResponses; //number of responses
};

struct SurveyInfo {
    int numQuestions; //Number of questions
    string title; //Title of info
    vector<SurveyQInfo> questions; //questions in Survey
};

class Survey {
private:
    SurveyInfo *info;
public:
    Survey();
    ~Survey();
    void display();
};

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    Survey survey;      //instance of the survey class

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    survey.display();


    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

Survey::Survey() {
    info = new SurveyInfo; //Declare pointer to SurveyInfo object

    //Read in survey title
    cout<<"Enter Survey Title: ";
    getline(cin,info->title);
    
    //Read in number of questions in survey
    do {
        cout << "Enter Number of Questions(up to 10): ";
        cin >> info->numQuestions;
        cin.ignore();
    } while (info->numQuestions > SSIZE);
    
    //Allocate memory for the questions vector
    info->questions.resize(info->numQuestions);

    //Set information for every survey question
    for (int i = 0; i < info->numQuestions; i++) {
//        SurveyQInfo survQ;
        cout << endl;
        cout << "Enter Question " << i + 1 << ": ";
        //Read in the question
        getline(cin,info->questions[i].question);
        
        //Read in number of responses
        do {
            cout << "Enter Number of Responses (up to 10): ";
            cin >> info->questions[i].numResponses;
            cin.ignore();
        } while (info->questions[i].numResponses > RSIZE);

        //Read in responses
        for (int j = 0; j < info->questions[i].numResponses; j++) {
            cout << "Enter Response " << j + 1 << ": ";
            getline(cin, info->questions[i].responses[j]);
        }
    }
}

void Survey::display() {
    //Display survey
    cout<<"Title: "<<info->title<<endl;
    for (int i = 0; i < info->numQuestions; i++) {
        cout << endl;
        cout << "Question " << i + 1 << ": " << info->questions[i].question << endl;
        for (int j = 0; j < info->questions[i].numResponses; j++) {
            cout << left;
            cout << setw(2) << j + 1 << ") ";
            cout << info->questions[i].responses[j] << endl;
        }
    }
}

Survey::~Survey() {
    delete info;
}