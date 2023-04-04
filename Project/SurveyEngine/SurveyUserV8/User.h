/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 7:36 PM
 */
#include "SurveyEngine.h"

#ifndef USER_H
#define USER_H



struct UserInfo {
    string username;
    string password;
    int numSurveys;
    bool active;
};

class User {
private:
    UserInfo info;
public:
    User();                                 //Default constructor
    void setInfo(string,string);            //Constructor
    void validateInfo();                    //Validate user 
    void writeInfo(fstream &,UserInfo);     //Write userinfo to DB
    void displayInfo();                    //Display user 
};

#endif /* USERS_H */

