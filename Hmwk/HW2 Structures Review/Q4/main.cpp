/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 10, 2023 7:43PM
 * Purpose: Simulates a soft drink machine.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <string>
using namespace std;

//User Libraries  

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
struct Drink {
    string name;
    float cost;
    int nDrinks;
};

//Function Prototypes
void update(Drink &);
int calc(Drink &,int);
void display(Drink []);
void calcTotal(Drink []);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    //Create array of Drink structures
    int const SIZE=5;
    Drink drinks[SIZE];
    string choice,amt;
    int money,change=0,dIndx;

    //Initial Array of drink structures
    for(int i=0;i<SIZE;i++) {
        if(i==0) {
            drinks[i].name="Cola";
            drinks[i].cost=0.75;
            drinks[i].nDrinks=20;
        } else if(i==1) {
            drinks[i].name="Root Beer";
            drinks[i].cost=0.75;
            drinks[i].nDrinks=20;
        } else if(i==2) {
            drinks[i].name="Lemon-Lime";
            drinks[i].cost=0.75;
            drinks[i].nDrinks=20;
        } else if(i==3) {
            drinks[i].name="Grape Soda";
            drinks[i].cost=0.80;
            drinks[i].nDrinks=20;
        } else if(i==4) {
            drinks[i].name="Cream Soda";
            drinks[i].cost=0.80;
            drinks[i].nDrinks=20;
        }
    }


    //Map the Inputs to the Outputs
    
    //Display the Inputs and Outputs
    do {
        display(drinks);
        getline(cin,choice);
        if(choice!="Quit") {
            if(choice=="Cola") {
                getline(cin,amt);
                dIndx=0;
            } else if(choice=="Root Beer") {
                cout<<"Root Beer"<<endl;
                getline(cin,amt);
                dIndx=1;
            } else if(choice=="Lemon-Lime") {
                cout<<"Lemon-Lime"<<endl;
                getline(cin,amt);
                dIndx=2;
            } else if(choice=="Grape Soda") {
                cout<<"Grape Soda"<<endl;
                getline(cin,amt);
                dIndx=3;
            } else if(choice=="Cream Soda") {
                getline(cin,amt);
                dIndx=4;
            }
            money=stoi(amt);
            cout<<"Quit"<<endl;    
            cout<<calc(drinks[dIndx],money)<<endl;           
        }
        update(drinks[dIndx]);
    } while(choice!="Quit");
    
    cout<<"Quit"<<endl;
    calcTotal(drinks);   

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void update(Drink &data) {
    data.nDrinks--;
}

int calc(Drink &data,int money) {
    int change;
    
    if(money>data.cost*100) {
        change=money-(data.cost)*100;
    } else if(data.cost*100>money) {
        change=(data.cost)*100-money;
    } else change=0;
    
    return change;
}

void display(Drink data[]) {
    for(int i=0;i<5;i++) {
        int temp=data[i].cost*100;
        cout<<setw(11)<<left<<data[i].name
            <<setw(4)<<left<<temp
            <<data[i].nDrinks<<endl;
    }
}

void calcTotal(Drink data[]) {
    float tempCost=0;

    tempCost=data[0].cost+data[4].cost;

    cout<<tempCost*100<<endl;
}