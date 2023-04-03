/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CSurvey.h
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 4:52 PM
 */

#ifndef CSURVEY_H
#define CSURVEY_H

#include "Survey.h"

class CSurvey {
    private:
        Survey *survey;        //Pointer to dynamic Survey structure
    public:
        CSurvey();      //Constructor
        ~CSurvey();     //Destructor
        void display(); //Display structures
};

#endif /* CSURVEY_H */

