/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"
#include "Survey.h"

Survey::Survey() {
    survey = new SurveyInfo;
}

Survey::Survey(char title[], int numQ, vector<SurveyQuestion> questions) {
    survey = new SurveyInfo;
    for (int i = 0; i < SIZE; i++) {
            survey.title[i] = title[i];
        }
    survey->numQuestions = numQ;
    survey->questions = questions;
}

Survey::~Survey() {
    delete []survey;
}

void Survey::addQuestion(SurveyQuestion q) {
    survey->questions.push_back(q);
}

void Survey::display() {
    cout << "Survey: " << survey->title << endl;
    for (int i = 0; i < survey->numQuestions; i++) {
        cout << "Question " << i + 1 << ": " << survey->questions[i].question << endl;
        displayType(survey->questions[i].questionType);
//        cout << "Response Number " << survey->questions[i].numResponses << endl;
        for (int j = 0; j < survey->questions[i].numResponses; j++) {
            cout << j + 1 << ") " << survey->questions[i].responses[j] << endl;
        }
        cout << endl;
    }
}

void Survey::writeToFile(Survey *survey) {
    ofstream outFile("SurveyData.dat", ios::binary | ios::app);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*> (survey->survey), sizeof (SurveyInfo));
        outFile.close();
        cout << "Survey Saved to Binary File." << endl;
    }
}

void Survey::readFromFile() {
    ifstream inFile("SurveyData.dat", ios::binary);
    if (inFile.is_open()) {
        //Read SurveyInfo
        SurveyInfo surveyInfo;
        inFile.read(reinterpret_cast<char*>(&surveyInfo), sizeof(SurveyInfo));
        Survey *survey = new Survey(surveyInfo.title, surveyInfo.questions.size(),
            surveyInfo.questions);
        survey->survey->title = surveyInfo.title;
        survey->survey->numQuestions = surveyInfo.numQuestions;
        survey->survey->questions = surveyInfo.questions;

        survey->display();
    }
    else {
        cout << "Unable to open file.";
    }
}

void Survey::displayType(QType type) {
    cout << "Question Type: ";
    if (type == MULTIPLE) {
        cout << "Multiple Choice" << endl;
    } else if (type == SINGLE) {
        cout << "Single Choice" << endl;
    } else if (type == WRITEIN) {
        cout << "Write-In" << endl;
    }
}