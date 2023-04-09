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

struct ResponseInfo {
    char respOption[QRSIZE];
};

struct QuestionInfo {
    char question[QRSIZE];
    int typeInt;
    int numRespOptions;
    ResponseInfo *respInfo;
};

class Question {
private:
    QuestionInfo *questInfo;
public:
    Question();
    ~Question();
    void display();
    QuestionInfo *getQInfo() const { return questInfo; }
    char *getQuestion() const { return questInfo->question;}
    int getType() const { return questInfo->typeInt; }
    int getNumResp() const { return questInfo->numRespOptions; }
    ResponseInfo *getRespInfo() const { return questInfo->respInfo; }
    char *getRespOption(int n) const { return questInfo->respInfo[n].respOption; }
};

#endif /* QUESTION_H */

