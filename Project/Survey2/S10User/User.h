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
    string usrSrvFile; //name of user surveys file
    string usrRespFile; //name of user responses file
public:

    User() {
        strcpy(info.username, " ");
        strcpy(info.password, " ");
    }

    void prompt() {
        int choice;
        do {
            cout << endl << "Welcome, " << info.username << endl;
            cout << " 1) Complete Survey" << endl;
            cout << " 2) List Available Surveys" << endl;
            cout << " 3) List Completed Surveys" << endl;
            cout << " 4) View an Available Survey" << endl;
            cout << " 5) View a Completed Survey" << endl;
            cout << " 6) " << endl;
            cout << " 7) View Account Information" << endl;
            cout << " 8) " << endl;
            cout << "99) Delete All" << endl;
            cout << "-1) Logout" << endl;
            cin>>choice;
            cin.ignore();
            if (choice == 1) {
                completeSrv();
            } else if (choice == 2) {
                listSrvs("SurveyInfo.dat");
            } else if (choice == 3) {
                listCompSrvs(usrSrvFile);
            } else if (choice == 4) {
                prntSrvs("SurveyInfo.dat");
            } else if (choice == 5) {
                prntUsrSrvs();
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
        usrSrvFile = string(info.username) + "Surveys.dat";
        usrRespFile = string(info.username) + "Resp.dat";
    }

    void completeSrv() {
        int survNum = 0, indx = 0, validNum = 0;
        bool completed = false; //flag to indicate whether survey is completed

        //List all surveys, also reads surveys from binary
        listSrvs("SurveyInfo.dat");
        //Read completed surveys and responses from binary
        readFromBin(usrSrvFile, userSrvs);
        readRespBin();

        //Prompt to select a survey to complete if there are surveys to complete
        if (surveys.size() != 0) {
            validNum = surveys.size(); //Check input is within bounds
            do {
                cout << "Enter the Number of the Survey to Complete: ";
                cin>>survNum;
                cin.ignore();
                if (survNum <= 0 || survNum > validNum) {
                    cout << "Invalid Survey Number. Enter 1 - " << validNum << endl;
                }
            } while (survNum <= 0 || survNum > validNum);

            indx = survNum - 1;

            //Check that the selected survey hasn't already been completed
            if (userSrvs.size() != 0 || completed == false) {
                for (int i = 0; i < userSrvs.size(); i++) {
                    if (strcmp(surveys[indx]->getTitle(), userSrvs[i]->getTitle()) == 0) {
                        completed = true;
                    }
                }

                if (completed == false) {
                    surveys[indx]->display();
                    cout << "COMPLETE SURVEY" << endl;
                    //Prompt for responses to every question in survey
                    for (int i = 0; i < surveys[indx]->getNumQs(); i++) {
                        cout << "Question " << i + 1 << endl;
                        answerQ(i, surveys[indx]->getQs()[i]);
                        cout<<endl;
                    }
                    //Save selected survey and new responses to binary
                    userSrvs.push_back(surveys[indx]);
                    surveys[indx]->saveToBin(usrSrvFile);
                    reloadResp();
                } else {
                    cout << "You've Already Completed This Survey." << endl;
                }
            }
        }
    }

    void answerQ(int i, Question *q) {
        //Prompt for response, varies based on type of question
        if (q->getType() == SINGLE) {
            singleResp(i, q);
        } else if (q->getType() == MULTIPLE) {
            multResp(i, q);
        } else if (q->getType() == WRITEIN) {
            wrtInResp(i, q);
        }
    }

    void singleResp(int i, Question *q) {
        string response;

        cout << "Enter Single Response: ";
        getline(cin, response);

        //Validate that response is a valid option
        if (isdigit(response[0]) && (stoi(response) >= 1) && (stoi(response) <= q->getNumResp())) {
            cout << "You entered: " << response << endl;
            responses.push_back(response);
        } else {
            cout << "Invalid Input. Enter 1 - " << q->getNumResp() << endl;
            singleResp(i, q);
        }
    }

    void multResp(int i, Question *q) {
        string usrResps;
        vector<string> listResp;
        bool validInput = true;

        cout << "Enter Multiple Responses (separated by commas): ";
        getline(cin, usrResps);

        // Split the input and store into a vector of strings
        listResp = strSplit(usrResps);

        // Validate that each response is a valid option
        for (int i = 0; i < listResp.size(); i++) {
            if (!isdigit(listResp[i][0]) || (stoi(listResp[i]) < 1) || (stoi(listResp[i]) > q->getNumResp())) {
                validInput = false;
                break;
            }
        }

        // If input is valid, add to the vector of all responses, else prompt again
        if (validInput) {
            cout << "You Entered: " << usrResps << endl;
            responses.push_back(usrResps);
            cout << endl;
        } else {
            cout << "Invalid Input. Enter 1 - " << q->getNumResp() << endl;
            multResp(i, q);
        }
    }

    void wrtInResp(int i, Question *q) {
        string writeInResp, usrResps;
        vector<string> listResp;
        bool validInput = true;
        int sizeList;

        cout << "To Enter a Write-In Response, Include the Last Number Below \n";
        cout << "Enter Multiple Responses (separated by commas): ";
        getline(cin, usrResps);

        // Split the input and store into a vector of strings
        listResp = strSplit(usrResps);
        sizeList = listResp.size();

        // Validate that each response is a valid option
        for (int i = 0; i < sizeList; i++) {
            if (!isdigit(listResp[i][0]) || (stoi(listResp[i]) < 1) || (stoi(listResp[i]) > q->getNumResp())) {
                validInput = false;
                break;
            }
        }

        // If input is valid, add to the vector of all responses, else prompt again
        if (validInput) {
            cout << "You Entered: " << usrResps << endl;
            //Prompt the user to enter a write-in response if they selected the last option
            if (stoi(listResp[sizeList - 1]) == q->getNumResp()) {
                cout << "Enter Write-In Response: ";
                getline(cin, writeInResp);
                usrResps += "," + writeInResp;
                responses.push_back(usrResps);
            }
        } else {
            cout << "Invalid Input. Enter 1 - " << q->getNumResp() << endl;
            wrtInResp(i, q);
        }
    }

    vector<string> strSplit(string s) {
        vector<string> list;
        stringstream ss(s);
        string substr;

        // Read and split a string into substrings with delimiter, add to vector
        while (getline(ss, substr, ',')) {
            list.push_back(substr);
        }

        return list;
    }

    void deleteAll() {
        //Only used for testing
        clearBin(usrSrvFile);
        userSrvs.clear();
        clearBin(usrRespFile);
        responses.clear();
        cout << endl << "All Surveys and Responses Have Been Deleted from the Database..." << endl;
    }

    void updtUsrInfo() {
        listUsrInfo();

        //Change password and add to binary file 

    }

    void listUsrInfo() {
        fstream userDB(string(info.username) + ".dat", ios::in | ios::app | ios::binary);
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

    void listSrvs(string srvDBfile) {
        readFromBin(usrSrvFile, userSrvs);
        readFromBin(srvDBfile, surveys);

        cout << endl << "AVAILABLE SURVEYS" << endl;
        if (surveys.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            cout << left;
            cout << setw(50) << "Title" << right << setw(12) << "Completed" << endl;
            for (int i = 0; i < surveys.size(); i++) {
                cout << i + 1 << ") ";
                cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                        << boolalpha << chkComplete(surveys[i]) << endl;
            }
        }
        cout << endl;
    }

    bool chkComplete(Survey *srv) {
        bool complete;

        for (int i = 0; i < userSrvs.size(); i++) {
            if (strcmp(srv->getTitle(), userSrvs[i]->getTitle()) == 0) {
                return true;
            }
        }
        return false;
    }

    void listCompSrvs(string file) {
        bool none = true;
        readFromBin(file, userSrvs);

        cout << endl << "COMPLETED SURVEYS" << endl;
        if (userSrvs.size() == 0) {
            cout << "No Surveys To Retrieve from the Database." << endl;
        } else {
            cout << left;
            cout << setw(50) << "Title" << endl;
            for (int i = 0; i < userSrvs.size(); i++) {
                if (userSrvs[i]->getStatus() == true) {
                    cout << i + 1 << ") ";
                    cout << left << setw(50) << userSrvs[i]->getTitle() << endl;
                    none = false;
                }
            }
            if (none == true) {
                cout << right << setw(15) << "- - - - - - None - - - - - -" << endl;
            }
        }
    }

    void prntSrvs(string srvDBfile) {
        int survNum = 0, indx = 0, validNum = 0;

        //Read surveys from binary file
        readFromBin(srvDBfile, surveys);
        listSrvs(srvDBfile);
        validNum = surveys.size();

        if (surveys.size() != 0) { //Ensure input for survey is within bounds
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

    void prntUsrSrvs() {
        int survNum = 0, indx = 0, validNum = 0;

        //Read surveys and responses from binary file
        readFromBin(usrSrvFile, userSrvs);
        listCompSrvs(usrSrvFile);
        readRespBin();
        validNum = userSrvs.size();

        if (userSrvs.size() != 0) { //Ensure input for survey is within bounds
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
            cout << "VIEW COMPLETED SURVEY" << endl;
            userSrvs[indx]->display();
            prntResp(userSrvs[indx], indx);
        }
    }

    void prntResp(Survey *srv, int srvIndx) {
        int i = 0, startIndx = 0, finalIndx = 0, qIndx = 1;

        //Find start and end index of responses for a given survey in responses vector
        startIndx = findRespIndx(srv, srvIndx);
        i = startIndx;
        finalIndx = startIndx + srv->getNumQs() - 1;

        cout << "Your Responses" << endl;
        do {
            cout << "Q" << qIndx << ": ";
            cout << responses[i] << endl;
            i++;
            qIndx++;
        } while (i <= finalIndx);
    }

    int findRespIndx(Survey *srv, int srvIndx) {
        int numQs = 0;

        //Calculate starting index by counting number of questions of surveys before
        for (int i = 0; i < srvIndx; i++) {
            numQs += userSrvs[i]->getNumQs();
        }

        return numQs;
    }

    void wrtRespBin() {
        fstream respDB(usrRespFile, ios::out | ios::binary | ios::app);

        if (!respDB) {
            cerr << "Error: Unable to Open File for Writing." << endl;
            return;
        }
        for (int i = 0; i < responses.size(); i++) {
            int len = responses[i].length();
            respDB.write(reinterpret_cast<char *> (&len), sizeof (int));
            respDB.write(responses[i].c_str(), len);
        }
        respDB.close();
    }

    void readRespBin() {
        responses.clear(); //Clear vector first to read entire file contents to it
        fstream respDB(usrRespFile, ios::in | ios::binary);
        if (!respDB) {
            return;
        }

        //Use cursor to get size of file to read entire file
        respDB.seekg(0, ios::end);
        int size = respDB.tellg();
        respDB.seekg(0, ios::beg);

        //Read in responses until cursor reaches the size of the file
        while (respDB.tellg() < size) {
            int len;
            string response;
            respDB.read(reinterpret_cast<char*> (&len), sizeof (int));
            response.resize(len);
            respDB.read(&response[0], len);
            responses.push_back(response);
        }
        respDB.close();
    }

    void reloadResp() {
        //Clear binary file, output vector surveys to binary, then write to bin
        clearBin(usrRespFile);

        wrtRespBin();

        readRespBin();
    }

    void readFromBin(string file, vector<Survey *>& srvs) {
        srvs.clear(); //Clear vector first to read entire file contents to it
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
            srvs.push_back(survey);
        }
        surveyDB.close();
    }

    void reloadSrvs(string file, vector<Survey *> srvs) {
        //Clear binary file, output vector surveys to binary, then write to bin
        clearBin(file);

        for (int i = 0; i < srvs.size(); i++) {
            srvs[i]->saveToBin(file);
        }

        readFromBin(file, srvs);
    }

    void clearBin(string file) {
        //Deletes all contents of the binary file
        ofstream DB(file, ios::out | ios::trunc);
        DB.close();
    }

};

#endif /* USER_H */

