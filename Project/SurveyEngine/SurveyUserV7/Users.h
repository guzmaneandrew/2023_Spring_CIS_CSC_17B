/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Users.h
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 7:36 PM
 */

#ifndef USERS_H
#define USERS_H

struct UserInfo {
    string username;
    string password;
};

struct Users {
    int numUsers;       //number of users
    UserInfo *users;    //Structure within a structure
};

#endif /* USERS_H */

