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
    char username[10];
    char password[12];
};

class User {
private:
    UserInfo info;
    vector<Survey *> surveys; //All available surveys
    vector<Survey *> userSrvs; //Surveys completed by user
    vector<string> responses; //User responses to surveys
    string usrFile; //name of user file
public:

    User() {
        strcpy(info.username, " ");
        strcpy(info.password, " ");
    }

    void prompt() {
        int choice;
        do {
            cout << endl << "Welcome, " << info.username << endl;
            cout << " 1) IP Complete Survey" << endl;
            cout << " 2) List Available Surveys" << endl;
            cout << " 3) List Completed Surveys" << endl;
            cout << " 4) View an Available Survey" << endl;
            cout << " 5) View a Completed Survey" << endl;
            cout << " 6) " << endl;
            cout << " 7) View Account Information" << endl;
            cout << " 8) " << endl;
            cout << "99) " << endl;
            cout << "-1 ) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                completeSrv(usrFile + "Surveys.dat");
            } else if (choice == 2) {
                listSrvs("SurveyInfo.dat");
            } else if (choice == 3) {
                listCompSrvs(usrFile + "Surveys.dat");
            } else if (choice == 4) {
                prntSrvs("SurveyInfo.dat",surveys);
            } else if (choice == 5) {
                prntSrvs(usrFile + "Surveys.dat",userSrvs);
            } else if (choice == 6) {
                
            } else if (choice == 7) {
                updtUsrInfo();
            } else if (choice == 8) {
                listUsrInfo();
            } else if (choice == 99) {
                deleteAll();
            }

        } while (choice != -1);
    }

    void setUsrInfo(string name, string pass) {
        strcpy(info.username, name.c_str());
        strcpy(info.password, pass.c_str());
        usrFile = info.username;
    }

    void completeSrv(string file) {
        cout << "COMPLETE SURVEY" << endl;
        int survNum, indx, validNum;

        //List all surveys
        listSrvs("SurveyInfo.dat");
        validNum = surveys.size();

        //Prompt to select a survey to complete if there are surveys to complete
        if (surveys.size() != 0) {
            do {
                cout << "Enter the Number of the Survey to Complete: ";
                cin>>survNum;
                cin.ignore();
                if (survNum <= 0 || survNum > validNum) {
                    cout << "Invalid Survey Number. Enter 1 - " << validNum << endl;
                }
            } while (survNum <= 0 || survNum > validNum);

            indx = survNum - 1;
            cout << "COMPLETE SURVEY" << endl;
            userSrvs.push_back(surveys[indx]);
            surveys[indx]->saveToBin(file);
            surveys[indx]->display();
        }
    }

    void updtUsrInfo() {
        listUsrInfo();

        //Change password and add to binary file 

    }

    void listUsrInfo() {
        fstream userDB(usrFile + ".dat", ios::in | ios::app | ios::binary);
        UserInfo temp;

        cout << endl << "Username \t Password" << endl << endl;
        userDB.seekg(ios::beg);
        while (userDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
            //            cout<<"temp"<<temp.username<<endl;
            //            cout<<"info"<<info.username<<endl;
            if (strcmp(temp.username, info.username) == 0) {
                cout << left << setw(17);
                cout << temp.username << setw(17) << temp.password << endl;
            }
        }
        userDB.close();
    }

    void listSrvs(string file) {
        readFromBin(file);

        cout << endl << "AVAILABLE SURVEYS" << endl;
        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            cout << left;
            cout << setw(50) << "Title" << right << setw(12) << "Completed" << endl;
            for (int i = 0; i < surveys.size(); i++) {
                cout << i + 1 << ") ";
                cout << left << setw(50) << surveys[i]->getTitle() << endl;
            }
        }
        cout << endl;
    }

    void listCompSrvs(string file) {
        bool none = true;
        readFromBin(file);

        cout << endl << "COMPLETEDS SURVEYS" << endl;
        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            cout << left;
            cout << setw(50) << "Title" << right << setw(12) << "Active" << endl;
            for (int i = 0; i < surveys.size(); i++) {
                if (surveys[i]->getStatus() == true) {
                    cout << i + 1 << ") ";
                    cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                            << boolalpha << surveys[i]->getStatus() << endl;
                    none = false;
                }
            }
            if (none == true) {
                cout << right << setw(15) << "- - - - - - None - - - - - -" << endl;
            }
        }
    }

    void prntSrvs(string file,vector<Survey *> srvs) {
        int survNum, indx, validNum;

        //List all surveys
        listSrvs(file);
        validNum = srvs.size();

        if(srvs.size() != 0) {
            //Indicate which survey to view
            do {
                cout << "Enter the Number of the Survey to View: ";
                cin>>survNum;
                cin.ignore();
                if (survNum <= 0 || survNum > validNum) {
                    cout << "Invalid Survey Number. Enter 1 - " << validNum << endl;
                }
            } while (survNum <= 0 || survNum > validNum);

            indx = survNum - 1;

            cout << "VIEW SURVEY" << endl;
            surveys[indx]->display();      
        }
    }

    void deleteAll() {

    }

    //    Helper Functions

    void readFromBin(string file) {
        surveys.clear(); //Clear vector first to read entire file contents to it
        fstream surveyDB(file, ios::in | ios::binary);
        if (!surveyDB) {
            cerr << "ERROR: Unable to Open File for Reading." << endl;
            return;
        }

        //Use cursor to get size of file to read entire file
        surveyDB.seekg(0, ios::end);
        int size = surveyDB.tellg();
        surveyDB.seekg(0, ios::beg);

        //Read in Survey information until cursor reaches the size of the file
        while (surveyDB.tellg() < size) {
            //Read title and number of questions from binary file
            char title[TSIZE];
            bool status;
            int numQs;
            surveyDB.read(reinterpret_cast<char *> (title), TSIZE);
            surveyDB.read(reinterpret_cast<char *> (&status), sizeof (bool));
            surveyDB.read(reinterpret_cast<char *> (&numQs), sizeof (int));
            vector<Question *> questions;
            //Loop through each question in the binary file and read
            for (int i = 0; i < numQs; i++) {
                char q[QRSIZE];
                int type, numResp;
                vector<string> options;

                surveyDB.read(reinterpret_cast<char *> (q), sizeof (q));
                surveyDB.read(reinterpret_cast<char *> (&type), sizeof (int));
                surveyDB.read(reinterpret_cast<char *> (&numResp), sizeof (int));
                //Loop through each response option in the binary file and read
                for (int j = 0; j < numResp; j++) {

                    int len;
                    string option;
                    surveyDB.read(reinterpret_cast<char *> (&len), sizeof (int));
                    option.resize(len);
                    surveyDB.read(&option[0], len);
                    options.push_back(option);
                }

                // Create new Question object and set its properties
                Question *newQ = new Question();
                newQ->setQ(q);
                newQ->setType(type);
                newQ->setNumResp(numResp);
                newQ->setRespOptions(options);
                questions.push_back(newQ);
            }

            //Create new Survey object,set properties, and add it to vector
            Survey *survey = new Survey();
            survey->setTitle(title);
            survey->setStatus(status);
            survey->setNumQs(numQs);
            survey->setQs(questions);
            surveys.push_back(survey);
        }
        surveyDB.close();
    }

    void clearBin(string file) {
        //Deletes all contents of the binary file
        ofstream surveyDB(file, ios::out | ios::trunc);
        surveyDB.close();
    }

    void reloadSrvs(string file) {
        //Clear binary file, output vector surveys to binary, then write to bin
        clearBin(file);

        for (int i = 0; i < surveys.size(); i++) {
            surveys[i]->saveToBin(file);
        }

        readFromBin(file);
    }
};

#endif /* USER_H */

