/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Survey.h
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 4:01 PM
 */

#ifndef SURVEY_H
#define SURVEY_H

const int SIZE=100;    //Question/response size
const int TSIZE=50;     //Title size

struct SurveyQuestion {
    char question[SIZE];        //Question
    vector<char [SIZE]> responses;  //Possible responses
    int numResponses;       //number of response options for question
    QType questionType;      //Type of question
};

struct SurveyInfo {
    char title[TSIZE];               //Survey title
    int numQuestions;           //Number of questions
    vector<SurveyQuestion> questions;   //Questions in a survey
};

class Survey {
    private:
        SurveyInfo *survey;        //Pointer to dynamic Survey structure
    public:
//        Constructors/Destructor
        Survey();
        Survey(char [],int,vector<SurveyQuestion>);    
        ~Survey();
//        Setter Functions
        void addQuestion(SurveyQuestion);
        void deleteQuestion(int);
        
//        Getter Functions
        vector<SurveyQuestion> getQuestions() const { return survey->questions;}
        string getTitle() const { return survey->title;}
//        Display and write to files
        void display(); 
        void writeToFile(Survey *);
        void readFromFile();
//        Helper functions
        void displayType(QType);
};

#endif /* SURVEY_H */

