/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Survey.h
 * Author: andrewguzman
 *
 * Created on April 5, 2023, 7:59 PM
 */

#ifndef SURVEY_H
#define SURVEY_H

#include "Headers.h"

//Structure Definitions

struct SurveyQInfo {
    char question[QRSIZE]; //Question
    QType type;         //Question type
    int numRespOptions; //Number of response options
    vector<string> respOptions; //Response options
    vector<string> responses;   //Responses
};

struct SurveyInfo {
    char title[TSIZE]; //Title of info
    int numQuestions; //Number of questions
    bool active; //Status of survey
    vector<SurveyQInfo> questions; //questions in Survey
};

class Survey {
private:
    SurveyInfo *info;
public:

    Survey() {
        info = new SurveyInfo; //Declare pointer to SurveyInfo object
        strcpy(info->title, " ");
        info->numQuestions = 0;
        info->active = false;
    }

    Survey(string title, int numQ) {
        info = new SurveyInfo; //Declare pointer to SurveyInfo object
        info->numQuestions = numQ;
        strcpy(info->title, title.c_str());
        info->active = true;

        //Allocate memory for the questions vector
        info->questions.resize(info->numQuestions);

        //Set information for every survey question
        for (int i = 0; i < info->numQuestions; i++) {
            string q;
            cout << endl;
            cout << "Enter Question (up to 100 char) " << i + 1 << ": ";
            //Read in the question
            getline(cin,q);
            strcpy(info->questions[i].question, q.c_str());

            //Read in number of respOptions
            do {
                cout << "Enter Number of Response Options (up to 10): ";
                cin >> info->questions[i].numRespOptions;
                cin.ignore();
            } while (info->questions[i].numRespOptions > RSIZE);

            //Allocate memory for the response options vector
            info->questions[i].respOptions.resize(info->questions[i].numRespOptions);

            //Read in respOptions
            for (int j = 0; j < info->questions[i].numRespOptions; j++) {
                string respOpt;
                cout << "Enter Response Option (up to 100 char) " << j + 1 << ": ";
                getline(cin,respOpt);
                info->questions[i].respOptions.push_back(respOpt);
            }
        }
    }

    ~Survey() {
        delete info;
    }

    //    Setters

    void setNumQuestions(int n) {
        info->numQuestions = n;
    }

    void setTitle(char title[]) {
        for (int i = 0; i < TSIZE; i++) {
            info->title[i] = title[i];
        }
    }

    void setQuestions(vector<SurveyQInfo> qs) {
        //Set information for every survey question
        for (int i = 0; i < info->numQuestions; i++) {
            cout << endl;
            cout << "Enter Question (up to 100 char) " << i + 1 << ": ";
            //Read in the question
            cin.getline(info->questions[i].question, QRSIZE);

            //Read in number of respOptions
            do {
                cout << "Enter Number of Responses (up to 10): ";
                cin >> info->questions[i].numRespOptions;
                cin.ignore();
            } while (info->questions[i].numRespOptions > RSIZE);

            //Read in respOptions
            for (int j = 0; j < info->questions[i].numRespOptions; j++) {
                char response[QRSIZE];
                cout << "Enter Response (up to 100 char) " << j + 1 << ": ";
                cin>>response;
                info->questions[i].respOptions.push_back(response);
            }
        }
    }

    void setQuestion(int index, char q[]) {
        for (int i = 0; i < QRSIZE; i++) {
            if (q[i] != '\0') {
                info->questions[index].question[i] = q[i];
            }
        }
    }

    void setStatus(bool status) {
        info->active = status;
    }

    //Getters

    int getNumQ() const {
        return info->numQuestions;
    }

    char *getTitle() const {
        return info->title;
    }

    vector<SurveyQInfo> getSurvQInfo() const {
        return info->questions;
    }

    bool getStatus() const {
        return info->active;
    }

    void display() {
        //Display survey
        cout << endl;
        cout << "Title: " << info->title << endl;
        cout << "Status: " << boolalpha << info->active << endl;
        for (int i = 0; i < info->numQuestions; i++) {
            cout << endl;
            cout << "Question " << i + 1 << ": " << info->questions[i].question << endl;
            for (int j = 0; j < info->questions[i].numRespOptions; j++) {
                cout << left;
                cout << setw(2) << j + 1 << ") ";
                cout << info->questions[i].respOptions[j] << endl;
            }
        }
    }

