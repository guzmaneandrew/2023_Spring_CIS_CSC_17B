/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 28, 2023 @ 10:31 AM
 * Purpose: v4) Create static structure array
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
enum questionType{MULTIPLE,SINGLE,WRITEIN};  //multiple choice, single choice, write in

//Structure Definitions
struct SurveyQuestion {
    string question;        //Question
    string responses[MAX];  //Possible responses
};

//Function Prototypes
char dispMenu();
void createUsers();
void createSurvey();

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    
    const int TOOMANY=10;
    SurveyQuestion survey[TOOMANY];
    int numQuestions=0,numResponses=0;      //Number of questions,answers

    do {
        cout<<"Enter the Number of Questions for the Survey(up to 10): ";
        cin>>numQuestions;
        cin.ignore();    
    } while(numQuestions>MAX);
    
    for(int i=0;i<numQuestions;i++) {
        cout<<endl;
        cout<<"Enter Question "<<i+1<<": ";
        getline(cin,survey[i].question);
        cout<<"Enter Number of Response Options For Question "<<i+1<<": ";
        cin>>numResponses;
        cin.ignore();
        for(int j=0;j<numResponses;j++) {
            cout<<"Enter Response Option "<<j+1<<": ";
            getline(cin,survey[i].responses[j]);
        }   
        
        cout<<endl<<"Question "<<i+1<<": "<<survey[i].question<<endl;
        for(int j=0;j<numResponses;j++) {
            cout<<survey[i].responses[j]<<endl;
        }
    }
    
    //Clean Up the Dynamic Stuff

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

void createSurvey() {

}

void displaySurvey() {
    
}