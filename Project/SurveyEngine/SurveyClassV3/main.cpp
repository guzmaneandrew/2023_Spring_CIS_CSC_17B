/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 28, 2023 @ 10:31 AM
 * Purpose: v3) Format the results
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std; //Libraries compiled under std

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
char dispMenu();
void createUsers();
void createSurveys();

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int nUsers=0;

    
    //Initial Variables
//    createUsers();
    createSurveys();
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

void createSurveys() {
    string question,answer;
    int numQuestions=0,numAnswers=0;      //Number of questions,answers
    const char MAX=10;    //Max number of questions/answers
    string questions[MAX];
    string answers[MAX];
    
    cout<<"Enter the Number of Questions for the Survey: ";
    cin>>numAnswers;
    cin.ignore();
    for(int i=0;i<numAnswers;i++) {
        cout<<endl;
        cout<<"Enter Question "<<i+1<<": ";
        getline(cin,questions[i]);
        cout<<"Enter Number of Response Options For Question "<<i+1<<": ";
        cin>>numAnswers;
        cin.ignore();
        for(int j=0;j<numAnswers;j++) {
            cout<<"Enter Response Option "<<j+1<<": ";
            getline(cin,answers[j]);
        }   
        
        cout<<endl<<"Question "<<i+1<<": "<<questions[i]<<endl;
        for(int j=0;j<numAnswers;j++) {
            cout<<answers[j]<<endl;
        }
    }
}