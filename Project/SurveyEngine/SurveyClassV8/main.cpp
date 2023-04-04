/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 2, 2023 @ 4:50 PM
 * Purpose: v8) Class in separate .h and .cpp files
 */

//System Libraries

//User Libraries
#include "Headers.h"
#include "Survey.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int num;
    string title;
    
    cout<<"Enter Survey Title: "<<endl;
    getline(cin,title);
    cout<<"Enter How Many Questions: ";
    cin>>num;
    cin.ignore();
    Survey *survey1=new Survey(title,num);        //Create an instance of the CSurvey class
   
    
    //Initialize Variables
    
    //Display the Inputs and Outputs
    survey1->display();
    survey1->writeToFile(survey1);
    
    Survey *survey2=new Survey;
    survey2->readFromFile();
    
    //Clean Up the Dynamic Stuff
    

    //Exit 
    return 0;
}