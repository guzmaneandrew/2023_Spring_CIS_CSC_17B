/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SurveyQ.h
 * Author: andrewguzman
 *
 * Created on April 5, 2023, 3:47 PM
 */

#ifndef SURVEYQ_H
#define SURVEYQ_H

//Structure Definitions
struct SurveyQInfo {
    string question; //Question
    string responses[RSIZE]; //Responses
    int numResponses; //number of responses
};

class SurveyQ {
private:
    SurveyQInfo surveyQ;

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
        surveyQ.question = q;
    }

    void setResponse(string r, int i) {
        surveyQ.responses[i] = r;
    }

    void deleteResponse(int i) {
        if (i >= 0 && i < surveyQ.numResponses) {
            //go through vector after index of deleted response and shift to the left by 1
            for (int j = i; j < surveyQ.numResponses - 1; j++) {
                surveyQ.responses[j] = surveyQ.responses[j + 1];
            }
            surveyQ.numResponses--; //decrement number of responses
        }
    }
};

#endif /* SURVEYQ_H */

