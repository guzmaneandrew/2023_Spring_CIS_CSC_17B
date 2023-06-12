/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: andrewguzman
 *
 * Created on May 2, 2023, 11:32 AM
 */

#ifndef USER_H
#define USER_H

#include "Cart.h"

struct UserInfo {
    char username[11];
    char password[13];
    bool status;
};

class User {
private:
    UserInfo info;
    Store *store;
    Cart *cart;
    string usrCartFile;
public:

    User();

    void prompt();

    void setUsrInfo(string, string);

    void listItms();

    void listItmsInStck();

    void listItmsNotInStck();

    void listItmsInCart();

    void addItems();

    void readStoreBin(string);
    
    void readCartBin(string);

    void clearBin(string);

    void reloadItms(string);
};

#endif /* USER_H */

