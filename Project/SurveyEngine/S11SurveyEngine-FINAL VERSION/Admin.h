/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Admin.h
 * Author: andrewguzman
 *
 * Created on April 9, 2023, 4:33 PM
 */

#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

struct AdminInfo {
    char username[10];
    char password[12];
};

class Admin {
private:
    AdminInfo info;
    vector<Survey *> surveys;
public:
    Admin(string, string);
    void listUsrs();
    void addAdmin();
    void listAdmins();
    void createSrv();
    void listAllSrv();
    void listActvSrv();
    void listInacSrv();
    void prntSrv();
    void updtSrv();
    void deleteAll();
    //    Helper Functions
    void addSrvQ(Survey *);
    void deleteQ(Survey *);
    void updtStatus(Survey *);
    void updtSrvQs(Survey *);
    void updtQ(Question *);
    void updtQType(Question *);
    void updtROpts(Question *);
    void updtROPt(Question *);
    void addROpt(Question *);
    void deleteROpt(Question *);
    void readFromBin(string);
    void clearBin(string);
    void reloadSrvs(string);
};

#endif /* ADMIN_H */

