/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Headers.h"

Admin::Admin(string name, string pass) {
    strcpy(info.username, name.c_str());
    strcpy(info.password, pass.c_str());

    int choice;
    do {
        cout << endl << "Hello Admin, " << info.username << endl;
        cout << " 1) Create New Survey" << endl;
        cout << " 2) List All Surveys" << endl;
        cout << " 3) List Active Surveys" << endl;
        cout << " 4) List Inactive Surveys" << endl;
        cout << " 5) View a Survey" << endl;
        cout << " 6) Update a Survey" << endl;
        cout << " 7) List Users" << endl;
        cout << " 8) List Admins" << endl;
        cout << " 9) Add Admin" << endl;
        cout << "-99) Delete All Surveys" << endl;
        cout << "-1) Logout" << endl;
        cin>>choice;
        cin.ignore();
        if (choice == 1) {
            createSrv();
        } else if (choice == 2) {
            listAllSrv();
        } else if (choice == 3) {
            listActvSrv();
        } else if (choice == 4) {
            listInacSrv();
        } else if (choice == 5) {
            prntSrv();
        } else if (choice == 6) {
            updtSrv();
        } else if (choice == 7) {
            listUsrs();
        } else if (choice == 8) {
            listAdmins();
        } else if (choice == 9) {
            addAdmin();
        } else if (choice == -99) {
            deleteAll();
        }

    } while (choice != -1);
};

void Admin::listUsrs() {
    fstream userDB("UserInfo.dat", ios::in | ios::app | ios::binary);
    UserInfo temp;

    cout << endl << "LIST USERS" << endl;
    cout << endl << "Username \t Password \t Active" << endl << endl;
    userDB.seekg(ios::beg);
    while (userDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
        cout << left << setw(17);
        cout << temp.username << setw(17) << temp.password << setw(17) <<
                boolalpha << temp.status << endl;
    }
    userDB.close();
}

void Admin::addAdmin() {
    //Add admins to admin DB
    string username, password;
    cout << "Enter the Username for the Admin: ";
    cin>>username;
    cout << "Enter the Password for the Admin: ";
    cin>>password;

    AdminInfo newAdmin;
    strcpy(newAdmin.username, username.c_str());
    strcpy(newAdmin.password, password.c_str());

    fstream adminDB("AdminInfo.dat", ios::in | ios::app | ios::binary);
    adminDB.seekp(ios::app);
    adminDB.write(reinterpret_cast<char *> (&newAdmin), sizeof (newAdmin));
    adminDB.close();
    listAdmins();
}

void Admin::listAdmins() {
    fstream adminDB("AdminInfo.dat", ios::in | ios::app | ios::binary);
    AdminInfo temp;

    cout << endl << "List Admins" << endl;
    cout << endl << "Username \t Password" << endl << endl;
    adminDB.seekg(ios::beg);
    while (adminDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
        cout << left << setw(17);
        cout << temp.username << setw(17) << temp.password << endl;
    }
    adminDB.close();
}

void Admin::createSrv() {
    //Create survey and add to survey DB
    char title[TSIZE];
    int numQs;
    cout << endl << "CREATE NEW SURVEY" << endl;
    cout << "Enter Title: ";
    cin.getline(title, TSIZE);
    cout << "Enter Number of Questions: ";
    cin>>numQs;
    cin.ignore();

    Survey *surv = new Survey(title, numQs);
    surveys.push_back(surv);
    surv->saveToBin("SurveyInfo.dat");
    surv->display();
}

void Admin::listAllSrv() {
    readFromBin("SurveyInfo.dat");

    cout << endl << "ALL SURVEYS" << endl;
    if (surveys.size() == 0) {
        cout << "No Surveys To Retrieve from the Database." << endl;
    } else {
        for (int i = 0; i < surveys.size(); i++) {
            surveys[i]->display();
        }
        cout << left;
        cout << setw(50) << "Title" << right << setw(12) << "Active" << endl;
        for (int i = 0; i < surveys.size(); i++) {
            cout << i + 1 << ") ";
            cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                    << boolalpha << surveys[i]->getStatus() << endl;
        }
    }
}

void Admin::listActvSrv() {
    int num = 1; //number that appears next to survey in list
    bool none = true;
    readFromBin("SurveyInfo.dat");

    cout << endl << "ACTIVE SURVEYS" << endl;
    if (surveys.size() == 0) {
        cout << "No Surveys To Retrieve from the Database." << endl;
    } else {
        cout << left;
        cout << setw(50) << "Title" << right << setw(12) << "Active" << endl;
        for (int i = 0; i < surveys.size(); i++) {
            if (surveys[i]->getStatus() == true) {
                cout << num++ << ") ";
                cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                        << boolalpha << surveys[i]->getStatus() << endl;
                none = false;
            }
        }
        if (none == true) {
            cout << right << setw(15) << "- - - - - - None - - - - - -" << endl;
        }
    }
}

void Admin::listInacSrv() {
    int num = 1; //number that appears next to survey in list
    bool none = true;
    readFromBin("SurveyInfo.dat");

    cout << endl << "INACTIVE SURVEYS" << endl;
    if (surveys.size() == 0) {
        cout << "No Surveys To Retrieve from the Database." << endl;
    } else {
        cout << left;
        cout << setw(50) << "Title" << right << setw(12) << "Active" << endl;
        for (int i = 0; i < surveys.size(); i++) {
            if (surveys[i]->getStatus() == false) {
                cout << num++ << ") ";
                cout << left << setw(50) << surveys[i]->getTitle() << "\t"
                        << boolalpha << surveys[i]->getStatus() << endl;
                none = false;
            }
        }
        if (none == true) {
            cout << right << setw(15) << "- - - - - - None - - - - - -" << endl;
        }
    }
}

