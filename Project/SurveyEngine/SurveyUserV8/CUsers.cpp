/* 
 * File:   CUsers.cpp
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 7:54 PM
 */

#include <iostream>     //I/O Library
#include <cstdlib>      //Random Number Generator, Setting Seed, etc...
#include <iomanip>      //Formatting Library
using namespace std;    //Libraries compiled under std

#include "CUsers.h"

CUsers::CUsers() {
    usersDB=new Users;
    
    cout<<"Enter Number of Users: ";
    cin>>usersDB->numUsers;
    
    usersDB->users=new UserInfo[usersDB->numUsers];
    
    for(int i=0;i<usersDB->numUsers;i++) {
        cout<<left;
        cout<<endl<<"User "<<i+1<<" Information"<<endl;
        cout<<"Enter Username: ";
        cin>>usersDB->users[i].username;
        cin.ignore();
        cout<<"Enter Password: ";
        cin>>usersDB->users[i].password;
    }
    cout<<endl;
}

CUsers::~CUsers() {
    delete []usersDB;
}

void CUsers::display() {
    cout<<"User Information"<<endl;
    for(int i=0;i<usersDB->numUsers;i++) {
        cout<<"User "<<i+1<<endl;
        cout<<"Username: "<<usersDB->users[i].username<<endl;
        cout<<"Password: "<<usersDB->users[i].password<<endl;  
        cout<<endl;
    }
    cout<<endl;
}