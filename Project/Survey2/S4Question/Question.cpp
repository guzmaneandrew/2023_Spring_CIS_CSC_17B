/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"
#include "Question.h"

Question::Question() {
    questInfo = new QuestionInfo;

    cout << "Enter Question: ";
    cin.getline(questInfo->question, QRSIZE);

    cout << "Enter Question Type(1 = Single, 2 = Multiple, 3 = WriteIn): ";
    cin >> questInfo->typeInt;


    cout << "Enter Number of Response Options: ";
    cin >> questInfo->numRespOptions;
    cin.ignore();

    questInfo->respInfo = new ResponseInfo[questInfo->numRespOptions];
    for (int j = 0; j < questInfo->numRespOptions; j++) {
        cout << "Enter Response Option " << j + 1 << ": ";
        cin.getline(questInfo->respInfo[j].respOption, QRSIZE);
    }
}

void Question::display() {
    cout << endl;
    cout << "Question: " << questInfo->question << endl;
    cout << "Number of Response Options: " << questInfo->numRespOptions << endl;
    for (int j = 0; j < questInfo->numRespOptions; j++) {
        cout << left;
        cout << setw(3) << j + 1 << ") " << questInfo->respInfo[j].respOption << endl;
    }

}

Question::~Question() {
    delete [] questInfo->respInfo;
    delete questInfo;
}
