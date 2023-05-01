/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 4:00 PM
 * Purpose: v7) Class in main
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries
#include "Survey.h"

class CSurvey {
    private:
        Survey *survey;        //Pointer to dynamic Survey structure
    public:
        CSurvey();      //Constructor
        ~CSurvey();     //Destructor
        void display(); //Display structures
};

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
char dispMenu();
void createUsers();

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

CSurvey::CSurvey() {
    survey=new Survey;
    
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
}

void CSurvey::display() {
    cout<<"Survey"<<endl;
    for(int i=0;i<survey->numQuestions;i++) {
        cout<<"Question "<<i+1<<": "<<survey->questions[i].question<<endl;
        for(int j=0;j<survey->questions[i].numResponses;j++) {
            cout<<j+1<<") "<<survey->questions[i].responses[j]<<endl;    
        }
    }
}

CSurvey::~CSurvey() {
    delete []survey;
}

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    CSurvey csurvey;        //Create an instance of the CSurvey class
    
    //Initialize Variables
    
    //Display the Inputs and Outputs
    csurvey.display();
    
    //Clean Up the Dynamic Stuff
    

    //Exit 
    return 0;
}