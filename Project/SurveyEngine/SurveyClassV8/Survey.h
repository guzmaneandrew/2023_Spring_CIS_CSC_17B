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

const int MAX=10;       //MAX number of questions/responses

struct SurveyQuestion {
    string question;        //Question
    string responses[MAX];  //Possible responses
    int numResponses;       //number of response options for question
    char questionType;      //Type of question
};

struct SurveyInfo {
    string title;               //Survey title
    int numQuestions;           //Number of questions
    vector<string> questions;   //Questions in a survey
};

class Survey {
    private:
        SurveyInfo *survey;        //Pointer to dynamic Survey structure
    public:
//        Constructors/Destructor
        Survey();
        Survey(string,int);    
        ~Survey();
//        Setter Functions
        void addQuestion(string);
        void deleteQuestion(int);
        
//        Getter Functions
        vector<string> getQuestions() const { return survey->questions;}
        string getTitle() const { return survey->title;}
//        Display and write to files
        void display(); 
        void writeToFile(Survey *);
        void readFromFile();
};

#endif /* SURVEY_H */

