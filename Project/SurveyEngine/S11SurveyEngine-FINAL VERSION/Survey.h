/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Survey.h
 * Author: andrewguzman
 *
 * Created on April 9, 2023, 11:43 AM
 */
#include "Headers.h"
#ifndef SURVEY_H
#define SURVEY_H
const int TSIZE = 50; //max size of title

class Survey {
private:
    char title[TSIZE];
    bool status;
    int numQs;
    vector<Question *> questions;
public:
    Survey();
    Survey(char [], int);
    ~Survey();
    void newSurvQ();
    void addQ();
    const char *getTitle() const;
    string getTitle(bool) const;
    void setTitle(char []);
    void setNumQs(int);
    void setStatus(bool);
    void setQs(vector<Question *>);
    void deleteQ(int i);
    bool getStatus() const;
    int getNumQs() const;
    vector<Question *> getQs();
    Question *getQ(int);
    void display();
    void saveToBin(string);
    void readFromBin(string);
};

#endif /* SURVEY_H */

