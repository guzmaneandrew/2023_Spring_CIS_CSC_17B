/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"
#include "Survey.h"

Survey::Survey() {
    strcpy(title, " ");
    numQuestions = 0;
    questions = nullptr;
}

Survey::Survey(string title, int numQuestions) {
    strcpy(this->title, title.c_str());
    this->numQuestions = numQuestions;
    questions = new Question[numQuestions];
}

Survey::~Survey() {
    delete[] questions;
}

void Survey::display() {
    cout << endl << "Survey Title: " << title << endl;
    cout << "Number of Questions: " << numQuestions << endl;
    for (int i = 0; i < numQuestions; i++) {
        questions[i].display();
    }
}

void Survey::updateQuestion(int i) {
    cout<<"Changing Question "<<i+1<<"..."<<endl;
    delete[] questions[i].getQInfo()->respInfo;
    delete questions[i].getQInfo();

    questions[i].updateQ();
}

void Survey::setTitle(char title[]) {
    strcpy(this->title, title);
}

void Survey::setNumQs(int numQs) {
    numQuestions=numQs;
}