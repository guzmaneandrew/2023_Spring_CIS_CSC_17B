/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Survey.h
 * Author: andrewguzman
 *
 * Created on April 8, 2023, 10:51 PM
 */

#ifndef SURVEY_H
#define SURVEY_H

#include "Question.h"

class Survey {
private:
    char title[TSIZE];
    int numQuestions;
    Question* questions;
public:
    Survey();
    Survey(string,int);
    ~Survey();
    void display();
    Question *getQuestions() { return questions; }
    void updateQuestion(int);
};

#endif /* SURVEY_H */
