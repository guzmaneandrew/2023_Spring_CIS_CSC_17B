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
            cout << " 2) List All Surveys" << endl;
            cout << " 3) List Active Surveys" << endl;
            cout << " 4) List Inactive Surveys" << endl;
            cout << " 5) View a Survey" << endl;
            cout << " 6) Update a Survey" << endl;
            cout << " 7) Delete All Surveys" << endl;
            cout << "-1 ) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                createSrv();
            } else if (choice == 2) {
                listAllSrv();
            } else if (choice == 3) {
                listActvSrv();
            } else if (choice == 4) {
                listInacSrv();
            } else if (choice == 5) {
                prntSrv();
            } else if (choice == 6) {
                updtSrv();
            } else if (choice == 7) {
                deleteAll();
            }

        } while (choice != -1);
    };

    void createSrv() {
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

    void listAllSrv() {
        readFromBin();

        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            for (int i = 0; i < surveys.size(); i++) {
                surveys[i]->display();
            }
            cout<<endl<<left;
            cout << setw(53) << "Title" << right << setw(8) << "Active" << endl;
            for (int i = 0; i < surveys.size(); i++) {
                cout << i + 1 << ") ";
                cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                            << boolalpha << surveys[i]->getStatus() << endl;
            }
        }
    }

    void listActvSrv() {
        bool none=true;
        readFromBin();

        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            cout << endl << left;
            cout << setw(53) << "Title" << right << setw(8) << "Active" << endl;
            for (int i = 0; i < surveys.size(); i++) {
                if (surveys[i]->getStatus() == true) {
                    cout << i + 1 << ") ";
                    cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                            << boolalpha << surveys[i]->getStatus() << endl;
                } else {
                    none =false;
                }
            }
            
            if(none==false) {
                cout<<right<<setw(15)<<"- - - - - - None - - - - - -"<<endl;
            }
        }
    }

    void listInacSrv() {
        readFromBin();

        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            cout << endl << left;
            cout << setw(53) << "Title" << right << setw(8) << "Active" << endl;
            for (int i = 0; i < surveys.size(); i++) {
                if (surveys[i]->getStatus() == false) {
                    cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                            << boolalpha << surveys[i]->getStatus() << endl;
                }
            }
        }
    }

    void prntSrv() {
        string title;
        bool found = false;
        //List all surveys
        listAllSrv();

        //Indicate which to delete by title
        cout << "Enter the Title of Survey to View: ";
        getline(cin, title);

        for (int i = 0; i < surveys.size(); i++) {
            if (surveys[i]->getTitle() == title) {
                surveys[i]->display();
                found = true;
            }
        }

        if (!found) cout << "Survey Not Found." << endl;
    }

    void updtSrv() {
        Survey *surv2updt;
        string title;
        bool found = false;
        //List all surveys
        listAllSrv();

        //Indicate which to delete by title
        cout << "Enter the Title of Survey to Update: ";
        getline(cin, title);
        //Go through surveys comparing titles
        for (int i = 0; i < surveys.size(); i++) {
            if (strcmp(title.c_str(), surveys[i]->getTitle()) == 0) {
                surv2updt = surveys[i];
                surveys[i]->display();
                found = true;
            }
        }

        if (!found) {
            cout << "Survey Not Found." << endl;
        } else {
            int choice;
            cout << endl << "Enter What You Would Like to Update"
                    << "(1 = Title \t 2 = Status \t 3 = Questions): ";
            cin>>choice;
            cin.ignore();
            switch (choice) {
                case 1:
                    cout << "Update Survey Title" << endl;
                    updtTitle(surv2updt);
                    break;
                case 2:
                    cout << "Update Survey Status" << endl;
                    updtStatus(surv2updt);
                    break;
                case 3:
                    cout << "Update Survey Questions" << endl;
                    updtQs(surv2updt);
                    break;
                default:
                    cout << "You picked an invalid option" << endl;

                    break;
            }
        }
    }

    void updtTitle(Survey *survey) {
        char newTitle[TSIZE];
        cout << "Enter the New Title: ";
        cin.getline(newTitle, TSIZE);

        survey->setTitle(newTitle);
        survey->display();

        clearBin();

        for (int i = 0; i < surveys.size(); i++) {
            surveys[i]->saveToBin();
        }

        readFromBin();
    }

    //STILL NEED TO DO
    void updtQs(Survey *survey) {
        //        //Get questions for specific question
        vector<Question *> qs = survey->getQs();
        vector<Question *> &qsCopy = qs;

        int numQ;

        cout << "Which Question Would You Like To Delete: " << endl;
        cin>>numQ;
        numQ--;
        cin.ignore();

        if (numQ >= 0 && numQ < qsCopy.size()) {
            delete qsCopy[numQ];
            qsCopy.erase(qsCopy.begin() + numQ);
        } else {
            cout<<"ERROR: Invalid Question Index."<<endl;
        }

        clearBin();

        for (int i = 0; i < surveys.size(); i++) {
            surveys[i]->saveToBin();
        }

        surveys.clear();
        readFromBin();

    }

    void updtStatus(Survey *survey) {
        survey->setStatus(!survey->getStatus());
        survey->display();

        clearBin();

        for (int i = 0; i < surveys.size(); i++) {
            surveys[i]->saveToBin();
        }

        readFromBin();
    }

    void readFromBin() {
        surveys.clear(); //Clear vector first to read entire file contents to it
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
            clearBin();
            surveys.clear();
            cout << endl << "All Surveys Have Been Deleted from the Database..." << endl;
        }
    }

    void clearBin() {
        //Deletes all contents of the binary file
        ofstream surveyDB("SurveyInfo.dat", ios::out | ios::trunc);
        surveyDB.close();
    }
};

#endif /* ADMIN_H */

