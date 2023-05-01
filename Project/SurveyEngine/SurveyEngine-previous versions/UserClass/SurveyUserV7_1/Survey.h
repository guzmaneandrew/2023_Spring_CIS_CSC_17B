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

#include "SurveyQuestion.h"

struct Survey {
    int numQuestions;           //Number of questions
    SurveyQuestion *questions;  //Structure within a structure
};

#endif /* SURVEY_H */

