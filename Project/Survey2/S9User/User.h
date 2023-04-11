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
            cout << " 4) " << endl;
            cout << " 5) View a Survey" << endl;
            cout << " 6) " << endl;
            cout << " 7) View Account Information" << endl;
            cout << " 8) " << endl;
            cout << "99) " << endl;
            cout << "-1 ) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                completeSrv();
            } else if (choice == 2) {
                listSrvs();
            } else if (choice == 3) {
                listCompSrvs();
            } else if (choice == 4) {

            } else if (choice == 5) {
                prntSrv();
            } else if (choice == 6) {
                updtSrv();
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
    }

    void updtUsrInfo() {
        listUsrInfo();

        //Change password and add to binary file 

    }

    void listUsrInfo() {
        fstream userDB("UserInfo.dat", ios::in | ios::app | ios::binary);
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

    void completeSrv() {
        cout << "COMPLETE SURVEY" << endl;
        int survNum, indx, validNum;

        //List all surveys
        listSrvs();

        validNum = surveys.size();

        //Indicate which survey to view
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

    }

    void listSrvs() {
        readFromBin();

        cout << endl << "ALL SURVEYS" << endl;
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

    void listCompSrvs() {
        //        bool none = true;
        //        readFromBin();
        //
        //        cout << endl << "COMPLETEDS SURVEYS" << endl;
        //        if (surveys.size() == 0) {
        //            cout << "No Surveys To Retrieve from the Database." << endl;
        //        } else {
        //            cout << left;
        //            cout << setw(50) << "Title" << right << setw(12) << "Active" << endl;
        //            for (int i = 0; i < surveys.size(); i++) {
        //                if (surveys[i]->getStatus() == true) {
        //                    cout << i + 1 << ") ";
        //                    cout << left << setw(50) << surveys[i]->getTitle() << "\t"
        //                            << boolalpha << surveys[i]->getStatus() << endl;
        //                    none = false;
        //                }
        //            }
        //            if (none == true) {
        //                cout << right << setw(15) << "- - - - - - None - - - - - -" << endl;
        //            }
        //        }
    }

    void prntSrv() {
        int survNum, indx, validNum;

        //List all surveys
        listSrvs();

        validNum = surveys.size();

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

    void updtSrv() {
        Survey *surv2updt;
        int survNum, indx, choice, validNum;

        validNum = surveys.size();

        cout << endl << "UPDATE SURVEY" << endl;

        //List all surveys
        listSrvs();

        //Indicate which to delete
        do {
            cout << "Enter Number of Survey to Update: ";
            cin>>survNum;
            cin.ignore();
            if (survNum <= 0 || survNum > validNum) {
                cout << "Invalid Survey Number. Enter 1 - " << validNum << "." << endl;
            }
        } while (survNum <= 0 || survNum > validNum);


        indx = survNum - 1;
        surv2updt = surveys[indx];
        surveys[indx]->display();

        do {
            cout << "Enter What You Would Like to Update" << endl;
            cout << " 1) Title" << endl;
            cout << " 2) Status" << endl;
            cout << " 3) Questions/Responses Options" << endl;
            cout << " 4) Add Question" << endl;
            cout << " 5) Delete Question" << endl;
            cout << " 0) Cancel Survey Updates " << endl;

            cin>>choice;
            cin.ignore();
            switch (choice) {
                case 1:
                    cout << endl << "UPDATE TITLE" << endl;
                    updtTitle(surv2updt);
                    break;
                case 2:
                    cout << endl << "UPDATE STATUS" << endl;
                    updtStatus(surv2updt);
                    break;
                case 3:
                    cout << endl << "UPDATE QUESTIONS" << endl;
                    updtSrvQs(surv2updt);
                    break;
                case 4:
                    cout << endl << "ADD QUESTION" << endl;
                    addSrvQ(surv2updt);
                    break;
                case 5:
                    cout << endl << "DELETE QUESTION" << endl;
                    deleteQ(surv2updt);
                    break;
                case 0:
                    cout << endl << "CANCEL SURVEY UPDATES" << endl;
                    break;
                default:
                    cout << endl << "You picked an invalid option" << endl;
                    break;
            }
        } while (choice != 0);

        reloadSrvs();
    }

    void deleteAll() {
        string confirm1, confirm2;
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

    //    Helper Functions

    void addSrvQ(Survey *survey) {
        survey->addQ();
        survey->display();
    }

    void deleteQ(Survey *survey) {
        int numQ, indx, validNum;

        validNum = survey->getNumQs();

        do {
            cout << "Enter Number of Question to Delete: ";
            cin>>numQ;
            cin.ignore();
            if (numQ <= 0 || numQ > validNum) {
                cout << "Invalid Question Number. Enter 1 - " << validNum << endl;
            }
        } while (numQ <= 0 || numQ > validNum);


        indx = numQ - 1;
        survey->deleteQ(indx);
        survey->display();
    }

    void updtTitle(Survey *survey) {
        char newTitle[TSIZE];
        cout << "Enter the New Title: ";
        cin.getline(newTitle, TSIZE);

        survey->setTitle(newTitle);
        survey->display();
    }

    void updtStatus(Survey *survey) {
        survey->setStatus(!survey->getStatus());
        survey->display();
    }

    void updtSrvQs(Survey *survey) {
        //Get questions vector for specific question
        vector<Question *> qs = survey->getQs();
        int validIndx = qs.size();
        int numQ, indx, choice;

        do {
            cout << "Enter Number of Question To Update: ";
            cin>>numQ;
            cin.ignore();
            if (numQ <= 0 || numQ > validIndx) {
                cout << "Invalid Question Number. Enter 1 - " << validIndx << "." << endl;
            }
        } while (numQ < 0 || numQ > validIndx);

        indx = numQ - 1;
        cout << endl << "Question: ";
        qs[indx]->display(); //Print question for viewing

        do {
            cout << "Enter What You Would Like to Update" << endl;
            cout << " 1) Question" << endl;
            cout << " 2) Question Type" << endl;
            cout << " 3) Response Options" << endl;
            cout << " 0) Cancel Question/Response Options Updates" << endl;
            cin>>choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << endl << "UPDATE QUESTION" << endl;
                    updtQ(survey->getQ(numQ));
                    break;
                case 2:
                    cout << endl << "UPDATE QUESTION TYPE" << endl;
                    updtQType(survey->getQ(numQ));
                    break;
                case 3:
                    cout << endl << "UPDATE RESPONSE OPTIONS" << endl;
                    updtROpts(survey->getQ(numQ));
                    break;
                case 0:
                    cout << endl << "CANCEL QUESTION/RESPONSE OPTION UPDATES" << endl;
                    break;
                default:
                    cout << endl << "You picked an invalid option" << endl;
                    break;
            }
        } while (choice != 0);

        survey->display();

        reloadSrvs();
    }

    void updtQ(Question *q) {
        char newQ[QRSIZE];

        cout << "Enter New Question: ";
        cin.getline(newQ, QRSIZE);
        q->setQ(newQ);

        cout << endl << "Question: ";
        q->display();
    }

    void updtQType(Question *q) {
        int type;

        cout << "Enter Question Type (1=Single, 2=Multiple, 3=Write-In): ";
        cin>>type;
        cin.ignore();
        q->setType(type);

        cout << endl << "Question: ";
        q->display();
    }

    void updtROpts(Question *q) {
        vector<string> qResp = q->getRespOptions();

        int choice;

        //Display response options
        cout << "Response Options" << endl;
        for (int i = 0; i < qResp.size(); i++) {
            cout << i + 1 << ") " << qResp[i] << endl;
        }
        cout << endl;

        do {
            cout << "Enter What You Would Like to Update" << endl;
            cout << " 1) Update Response Option" << endl;
            cout << " 2) Add Response Option" << endl;
            cout << " 3) Delete Response Option" << endl;
            cout << " 0) Cancel Response Option Updates" << endl;
            cin>>choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << endl << "UPDATE RESPONSE OPTION" << endl;
                    updtROPt(q);
                    break;
                case 2:
                    cout << endl << "ADD RESPONSE OPTION" << endl;
                    addROpt(q);
                    break;
                case 3:
                    cout << endl << "DELETE RESPONSE OPTION" << endl;
                    deleteROpt(q);
                    break;
                case 0:
                    cout << endl << "CANCEL RESPONSE OPTION UPDATES" << endl;
                    break;
                default:
                    cout << endl << "You picked an invalid option" << endl;
                    break;
            }
        } while (choice != 0);

        cout << endl << "Question: ";
        q->display();

        reloadSrvs();
    }

    void updtROPt(Question *q) {
        int validIndx = q->getNumResp();
        string response;

        int numR, indx;

        do {
            cout << "Enter the Number of the Response To Update: ";
            cin>>numR;
            cin.ignore();
            if (numR <= 0 || numR > validIndx) {
                cout << "Invalid Response Number. Enter 1 - " << validIndx << "." << endl;
            }
        } while (numR < 0 || numR > validIndx);

        indx = numR - 1;
        q->setResp(indx);

        cout << endl << "Question: ";
        q->display();
    }

    void addROpt(Question *q) {
        q->addResp();

        cout << endl << "Question: ";
        q->display();
    }

    void deleteROpt(Question *q) {
        int numR, indx, validNum;

        validNum = q->getNumResp();

        do {
            cout << "Enter Response to Delete: ";
            cin>>numR;
            cin.ignore();
            if (numR <= 0 || numR > validNum) {
                cout << "Invalid Response Number. Enter 1 - " << validNum << endl;
            }
        } while (numR <= 0 || numR > validNum);

        indx = numR - 1;
        q->deleteROpt(indx);

        cout << endl << "Question: ";
        q->display();
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

    void clearBin() {
        //Deletes all contents of the binary file
        ofstream surveyDB("SurveyInfo.dat", ios::out | ios::trunc);
        surveyDB.close();
    }

    void reloadSrvs() {
        //Clear binary file, output vector surveys to binary, then write to bin
        clearBin();

        for (int i = 0; i < surveys.size(); i++) {
            surveys[i]->saveToBin();
        }

        readFromBin();
    }
};

#endif /* USER_H */

