/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: andrewguzman
 *
 * Created on April 11, 2023, 12:49 PM
 */

#ifndef USER_H
#define USER_H

#include "Survey.h"

struct UserInfo {
    char username[11];
    char password[13];
    bool status;
};

class User {
private:
    UserInfo info;
    vector<Survey *> surveys; //All available surveys
    vector<Survey *> userSrvs; //Surveys completed by user
    vector<string> responses; //User responses to surveys
    string usrSrvFile; //name of user surveys file
    string usrRespFile; //name of user responses file
public:
    User();
    void prompt();
    void setUsrInfo(string,string);
    void completeSrv();
    void answerQ(int, Question *);
    void singleResp(int, Question *);
    void multResp(int, Question *);
    void wrtInResp(int, Question *);
    vector<string> strSplit(string);
    void deleteAll();
    void updtUsrMenu();
    void updtPass();
    void deactvtAcc();
    void listUsrInfo();
    void listSrvs(string);
    bool chkComplete(Survey *);
    void listCompSrvs(string);
    void prntSrvs(string);
    void prntUsrSrvs();
    void prntResp(Survey *, int);
    int findRespIndx(Survey *, int);
    void wrtRespBin();
    void readRespBin();
    void reloadResp();
    void readFromBin(string, vector<Survey *>&);
    void reloadSrvs(string, vector<Survey *>);
    void clearBin(string);
};

#endif /* USER_H */

