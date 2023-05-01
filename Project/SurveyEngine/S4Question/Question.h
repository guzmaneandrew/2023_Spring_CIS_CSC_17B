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
#include "Headers.h"
#ifndef QUESTION_H
#define QUESTION_H

struct QuestionInfo {
    char question[QRSIZE];
    int typeInt;
    int numRespOptions;
    char respOption1[QRSIZE];
    char respOption2[QRSIZE];
    char respOption3[QRSIZE];
    char respOption4[QRSIZE];
    char respOption5[QRSIZE];
};

class Question {
private:
    QuestionInfo *questInfo;
public:

    Question() {
        strcpy(question, " ");
        questInfo = nullptr;
        typeInt = 0;
        numRespOptions = 0;
        strcpy(respOption1, " ");
        strcpy(respOption2, " ");
        strcpy(respOption3, " ");
        strcpy(respOption4, " ");
        strcpy(respOption5, " ");
    }

    Question() {
        questInfo = new QuestionInfo;

        cout << "Enter Question: ";
        cin.getline(questInfo->question, QRSIZE);

        cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
        cin >> questInfo->typeInt;

        cout << "Enter Number of Response Options: ";
        cin >> questInfo->numRespOptions;
        cin.ignore();

        cout << "Enter Response Option 1: ";
        cin.getline(questInfo->respOption1, QRSIZE);

        cout << "Enter Response Option 2: ";
        cin.getline(questInfo->respOption2, QRSIZE);

        cout << "Enter Response Option 3: ";
        cin.getline(questInfo->respOption3, QRSIZE);

        cout << "Enter Response Option 4: ";
        cin.getline(questInfo->respOption4, QRSIZE);

        cout << "Enter Response Option 5: ";
        cin.getline(questInfo->respOption5, QRSIZE);
    }

    ~Question() {
        delete questInfo;
    }

    void display() {
        cout << endl;
        cout << "Question: " << questInfo->question << endl;
        cout << left;
        cout << setw(3) << "1) " << questInfo->respOption1 << endl;
        cout << setw(3) << "2) " << questInfo->respOption2 << endl;
        cout << setw(3) << "3) " << questInfo->respOption3 << endl;
        cout << setw(3) << "4) " << questInfo->respOption4 << endl;
        cout << setw(3) << "5) " << questInfo->respOption5 << endl;
    }

    QuestionInfo *getQInfo() const {
        return questInfo;
    }

    char *getQuestion() const {
        return questInfo->question;
    }

    int getType() const {
        return questInfo->typeInt;
    }

    int getNumResp() const {
        return questInfo->numRespOptions;
    }

    char *getRespOpt1() const {
        return questInfo->respOption1;
    }
    
    char *getRespOpt1() const {
        return questInfo->respOption1;
    }
};

#endif /* QUESTION_H */

