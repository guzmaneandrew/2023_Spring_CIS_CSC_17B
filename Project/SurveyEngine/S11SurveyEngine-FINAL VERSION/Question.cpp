/*
 * Click nbfs:://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs:://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"

Question::Question() {
    strcpy(question, " ");
    typeInt = 0;
    numRespOptions = 0;
}

Question::Question(char q[], int type, int numResp, vector<string> options) {
    strcpy(question, q);
    typeInt = type;
    numRespOptions = numResp;
    respOptions = options;
}

void Question::setQ(char q[]) {
    strcpy(question, q);
}

void Question::setType(int t) {
    typeInt = t;
}

void Question::setNumResp(int n) {
    numRespOptions = n;
}

void Question::setRespOptions(vector<string> options) {
    respOptions = options;
}

void Question::setResp(int i) {
    string response;
    cout << endl << "Enter New Response Option: ";
    getline(cin, response);

    if (i >= 0 && i < respOptions.size()) {
        respOptions[i] = response;
    }
}

void Question::addResp() {
    numRespOptions++;
    string response;
    cout << "Enter New Response Option:: ";
    getline(cin, response);
    respOptions.push_back(response);
}

void Question::deleteROpt(int i) {
    numRespOptions--;
    respOptions.erase(respOptions.begin() + i);
}

const char* Question::getQ() const {
    return question;
}

int Question::getType() const {
    return typeInt;
}

int Question::getNumResp() const {
    return respOptions.size();
}

vector<string> Question::getRespOptions() const {
    return respOptions;
}

string Question::dispType() {
    if (typeInt == SINGLE) return "Single Choice";
    else if (typeInt == MULTIPLE) return "Multiple Choice";
    else if (typeInt == WRITEIN) return "Multiple Choice/Write-In Response";
    else return " ";
}

void Question::display() {
    cout << question << endl;
    cout << "Type: " << dispType() << endl;
    cout << left;
    for (int i = 0; i < numRespOptions; i++) {
        cout << setw(3) << i + 1 << ") " << respOptions[i] << endl;
    }
    cout << endl;
}