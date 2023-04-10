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

#include "Survey.h"

struct AdminInfo {
    char username[10];
    char password[12];
};

class Admin {
private:
    vector<Survey *> surveys;
public:

    Admin() {
        int choice;
        do {
            cout << endl << "Welcome Admin" << endl;
            cout << " 1) Create New Survey" << endl;
            cout << " 2) Print All Surveys" << endl;
            cout << " 3) Delete All Surveys" << endl;
            cout << "-1 ) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                createSurv();
            } else if (choice == 2) {
                printSurvs();
            } else if (choice == 3) {
                deleteAll();
            }

        } while (choice != -1);
    };

    void createSurv() {
        char title[TSIZE];
        int numQs;
        cout << "CREATE NEW SURVEY" << endl;
        cout << "Enter Title: ";
        cin.getline(title, TSIZE);
        cout << "Enter Number of Questions: ";
        cin>>numQs;
        cin.ignore();
        Survey *surv = new Survey(title, numQs);
        surveys.push_back(surv);
        surv->saveToBin();
    }

    void printSurvs() {
        surveys.clear();
        readFromBin();
        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        }
        for (int i = 0; i < surveys.size(); i++) {
            cout << surveys.size() << endl;
            surveys[i]->display();
        }
    }

    void readFromBin() {
        fstream surveyDB("SurveyInfo.dat", ios::in | ios::binary);
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
            int numQs;
            surveyDB.read(reinterpret_cast<char *> (title), TSIZE);
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
            survey->setNumQs(numQs);
            survey->setQs(questions);
            surveys.push_back(survey);
        }
        surveyDB.close();
    }

    void deleteAll() {
        string confirm1, confirm2, confirm3;
        cout << "DANGER ZONE: DELETE ALL SURVEYS" << endl;
        cout << "This action will permanently delete all surveys in your database.\n";

        do {
            cout << "Press 'D' to Continue or 'X' to Cancel: ";
            cin>>confirm1;
            cin.ignore();
        } while (confirm1 != "D" && confirm1 != "X");

        do {
            if (confirm1 == "X" || confirm1 == "x") {
                break;
            }
            cout << endl << "There is no going back. Please be certain." << endl;
            cout << "To confirm, type 'admin password': ";
            getline(cin, confirm2);

            if (confirm2 != "admin password") {
                cout << "Did You Change Your Mind? (Y=yes or N=no): ";
                cin>>confirm2;
                cin.ignore();
                if (confirm2 == "Y" || confirm2 == "y") {
                    break;
                } else {
                    cout << "Try Again." << endl;
                }
            }
        } while (confirm2 != "admin password");

        if (confirm2 == "admin password" && confirm1 == "D") {
            ofstream surveyDB("SurveyInfo.dat", ios::out | ios::trunc);
            surveyDB.close();
            surveys.clear();
            cout << endl << "All Surveys Have Been Deleted from the Database..." << endl;
        }
    }

};

#endif /* ADMIN_H */

