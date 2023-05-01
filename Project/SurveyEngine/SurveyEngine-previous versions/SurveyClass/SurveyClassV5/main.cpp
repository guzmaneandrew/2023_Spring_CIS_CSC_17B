/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 2:55 PM
 * Purpose: v5) Fill and display structure in functions
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

//Function Prototypes
char dispMenu();
void createUsers();
SurveyQuestion *createSurvey(int &);    //Fill structure
void display(SurveyQuestion *,int);     //Display survey
void display(string *,int);             //Display responses for question

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    SurveyQuestion *survey;
    int numQuestions;      //Number of questions
    
    //Initialize Variables
    survey=nullptr;
    numQuestions=0;

    do {
        cout<<"Enter the Number of Questions for the Survey(up to 10): ";
        cin>>numQuestions;
        cin.ignore();    
    } while(numQuestions>MAX);
    
    survey=createSurvey(numQuestions);
    
    //Display the Inputs and Outputs
    display(survey,numQuestions);
    
    //Clean Up the Dynamic Stuff
    delete []survey;

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

SurveyQuestion *createSurvey(int &nQuestions) {
    SurveyQuestion *survey=new SurveyQuestion[nQuestions];
    
    for(int i=0;i<nQuestions;i++) {
            cout<<"Question "<<i+1<<endl;
            cout<<"Enter Question Type (1=Multiple Choice,"
                    " 2=Single Choice, 3=Write-In): ";
            cin>>survey[i].questionType;
            cin.ignore();
            cout<<"Enter Question: ";
            getline(cin,survey[i].question);
            do {
                cout<<"Enter Number of Response Options(up to 10): ";
                cin>>survey[i].numResponses;
                cin.ignore();
            }while(survey[i].numResponses>10);
            for(int j=0;j<survey[i].numResponses;j++) {
                cout<<"Enter Response Option "<<j+1<<": ";
                getline(cin,survey[i].responses[j]);
            }
    }
    
    return survey;
}

void display(SurveyQuestion *survey,int nQuestions) {
    cout<<"Survey"<<endl;
    for(int j=0;j<nQuestions;j++) {
        cout<<"Question: "<<survey->question<<endl;
        display(survey->responses,survey->numResponses);
    }
}

void display(string *responses,int nResponses) {
    for(int i=0;i<nResponses;i++) {
        cout<<i+1<<") "<<responses[i]<<endl;
    }
}