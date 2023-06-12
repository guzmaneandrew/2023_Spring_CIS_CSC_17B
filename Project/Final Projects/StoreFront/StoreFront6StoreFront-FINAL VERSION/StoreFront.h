/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   StoreFront.h
 * Author: andrewguzman
 *
 * Created on May 5, 2023, 9:56 PM
 */

#ifndef STOREFRONT_H
#define STOREFRONT_H

class StoreFront {
private:
    bool isActive;
    bool isAdmin;
    bool loggedIn;
    string username;
    string password;
public:

    StoreFront();

    void mainMenu();
    
    void login();

    void regUsr();

    bool validtUsr();

    bool validtName();

    bool validtAdmn();

};

#endif /* STOREFRONT_H */

