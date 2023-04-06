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
    char response[QRSIZE]; //Response
    int numResponses; //number of responses
};

struct SurveyInfo {
    int numQuestions; //Number of questions
    char title[TSIZE]; //Title of info
    vector<SurveyQInfo> questions; //questions in Survey
    bool active; //Status of survey
};

class Survey {
private:
    SurveyInfo *info;
public:

    Survey() {
        info = new SurveyInfo; //Declare pointer to SurveyInfo object
        info->numQuestions = 0;
        info->active = false;
    }

    Survey(char title[], int numQ) {
        info = new SurveyInfo; //Declare pointer to SurveyInfo object
        info->numQuestions = numQ;
        for (int i = 0; i < TSIZE; i++) {
            info->title[i] = title[i];
        }
        info->active = true;

        //Allocate memory for the questions vector
        info->questions.resize(info->numQuestions);

        //Set information for every survey question
        for (int i = 0; i < info->numQuestions; i++) {
            cout << endl;
            cout << "Enter Question " << i + 1 << ": ";
            //Read in the question
            cin.getline(info->questions[i].question, QRSIZE);

            //Read in number of responses
            do {
                cout << "Enter Number of Responses (up to 10): ";
                cin >> info->questions[i].numResponses;
                cin.ignore();
            } while (info->questions[i].numResponses > RSIZE);

            //Read in responses
            for (int j = 0; j < info->questions[i].numResponses; j++) {
                cout << "Enter Response " << j + 1 << ": ";
                cin.getline(info->questions[i].response, QRSIZE);
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

    //    void setQuestion(int i, string q) {
    //        info->questions[i].question = q;
    //    }

    void display() {
        //Display survey
        cout << endl;
        cout << "Title: " << info->title << endl;
        for (int i = 0; i < info->numQuestions; i++) {
            cout << endl;
            cout << "Question " << i + 1 << ": " << info->questions[i].question << endl;
            for (int j = 0; j < info->questions[i].numResponses; j++) {
                cout << left;
                cout << setw(2) << j + 1 << ") ";
                cout << info->questions[i].response<< endl;
            }
        }
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
    //            // Write the number of responses
    //            surveyDB.write(reinterpret_cast<char*> (&info->questions[i].numResponses), sizeof (int));
    //
    //            // Write the responses
    //            for (int j = 0; j < info->questions[i].numResponses; j++) {
    //                int responseLen = info->questions[i].responses[j].size();
    //                surveyDB.write(reinterpret_cast<char*> (&responseLen), sizeof (int));
    //                surveyDB.write(info->questions[i].responses[j].c_str(), responseLen);
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
    //            // Read the number of responses
    //            int numResponses;
    //            surveyDB.read(reinterpret_cast<char*> (&numResponses), sizeof (int));
    //            info->questions[i].numResponses = numResponses;
    //
    //            // Read the responses
    //            for (int j = 0; j < numResponses; j++) {
    //                int responseLen;
    //                surveyDB.read(reinterpret_cast<char*> (&responseLen), sizeof (int));
    //                char* respCArr = new char[responseLen + 1];
    //                surveyDB.read(respCArr, responseLen);
    //                respCArr[responseLen] = '\0';
    //                info->questions[i].responses[j] = respCArr;
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

