/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Question.h
 * Author: andrewguzman
 *
 * Created on April 8, 2023, 10:20 PM
 */
#ifndef QUESTION_H
#define QUESTION_H
#include "Headers.h"

enum QType {
    SINGLE = 1, MULTIPLE = 2, WRITEIN = 3
}; //Question type

const int QRSIZE = 100; //max size of question and response

class Question {
private:
    char question[QRSIZE];
    int typeInt;
    int numRespOptions;
    vector<string> respOptions;
public:

    Question() {
        strcpy(question, " ");
        typeInt = 0;
        numRespOptions = 0;
    }

    Question(char q[], int type, int numResp, vector<string> options) {
        strcpy(question, q);
        typeInt = type;
        numRespOptions = numResp;
        respOptions = options;
    }

    void setQ(char q[]) {
        strcpy(question, q);
    }

    void setType(int t) {
        typeInt = t;
    }

    void setNumResp(int n) {
        numRespOptions = n;
    }

    void setRespOptions(vector<string> options) {
        respOptions = options;
    }

    void setResp(int i) {
        string response;
        cout << endl<< "Enter New Response Option: ";
        getline(cin, response);

        if (i >= 0 && i < respOptions.size()) {
            respOptions[i] = response;
        }
    }

    void addResp() {
        numRespOptions++;
        string response;
        cout << "Enter New Response Option: ";
        getline(cin, response);
        respOptions.push_back(response);
    }
    
    void deleteROpt(int i) {
        numRespOptions--;
        respOptions.erase(respOptions.begin() + i);
    }

    const char *getQ() const {
        return question;
    }

    int getType() const {
        return typeInt;
    }

    int getNumResp() const {
        return respOptions.size();
    }

    vector<string> getRespOptions() const {
        return respOptions;
    }

    string dispType() {
        if (typeInt == SINGLE) return "Single Choice";
        else if (typeInt == MULTIPLE) return "Multiple Choice";
        else if (typeInt == WRITEIN) return "Multiple Choice/Write-In Response";
        else return " ";
    }

    void display() {
        cout << question << endl;
        cout << "Type: " << dispType() << endl;
        cout << left;
        for (int i = 0; i < numRespOptions; i++) {
            cout << setw(3) << i + 1 << ") " << respOptions[i] << endl;
        }
        cout << endl;
    }
};

#endif /* QUESTION_H */


//    SAVE FOR SURVEY CLASS
//    Question() {
//        cout << "Enter Question: ";
//        cin.getline(questInfo->question, QRSIZE);
//
//        cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
//        cin >> questInfo->typeInt;
//
//        cout << "Enter Number of Response Options: ";
//        cin >> questInfo->numRespOptions;
//        cin.ignore();
//
//        cout << "Enter Response Option 1: ";
//        cin.getline(questInfo->respOption1, QRSIZE);
//
//        cout << "Enter Response Option 2: ";
//        cin.getline(questInfo->respOption2, QRSIZE);
//
//        cout << "Enter Response Option 3: ";
//        cin.getline(questInfo->respOption3, QRSIZE);
//
//        cout << "Enter Response Option 4: ";
//        cin.getline(questInfo->respOption4, QRSIZE);
//
//        cout << "Enter Response Option 5: ";
//        cin.getline(questInfo->respOption5, QRSIZE);
//    }