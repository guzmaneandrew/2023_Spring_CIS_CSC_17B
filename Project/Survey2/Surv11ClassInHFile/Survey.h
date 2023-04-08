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
    QType type; //Question type
    char respOpt1[QRSIZE]; //Response option 1
    char respOpt2[QRSIZE]; //Response option 2
    char respOpt3[QRSIZE]; //Response option 3
    char respOpt4[QRSIZE]; //Response option 4
    char respOpt5[QRSIZE]; //Response option 5
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
            getline(cin, q);
            strcpy(info->questions[i].question, q.c_str());

            //Read in each response option
            string respOpt1;
            cout << "Enter Response Option 1 (up to 100 char): ";
            getline(cin, respOpt1);
            strcpy(info->questions[i].respOpt1, respOpt1.c_str());

            string respOpt2;
            cout << "Enter Response Option 2 (up to 100 char): ";
            getline(cin, respOpt2);
            strcpy(info->questions[i].respOpt2, respOpt2.c_str());

            string respOpt3;
            cout << "Enter Response Option 3 (up to 100 char): ";
            getline(cin, respOpt3);
            strcpy(info->questions[i].respOpt3, respOpt3.c_str());

            string respOpt4;
            cout << "Enter Response Option 4 (up to 100 char): ";
            getline(cin, respOpt4);
            strcpy(info->questions[i].respOpt4, respOpt4.c_str());

            string respOpt5;
            cout << "Enter Response Option 5 (up to 100 char): ";
            getline(cin, respOpt5);
            strcpy(info->questions[i].respOpt5, respOpt5.c_str());
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

            //Read in each response option
            string respOpt1;
            cout << "Enter Response Option 1 (up to 100 char): ";
            getline(cin, respOpt1);
            strcpy(info->questions[i].respOpt1, respOpt1.c_str());

            string respOpt2;
            cout << "Enter Response Option 2 (up to 100 char): ";
            getline(cin, respOpt2);
            strcpy(info->questions[i].respOpt2, respOpt2.c_str());

            string respOpt3;
            cout << "Enter Response Option 3 (up to 100 char): ";
            getline(cin, respOpt3);
            strcpy(info->questions[i].respOpt3, respOpt3.c_str());

            string respOpt4;
            cout << "Enter Response Option 4 (up to 100 char): ";
            getline(cin, respOpt4);
            strcpy(info->questions[i].respOpt4, respOpt4.c_str());

            string respOpt5;
            cout << "Enter Response Option 5 (up to 100 char): ";
            getline(cin, respOpt5);
            strcpy(info->questions[i].respOpt5, respOpt5.c_str());
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
            cout << left;
            cout << setw(2) << 1 << ") ";
            cout << info->questions[i].respOpt1 << endl;

            cout << left;
            cout << setw(2) << 2 << ") ";
            cout << info->questions[i].respOpt2 << endl;

            cout << left;
            cout << setw(2) << 3 << ") ";
            cout << info->questions[i].respOpt3 << endl;

            cout << left;
            cout << setw(2) << 4 << ") ";
            cout << info->questions[i].respOpt4 << endl;

            cout << left;
            cout << setw(2) << 5 << ") ";
            cout << info->questions[i].respOpt5 << endl;
        }
    }

    void saveToBin() {
        fstream surveyDB("SurveyInfo.dat", ios::in | ios::app | ios::binary);
        surveyDB.seekp(ios::app);

        //Write the title - 50 bytes OK
        surveyDB.write(info->title, sizeof (info->title));

        // Write number of questions - 4 bytes OK
        surveyDB.write(reinterpret_cast<char*> (&info->numQuestions), sizeof (int));

        //Write status  - 1 byte OK
        surveyDB.write(reinterpret_cast<char*> (&info->active), sizeof (bool));

        //Write the number of SurveyQuestion structs  - 4 byte
        int numSurvQ = info->questions.size();
        surveyDB.write(reinterpret_cast<const char*> (&numSurvQ), sizeof (int));

        // Write the survey questions vector
        for (int i = 0; i < info->numQuestions; i++) {
            // Write the question string    - 100 bytes
            surveyDB.write(info->questions[i].question, sizeof (info->questions[i].question));

            // Write the respOptions - 5 * (100 bytes)
            surveyDB.write(info->questions[i].respOpt1, sizeof (info->questions[i].respOpt1));

            surveyDB.write(info->questions[i].respOpt2, sizeof (info->questions[i].respOpt2));

            surveyDB.write(info->questions[i].respOpt3, sizeof (info->questions[i].respOpt3));

            surveyDB.write(info->questions[i].respOpt4, sizeof (info->questions[i].respOpt4));

            surveyDB.write(info->questions[i].respOpt5, sizeof (info->questions[i].respOpt5));
        }

        surveyDB.close();
    }

    void readFromBin() {
        ifstream surveyDB("SurveyInfo.dat", ios::in | ios::binary);

        if (!surveyDB) {
            cerr << "File could not be opened!" << endl;
            return;
        }

        // Read the title - 50 bytes
        char title[TSIZE];
        surveyDB.read(title, sizeof (title));
        cout << "Title: " << title << endl << endl;

        // Read the number of questions - 4 bytes
        int numQuestions;
        surveyDB.read(reinterpret_cast<char*> (&numQuestions), sizeof (numQuestions));
        cout << "Number of questions: " << numQuestions << endl << endl;

        // Read the status - 1 byte
        bool active;
        surveyDB.read(reinterpret_cast<char*> (&active), sizeof (active));
        cout << "Status: " << active << endl << endl;

        // Read the number of SurveyQuestion structs - 4 bytes
        int numSurvQ;
        surveyDB.read(reinterpret_cast<char*> (&numSurvQ), sizeof (numSurvQ));
        cout << "Number of SurveyQuestion structs: " << numSurvQ << endl << endl;

        // Read the survey questions vector
        for (int i = 0; i < numSurvQ; i++) {
            SurveyQInfo q;

            // Read the question string - 100 bytes
            surveyDB.read(q.question, sizeof (q.question));
            cout << "Question " << i + 1 << ": " << q.question << endl;

            // Read the respOptions - 5 * (100 bytes)
            surveyDB.read(q.respOpt1, sizeof (q.respOpt1));
            cout << "Response option 1: " << q.respOpt1 << endl;

            surveyDB.read(q.respOpt2, sizeof (q.respOpt2));
            cout << "Response option 2: " << q.respOpt2 << endl;

            surveyDB.read(q.respOpt3, sizeof (q.respOpt3));
            cout << "Response option 3: " << q.respOpt3 << endl;

            surveyDB.read(q.respOpt4, sizeof (q.respOpt4));
            cout << "Response option 4: " << q.respOpt4 << endl;

            surveyDB.read(q.respOpt5, sizeof (q.respOpt5));
            cout << "Response option 5: " << q.respOpt5 << endl;
        }
        surveyDB.close();
    }

    Survey readFromBin2() {
        fstream surveyDB("SurveyInfo.dat", ios::in | ios::binary);

        if (!surveyDB) {
            cout << "Error: Unable to open file for read." << endl;
            exit(1);
        }

        SurveyInfo *info = new SurveyInfo;

        // Read the title - 50 bytes
        surveyDB.read(info->title, sizeof (info->title));
        cout << "Title: " << info->title << endl;

        // Read number of questions - 4 bytes
        surveyDB.read(reinterpret_cast<char*> (&info->numQuestions), sizeof (int));
        cout << "Number of Questions: " << info->numQuestions << endl;

        // Read status - 1 byte
        surveyDB.read(reinterpret_cast<char*> (&info->active), sizeof (bool));
        cout << "Status: " << info->active << endl;

        // Read the number of SurveyQuestion structs - 4 bytes
        int numSurvQ;
        surveyDB.read(reinterpret_cast<char*> (&numSurvQ), sizeof (int));
        cout << "Number of SurveyQuestion structs: " << numSurvQ << endl;

        // Read the survey questions vector
        for (int i = 0; i < numSurvQ; i++) {
            SurveyQInfo qInfo;

            // Read the question string - 100 bytes
            surveyDB.read(qInfo.question, sizeof (qInfo.question));
            cout << "Question: " << qInfo.question << endl;

            // Read the respOptions - 5 * (100 bytes)
            surveyDB.read(qInfo.respOpt1, sizeof (qInfo.respOpt1));
            cout << "Response Option 1: " << qInfo.respOpt1 << endl;

            surveyDB.read(qInfo.respOpt2, sizeof (qInfo.respOpt2));
            cout << "Response Option 2: " << qInfo.respOpt2 << endl;

            surveyDB.read(qInfo.respOpt3, sizeof (qInfo.respOpt3));
            cout << "Response Option 3: " << qInfo.respOpt3 << endl;

            surveyDB.read(qInfo.respOpt4, sizeof (qInfo.respOpt4));
            cout << "Response Option 4: " << qInfo.respOpt4 << endl;

            surveyDB.read(qInfo.respOpt5, sizeof (qInfo.respOpt5));
            cout << "Response Option 5: " << qInfo.respOpt5 << endl;

            info->questions.push_back(qInfo);
        }

        surveyDB.close();

        Survey survey;
        survey.info = info;
        return survey;
    }
};

#endif /* SURVEY_H */