    void saveToBin() {
        fstream surveyDB("SurveyInfo.dat", ios::in | ios::app | ios::binary);
        surveyDB.seekp(ios::app);

        //Write the title - 50 bytes
        surveyDB.write(info->title, sizeof (info->title));

        // Write number of questions - 4 bytes
        surveyDB.write(reinterpret_cast<char*> (&info->numQuestions), sizeof (int));

        //Write status  - 1 byte
        surveyDB.write(reinterpret_cast<char*> (&info->active), sizeof (bool));

        // Write the survey questions vector
        for (int i = 0; i < info->numQuestions; i++) {
            // Write the question string    - 100 bytes
            surveyDB.write(info->questions[i].question, sizeof(info->questions[i].question));

            // Write the number of respOptions - 4 bytes
            surveyDB.write(reinterpret_cast<char*> (&info->questions[i].numRespOptions), sizeof (int));

            // Write the respOptions - numRespOptions * 100bytes
            for (int j = 0; j < info->questions[i].numRespOptions; j++) {
                surveyDB.write(info->questions[i].respOptions[j].c_str(), sizeof(info->questions[i].respOptions[j]));
            }
        }

        surveyDB.close();
    }

    void readFromBin(char *b) {
        ifstream surveyDB("SurveyInfo.dat", ios::binary);
        surveyDB.read(b, TSIZE);
    }

    //    void writeBinary() {
    //        ofstream surveyDB("SurveyData.dat", ios::binary|ios::app);
    //        if (!surveyDB) {
    //            cerr << "Error: unable to open file." << endl;
    //            return;
    //        }
    //
    //        // Write the survey title
    //        int titleLen = info->title.size();
    //        surveyDB.write(reinterpret_cast<char*> (&titleLen), sizeof (int));
    //        surveyDB.write(info->title.c_str(), titleLen);
    //
    //        // Write number of questions
    //        surveyDB.write(reinterpret_cast<char*> (&info->numQuestions), sizeof (int));
    //
    //        // Write the survey questions
    //        for (int i = 0; i < info->numQuestions; i++) {
    //            // Write the question string
    //            int questionLen = info->questions[i].question.size();
    //            surveyDB.write(reinterpret_cast<char*> (&questionLen), sizeof (int));
    //            surveyDB.write(info->questions[i].question.c_str(), questionLen);
    //
    //            // Write the number of respOptions
    //            surveyDB.write(reinterpret_cast<char*> (&info->questions[i].numRespOptions), sizeof (int));
    //
    //            // Write the respOptions
    //            for (int j = 0; j < info->questions[i].numRespOptions; j++) {
    //                int responseLen = info->questions[i].respOptions[j].size();
    //                surveyDB.write(reinterpret_cast<char*> (&responseLen), sizeof (int));
    //                surveyDB.write(info->questions[i].respOptions[j].c_str(), responseLen);
    //            }
    //        }
    //
    //        surveyDB.close();
    //    }
    //
    //    void readBinary() {
    //        ifstream surveyDB("SurveyData.dat", ios::binary);
    //        if (!surveyDB) {
    //            cerr << "Error: unable to open file." << endl;
    //            return;
    //        }
    //
    //        // Read the survey title
    //        int titleLen;
    //        surveyDB.read(reinterpret_cast<char*> (&titleLen), sizeof (int));
    //        char* titleCArr = new char[titleLen + 1];
    //        surveyDB.read(titleCArr, titleLen);
    //        titleCArr[titleLen] = '\0';
    //        string title(titleCArr);
    //        delete[] titleCArr;
    //
    //        // Read the number of questions
    //        int numQuestions;
    //        surveyDB.read(reinterpret_cast<char*> (&numQuestions), sizeof (int));
    //
    //        // Read the survey questions
    //        SurveyInfo* info = new SurveyInfo;
    //        info->title = title;
    //        info->numQuestions = numQuestions;
    //        info->questions.resize(numQuestions);
    //        for (int i = 0; i < numQuestions; i++) {
    //            // Read the question string
    //            int questionLen;
    //            surveyDB.read(reinterpret_cast<char*> (&questionLen), sizeof (int));
    //            char* qCArr = new char[questionLen + 1];
    //            surveyDB.read(qCArr, questionLen);
    //            qCArr[questionLen] = '\0';
    //            info->questions[i].question = qCArr;
    //            delete[] qCArr;
    //
    //            // Read the number of respOptions
    //            int numRespOptions;
    //            surveyDB.read(reinterpret_cast<char*> (&numRespOptions), sizeof (int));
    //            info->questions[i].numRespOptions = numRespOptions;
    //
    //            // Read the respOptions
    //            for (int j = 0; j < numRespOptions; j++) {
    //                int responseLen;
    //                surveyDB.read(reinterpret_cast<char*> (&responseLen), sizeof (int));
    //                char* respCArr = new char[responseLen + 1];
    //                surveyDB.read(respCArr, responseLen);
    //                respCArr[responseLen] = '\0';
    //                info->questions[i].respOptions[j] = respCArr;
    //                delete[] respCArr;
    //            }
    //        }
    //
    //        surveyDB.close();
    //
    //        // Create the Survey object
    //        Survey survey;
    //        survey.info = info;
    //
    //        // Display the survey
    //        survey.display();
    //    }
};

#endif /* SURVEY_H */

