/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Survey.h
 * Author: andrewguzman
 *
 * Created on April 5, 2023, 7:59 PM
 */

#ifndef SURVEY_H
#define SURVEY_H

#include "Headers.h"

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

    Survey() {
        info = new SurveyInfo; //Declare pointer to SurveyInfo object

        //Read in survey title
        cout << "Enter Survey Title: ";
        getline(cin, info->title);

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
            getline(cin, info->questions[i].question);

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
    
    ~Survey() {
        delete info;
    }
    
//    Setters
    void setNumQuestions(int n) {
        info->numQuestions=n;
    }
    
    void setTitle(string t) {
        info->title=t;
    }
    
    void setQuestion(int i,string q) {
        info->questions[i].question=q;
    }
    
    void display() {
        //Display survey
        cout<<endl;
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
};

#endif /* SURVEY_H */

