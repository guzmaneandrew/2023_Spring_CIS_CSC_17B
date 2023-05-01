/* 
 * File:   User.cpp
 * Author: andrewguzman
 *
 * Created on April 2, 2023, 8:45 PM
 */

#include "User.h"
#include "SurveyEngine.h"

User::User() {
    info.username=" ";
    info.password=" ";
    info.numSurveys=0;
    info.active=false;
}

void User::setInfo(string name,string password) {
    info.username=name;
    info.password=password;
    info.numSurveys=0;
    info.active=true;

    validateInfo();

    cout<<"User : "<<info.username<<endl;
}

void User::validateInfo() {
    fstream userDB("UserData.dat",ios::in|ios::app|ios::binary);
    UserInfo temp;
    bool write=1;

    userDB.seekg(ios::beg);
    while (userDB.read(reinterpret_cast<char *>(&temp),sizeof(temp))) {
        if (temp.username==info.username && temp.password!=info.password){
            string password;
            do{
                cout<<"Incorrect Password Try Again: ";
                cin>>password;
            }while(password!=temp.password);
            info=temp;
            write=0;
        }else if(temp.username==info.username && temp.password==info.password) {
            info=temp;
            write=0;
        }
    }

    userDB.clear();

    if(write){
        writeInfo(userDB,info);
    }
}

void User::writeInfo(fstream &userDB,UserInfo info){
    userDB.write(reinterpret_cast<char *>(&info),sizeof(info));
    
    char tempUsernameLength=0; // User's username length 
    char tempPasswordLength=0; // User's password length

    tempUsernameLength=info.username.size();
    tempPasswordLength=info.password.size();
    
    userDB.seekp(ios::app);
    // Write username, password, and admin status to the binary file
    userDB.write(&tempUsernameLength,sizeof(char));
    userDB.write(info.username.c_str(),tempUsernameLength);
    userDB.write(&tempPasswordLength, sizeof (char));
    userDB.write(info.password.c_str(), tempPasswordLength);
    userDB.write(reinterpret_cast<char*>(&info.numSurveys),
            sizeof(int));
    userDB.write(reinterpret_cast<char*>(&info.active),
            sizeof(bool));
}


void User::displayInfo() {
    cout<<"Username : "<<info.username<<endl;
    cout<<"Password: "<<info.password<<endl;
}