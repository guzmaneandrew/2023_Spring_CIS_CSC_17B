/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>     //I/O Library
#include <cstdlib>      //Random Number Generator, Setting Seed, etc...
#include <iomanip>      //Formatting Library
using namespace std;    //Libraries compiled under std

#include "CSurvey.h"
CSurvey::CSurvey() {
    survey=new Survey;
    
    cout<<"Enter Number of Questions: ";
    cin>>survey->numQuestions;
    
    survey->questions=new SurveyQuestion[survey->numQuestions];
    
    for(int i=0;i<survey->numQuestions;i++) {
            cout<<"Question "<<i+1<<endl;
            cout<<"Enter Question Type\n(1 = Multiple Choice,"
                    " 2 = Single Choice, 3 = Write-In): ";
            cin>>survey->questions[i].questionType;
            cin.ignore();
            cout<<"Enter Question: ";
            getline(cin,survey->questions[i].question);
            do {
                cout<<"Enter Number of Response Options(up to 10): ";
                cin>>survey->questions[i].numResponses;
                cin.ignore();
            }while(survey->questions[i].numResponses>10);
            for(int j=0;j<survey->questions[i].numResponses;j++) {
                cout<<"Enter Response Option "<<j+1<<": ";
                getline(cin,survey->questions[i].responses[j]);
            }
    }
}

CSurvey::~CSurvey() {
    delete []survey;
}

void CSurvey::display() {
    cout<<"Survey"<<endl;
    for(int i=0;i<survey->numQuestions;i++) {
        cout<<"Question "<<i+1<<": "<<survey->questions[i].question<<endl;
        for(int j=0;j<survey->questions[i].numResponses;j++) {
            cout<<j+1<<") "<<survey->questions[i].responses[j]<<endl;    
        }
    }
}