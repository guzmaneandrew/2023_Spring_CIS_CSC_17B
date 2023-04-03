/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 3:30 PM
 * Purpose: v6) Structure in a structure
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int MAX=10;       //each survey max 10 questions, each question 10 max answers

//Structure Definitions
struct SurveyQuestion {
    string question;        //Question
    string responses[MAX];  //Possible responses
    int numResponses;       //number of response options for question
    char questionType;      //Type of question
};

struct Survey {
    int numQuestions;           //Number of questions
    SurveyQuestion *questions;  //Structure within a structure
};

//Function Prototypes
char dispMenu();
void createUsers();
Survey *createSurvey();                 //Fill structure
void display(Survey *);                   //Display survey
void display(string *,int);             //Display responses for question
void destroy(Survey *);                   //De-allocate memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    Survey *survey;
    
    //Initialize Variables
    survey=createSurvey();
    
    //Display the Inputs and Outputs
    display(survey);
    
    //Clean Up the Dynamic Stuff
    destroy(survey);

    //Exit 
    return 0;
}

char dispMenu() {
    char choice;
    
    cout<<"Press 1: Admin Login"<<endl;
    cout<<"Press 2: User Login"<<endl;
    cout<<"Press 3: Create Admin Account"<<endl;
    cout<<"Press 4: Create User Account"<<endl;
    
    cin>>choice;
    return choice;
}

void createUsers() {
    string email,password;
    int nUsers;
            
    cout<<"Enter the Number of Users: ";
    cin>>nUsers;
    cout<<"Number of Users: "<<nUsers<<endl;
    
    for(int i=0;i<nUsers;i++) {
        cout<<endl<<"User "<<i+1<<endl;
        cout<<"Enter Email Address: ";
        cin>>email;
        cout<<"Enter Password: ";
        cin>>password;
        
        //Display the Inputs and Outputs
        cout<<left<<endl;
        cout<<setw(12)<<"Email: "<<email<<endl;
        cout<<setw(12)<<"Password: "<<password<<endl<<endl; 
    }
}

Survey *createSurvey() {
    Survey *survey=new Survey;
    
    cout<<"Enter Number of Questions: ";
    cin>>survey->numQuestions;
    
    survey->questions=new SurveyQuestion[survey->numQuestions];
    
    for(int i=0;i<survey->numQuestions;i++) {
            cout<<"Question "<<i+1<<endl;
            cout<<"Enter Question Type\n(1 = Multiple Choice,"
                    " 2 = Single Choice, 3 = Write-In): ";
            cin>>survey->questions[i].questionType;
            cin.ignore();
            cout<<"Enter Question: ";
            getline(cin,survey->questions[i].question);
            do {
                cout<<"Enter Number of Response Options(up to 10): ";
                cin>>survey->questions[i].numResponses;
                cin.ignore();
            }while(survey->questions[i].numResponses>10);
            for(int j=0;j<survey->questions[i].numResponses;j++) {
                cout<<"Enter Response Option "<<j+1<<": ";
                getline(cin,survey->questions[i].responses[j]);
            }
    }
    
    return survey;
}

void display(Survey *survey) {
    cout<<"Survey"<<endl;
    for(int j=0;j<survey->numQuestions;j++) {
        cout<<"Question: "<<j+1<<endl;
        display(survey->questions[j].responses,survey->questions[j].numResponses);
    }
}

void display(string *responses,int nResponses) {
    for(int i=0;i<nResponses;i++) {
        cout<<i+1<<") "<<responses[i]<<endl;
    }
}

void destroy(Survey *survey) {
    delete []survey;
}