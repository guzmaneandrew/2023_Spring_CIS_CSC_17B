/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SurveyQuestion.h
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 4:02 PM
 */

#ifndef SURVEYQUESTION_H
#define SURVEYQUESTION_H

const int MAX=10;       //MAX number of questions/responses
struct SurveyQuestion {
    string question;        //Question
    string responses[MAX];  //Possible responses
    int numResponses;       //number of response options for question
    char questionType;      //Type of question
};

#endif /* SURVEYQUESTION_H */

