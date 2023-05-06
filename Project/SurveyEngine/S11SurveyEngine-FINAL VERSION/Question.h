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
    Question();
    Question(char [],int, int, vector<string>);
    void setQ(char []);
    void setType(int);
    void setNumResp(int);
    void setRespOptions(vector<string>);
    void setResp(int);
    void addResp();
    void deleteROpt(int);
    const char* getQ() const;
    int getType() const;
    int getNumResp() const;
    vector<string> getRespOptions() const;
    string dispType();
    void display();
};

#endif /* QUESTION_H */
