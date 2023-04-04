/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"
#include "Survey.h"

Survey::Survey() {
    survey=new SurveyInfo;
}

Survey::Survey(string title,int numQ,vector<SurveyQuestion> questions) {
    survey=new SurveyInfo;
    survey->title=title;
    survey->numQuestions=numQ;
    survey->questions=questions;
}

Survey::~Survey() {
    delete []survey;
}

void Survey::addQuestion(SurveyQuestion q) {
    survey->questions.push_back(q);
}

void Survey::display() {
    cout<<"Survey: "<<survey->title<<endl;
    for(int i=0;i<survey->numQuestions;i++) {
        cout<<"Question "<<i+1<<": "<<survey->questions[i].question<<endl;
        cout<<"Response "<<survey->questions[i].questionType<<endl;
        cout<<"Response Number "<<survey->questions[i].numResponses<<endl;
        for(int j=0;j<survey->questions[i].numResponses;j++) {
            cout<<j+1<<") "<<survey->questions[i].responses[j]<<endl;
        }
    }
}

void Survey::writeToFile(Survey *survey) {
    ofstream outFile("SurveyData.dat", ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*>(survey->survey), sizeof(SurveyInfo));
//        // Write survey title
//        int titleSize = survey->getTitle().size()+1;
//        outFile.write(reinterpret_cast<const char*>(&titleSize), sizeof(int));
//        outFile.write(survey->getTitle().c_str(), titleSize);
//
//        // Write survey questions
//        vector<SurveyQuestion> questions = survey->getQuestions();
//        int numQuestions = questions.size();
//        outFile.write(reinterpret_cast<const char*>(&numQuestions), sizeof(int));
//        for (int i = 0; i < numQuestions; i++) {
//            int questionSize = questions[i].size()+1;
//            outFile.write(reinterpret_cast<const char*>(&questionSize), sizeof(int));
//            outFile.write(questions[i].c_str(), questionSize);
//        }

        outFile.close();
        cout << "Survey information saved to binary file."<<endl;
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
        
        //Read SurveyQuestion
        for (int i = 0; i < surveyInfo.numQuestions; i++) {
            cout<<surveyInfo.questions[i].question<<endl;
        }
        
        inFile.close();
//        // Read survey title
//        int titleSize;
//        inFile.read(reinterpret_cast<char*>(&titleSize), sizeof(int));
//        string title;
//        getline(inFile,title,'\0');
//
        cout<<survey->survey->title<<endl;
//        // Read survey questions
//        int numQuestions;
//        inFile.read(reinterpret_cast<char*>(&numQuestions), sizeof(int));
//        vector<string> questions;
//        for (int i = 0; i < numQuestions; i++) {
//            int questionSize;
//            inFile.read(reinterpret_cast<char*>(&questionSize), sizeof(int));
//            string question;
//            getline(inFile, question, '\0');
//            questions.push_back(question);
//            cout<<question<<endl;
//        }
//
//        inFile.close();
////        return Survey(title, questions);
        cout<<"Survey Information Read From a Binary File."<<endl;
    }
    else {
        cout << "Unable to open file.";
//        return Survey("", "", {});
    }
}