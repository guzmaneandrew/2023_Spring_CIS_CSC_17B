/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"

Survey::Survey() {
}

Survey::Survey(char t[], int num) {
    strcpy(title, t);
    status = true;
    numQs = num;
    for (int i = 0; i < num; i++) {
        newSurvQ();
    }
}

Survey::~Survey() {
    for (int i = 0; i < questions.size(); i++) {
        delete questions[i];
    }
}

void Survey::newSurvQ() {
    //Receive input for new survey Question
    char q[QRSIZE];
    int type, numResp, writeInIndx = 0;
    vector<string> responses;

    do {
        cout << "Enter Question: ";
        cin.getline(q, QRSIZE);
    } while (strcmp(q, "") == 0);


    do {
        cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
        cin >> type;
    } while (type > 3);


    cout << "Enter Number of Response Options: ";
    cin >> numResp;
    cin.ignore();

    //If write-in Q, don't prompt for input for last option
    if (type == 3) {
        writeInIndx = numResp - 1;
    }

    for (int i = 0; i < numResp; i++) {
        string response;
        if (type == 3 & i == writeInIndx) {
            response = " ";
        } else if (i < numResp && (type == 1 | type == 2 || type == 3)) {
            do {
                cout << "Enter Response Option " << i + 1 << ": ";
                getline(cin, response);
            } while (response == "");
        }
        responses.push_back(response);
    }

    //Create new Question object
    Question *question = new Question(q, type, numResp, responses);
    questions.push_back(question);
}

void Survey::addQ() {
    numQs++;
    //Receive input for new survey Question
    char q[QRSIZE];
    int type, numResp, writeInIndx = 0;
    vector<string> responses;

    do {
        cout << "Enter Question: ";
        cin.getline(q, QRSIZE);
    } while (strcmp(q, "") == 0);


    do {
        cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
        cin >> type;
    } while (type > 3);


    cout << "Enter Number of Response Options: ";
    cin >> numResp;
    cin.ignore();

    //If write-in Q, don't prompt for input for last option
    if (type == 3) {
        writeInIndx = numResp - 1;
    }

    for (int i = 0; i < numResp; i++) {
        string response;
        if (type == 3 & i == writeInIndx) {
            response = " ";
        } else if (i < numResp && (type == 1 | type == 2 || type == 3)) {
            do {
                cout << "Enter Response Option " << i + 1 << ": ";
                getline(cin, response);
            } while (response == "");
        }
        responses.push_back(response);
    }

    //Create new Question object
    Question *question = new Question(q, type, numResp, responses);
    questions.push_back(question);
}

const char* Survey::getTitle() const {
    return title;
}

string Survey::getTitle(bool) const {
    string s(title);
    return s;
}

void Survey::setTitle(char t[]) {
    strcpy(title, t);
}

void Survey::setNumQs(int n) {
    numQs = n;
}

void Survey::setStatus(bool a) {
    status = a;
}

void Survey::setQs(vector<Question *>qs) {
    questions = qs;
}

void Survey::deleteQ(int i) {
    if (i >= 0 && i < questions.size()) {
        numQs--;
        delete questions[i];
        questions.erase(questions.begin() + i);
    } else {
        cout << "ERROR: Invalid Question Index." << endl;
    }
}

bool Survey::getStatus() const {
    return status;
}

int Survey::getNumQs() const {
    return numQs;
}

vector<Question *> Survey::getQs() {
    return questions;
}

Question* Survey::getQ(int i) {
    i--; //vectors are 0 indexed
    return questions[i];
}

void Survey::display() {
    cout << "------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Active: " << boolalpha << status << endl;
    cout << "Number of Questions: " << numQs << endl << endl;
    for (int i = 0; i < numQs; i++) {
        cout << "Question " << i + 1 << ": ";
        questions[i]->display();
    }
}

void Survey::saveToBin(string file) {
    fstream surveyDB(file, ios::out | ios::binary | ios::app);

    if (!surveyDB) {
        cerr << "Error: Unable to Open File for Writing." << endl;
        return;
    }

    //Write title and number of questions to binary file
    surveyDB.write(reinterpret_cast<char *> (title), TSIZE);
    surveyDB.write(reinterpret_cast<char *> (&status), sizeof (bool));
    surveyDB.write(reinterpret_cast<char *> (&numQs), sizeof (int));
    //Write each question info to binary file
    for (int i = 0; i < numQs; i++) {
        char q[QRSIZE];
        int type, numResp;
        vector<string> resp;

        strcpy(q, questions[i]->getQ());
        type = questions[i]->getType();
        numResp = questions[i]->getNumResp();
        resp = questions[i]->getRespOptions();

        surveyDB.write(reinterpret_cast<char *> (q), QRSIZE);
        surveyDB.write(reinterpret_cast<char *> (&type), sizeof (int));
        surveyDB.write(reinterpret_cast<char *> (&numResp), sizeof (int));

        for (int j = 0; j < numResp; j++) {
            int len = resp[j].length();
            surveyDB.write(reinterpret_cast<char *> (&len), sizeof (int));
            surveyDB.write(resp[j].c_str(), len);
        }
    }
    surveyDB.close();
}

void Survey::readFromBin(string file) {
    fstream surveyDB(file, ios::in | ios::binary);
    if (!surveyDB) {
        cerr << "Error: Unable to Open File for Reading." << endl;
        return;
    }

    //Read title and number of questions from binary file
    char title[TSIZE];
    bool status;
    int numQs;
    surveyDB.read(reinterpret_cast<char *> (title), TSIZE);
    surveyDB.read(reinterpret_cast<char *> (&status), sizeof (bool));
    surveyDB.read(reinterpret_cast<char *> (&numQs), sizeof (int));

    //Loop through each question in the binary file and read its properties
    for (int i = 0; i < numQs; i++) {
        char q[QRSIZE];
        int type, numResp;
        vector<string> options;

        surveyDB.read(reinterpret_cast<char *> (q), sizeof (q));
        surveyDB.read(reinterpret_cast<char *> (&type), sizeof (int));
        surveyDB.read(reinterpret_cast<char *> (&numResp), sizeof (int));

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

    //Create new Survey object and add it to vector
    Survey *survey = new Survey();
    strcpy(survey->title, title);
    survey->setStatus(status);
    survey->numQs = numQs;
    survey->questions = questions;
    survey->display();

    surveyDB.close();
}