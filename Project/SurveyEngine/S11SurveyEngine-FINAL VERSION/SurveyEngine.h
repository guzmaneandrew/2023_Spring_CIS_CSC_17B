/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SurveyEngine.h
 * Author: andrewguzman
 *
 * Created on April 13, 2023, 10:48 PM
 */

#include "User.h"
#include "Admin.h"

#ifndef SURVEYENGINE_H
#define SURVEYENGINE_H

class SurveyEngine {
private:
    bool isActive;
    bool isAdmin;
    bool loggedIn;
    string username;
    string password;
public:
    SurveyEngine();
    void mainMenu();
    void login();
    void regUsr();
    bool validtUsr();
    bool validtName();
    bool validtAdmn();
};

#endif /* SURVEYENGINE_H */