void Admin::prntSrv() {
    int survNum, indx, validNum;

    cout << endl << "VIEW SURVEY" << endl;

    //List all surveys (also reloads surveys from binary file)
    listAllSrv();
    validNum = surveys.size();

    if (surveys.size() != 0) { //If surveys in DB, prompt for which to view
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

void Admin::updtSrv() {
    Survey *surv2updt;
    int survNum, indx, choice, validNum;

    cout << endl << "UPDATE SURVEY" << endl;

    //List all surveys
    listAllSrv();
    validNum = surveys.size();

    if (surveys.size() != 0) { //If surveys in DB, prompt for which to update      
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

        do { //Print menu
            cout << "Enter What You Would Like to Update for This Survey" << endl;
            cout << " 1) Status" << endl;
            cout << " 2) Questions/Responses Options" << endl;
            cout << " 3) Add Question" << endl;
            cout << " 4) Delete Question" << endl;
            cout << " 0) Cancel Survey Updates " << endl;

            cin>>choice;
            cin.ignore();
            switch (choice) {
                case 1:
                    cout << endl << "UPDATE STATUS" << endl;
                    updtStatus(surv2updt);
                    break;
                case 2:
                    cout << endl << "UPDATE QUESTIONS" << endl;
                    updtSrvQs(surv2updt);
                    break;
                case 3:
                    cout << endl << "ADD QUESTION" << endl;
                    addSrvQ(surv2updt);
                    break;
                case 4:
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

        reloadSrvs("SurveyInfo.dat"); //Write to and read from binary
    }
}

void Admin::deleteAll() {
    string confirm1, adminConf;

    cout << "DANGER ZONE: DELETE ALL SURVEYS" << endl;
    cout << "This Action Will Permanently Delete All Surveys In Your Database.\n";

    do {
        cout << "Press 'D' to Continue or 'X' to Cancel: ";
        cin>>confirm1;
        cin.ignore();
    } while (confirm1 != "D" && confirm1 != "X");

    do {
        if (confirm1 == "X") {
            break;
        }
        cout << "There Is No Going Back, Please Be Certain." << endl;
        cout << "To Confirm, Enter Admin Password (X to Cancel): ";
        getline(cin, adminConf);
        if (adminConf == "X") break;
    } while (adminConf != info.password);

    if (adminConf == info.password && confirm1 == "D") {
        clearBin("SurveyInfo.dat");
        surveys.clear();
        cout << endl << "All Surveys Have Been Deleted from the Database..." << endl;
    }
}

//    Helper Functions

void Admin::addSrvQ(Survey *survey) {
    survey->addQ();
    survey->display();
}

void Admin::deleteQ(Survey *survey) {
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

void Admin::updtStatus(Survey *survey) {
    survey->setStatus(!survey->getStatus());
    survey->display();
}

void Admin::updtSrvQs(Survey *survey) {
    int numQ, indx, choice, validIndx;

    //Get questions vector for specific question
    vector<Question *> qs = survey->getQs();
    validIndx = qs.size();

    //Prompt for which question to update
    do {
        cout << "Enter Number of Question To Update: ";
        cin>>numQ;
        cin.ignore();
        if (numQ <= 0 || numQ > validIndx) {
            cout << "Invalid Question Number. Enter 1 - " << validIndx << "." << endl;
        }
    } while (numQ < 0 || numQ > validIndx);

    //Display the question
    indx = numQ - 1;
    cout << endl << "Question: ";
    qs[indx]->display();

    //Print menu of choices for what to update for a given question
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

    survey->display(); //Display updated survey

    reloadSrvs("SurveyInfo.dat"); //Write to binary and read to vectors
}

void Admin::updtQ(Question *q) {
    char newQ[QRSIZE];

    cout << "Enter New Question: ";
    cin.getline(newQ, QRSIZE);
    q->setQ(newQ);

    cout << endl << "Question: ";
    q->display();
}

void Admin::updtQType(Question *q) {
    int type;

    cout << "Enter Question Type (1=Single, 2=Multiple, 3=Write-In): ";
    cin>>type;
    cin.ignore();
    q->setType(type);

    cout << endl << "Question: ";
    q->display();
}

void Admin::updtROpts(Question *q) {
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

    reloadSrvs("SurveyInfo.dat");
}

void Admin::updtROPt(Question *q) {
    int numR, indx, validIndx; //input number of responses, index of response to 
    //delete, and valid number for a response

    validIndx = q->getNumResp();

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

void Admin::addROpt(Question *q) {
    q->addResp();

    cout << endl << "Question: ";
    q->display();
}

void Admin::deleteROpt(Question *q) {
    int numR, indx, validNum; //input number of responses, index of response to 
    //delete, and valid number for a response

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

void Admin::readFromBin(string file) {
    surveys.clear(); //Clear vector first to read entire file contents to it
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
        surveys.push_back(survey);
    }
    surveyDB.close();
}

void Admin::clearBin(string file) {
    //Deletes all contents of the binary file
    ofstream surveyDB(file, ios::out | ios::trunc);
    surveyDB.close();
}

void Admin::reloadSrvs(string file) {
    //Clear binary file, output vector surveys to binary, then read from binary
    clearBin(file);

    for (int i = 0; i < surveys.size(); i++) {
        surveys[i]->saveToBin(file);
    }

    readFromBin(file);
}