/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Admin.h
 * Author: andrewguzman
 *
 * Created on April 18, 2023, 2:08 PM
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
    Store *store;
public:
    Admin(string, string);

    ~Admin();

    void addItems();

    void listItms();

    void listItmsInStck();

    void listItmsNotInStck();

    void updtItem();

    void updtName(Item *);

    void updtPrice(Item *);

    void updtNumStk(Item *);

    void addAdmin();

    void listUsrs();

    void listAdmins();

    void deleteAll();

    void saveBin(string);
    
    void readBin(string);

    void clearBin(string);

    void reloadItms(string);
};

#endif /* ADMIN_H */