/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: andrewguzman
 *
 * Created on April 3, 2023, 8:27 PM
 */

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
//    Setters 
    void setInfo(string,string);            //Constructor
    void validateInfo();                    //Validate user 
    void writeInfo(fstream &,UserInfo);     //Write userinfo to DB
//    Getters
    void displayInfo();                    //Display all user 
};


#endif /* USER_H */

