/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 7,2023 11:00PM
 * Purpose: Uses a structure to store data on a company division.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
struct Division {
    string name;
    float q1Sales;
    float q2Sales;
    float q3Sales;
    float q4Sales;
    float totalSls;   //Total annual sales
    float avgSls;     //Avg quarter sales  
};

//Function Prototypes
void getData(Division *);
void calcTot(Division *); //Calculate total annual sales
void calcAvg(Division *); //Calculate avg quarter sales
void print(const Division *);

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    Division north,south,east,west;

    //Initial Variables
    //Set name for structs
    north.name="North";
    west.name="West";
    east.name="East";
    south.name="South";
    
    //Get sales data for division
    getData(&north);
    //Calculate the total annual sales
    calcTot(&north);
    //Calculate avg total sales
    calcAvg(&north);
    //Print total annual sales and avg quarterly sales
    print(&north);
    cout<<endl;
    
    //Get sales data for division
    getData(&west);
    //Calculate the total annual sales
    calcTot(&west);
    //Calculate avg total sales
    calcAvg(&west);
    //Print total annual sales and avg quarterly sales
    print(&west);
    cout<<endl;

    //Get sales data for division
    getData(&east);
    //Calculate the total annual sales
    calcTot(&east);
    //Calculate avg total sales
    calcAvg(&east);
    //Print total annual sales and avg quarterly sales
    print(&east);
    cout<<endl;
    
    //Get sales data for division
    getData(&south);
    //Calculate the total annual sales
    calcTot(&south);
    //Calculate avg total sales
    calcAvg(&south);
    //Print total annual sales and avg quarterly sales
    print(&south);
    
    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void getData(Division *d) {
    cout<<d->name<<endl;
    
    //Get q1 sales
    do{
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>d->q1Sales;
    }while(d->q1Sales<0);
    
    //Get q2 sales
    do{
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>d->q2Sales;
    }while(d->q2Sales<0);
    
    //Get q3 sales
    do{
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>d->q3Sales;
    }while(d->q3Sales<0);
    
    //Get q4 sales
    do{
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>d->q4Sales;
    }while(d->q4Sales<0);
}

void calcTot(Division *d) {
    float total;
    
    total=(d->q1Sales)+(d->q2Sales)+(d->q3Sales)+(d->q4Sales);
    d->totalSls=total;
}

void calcAvg(Division *d) {
    float avg;
    
    avg=(d->q1Sales+d->q2Sales+d->q3Sales+d->q4Sales)/4;
    d->avgSls=avg;
}

void print(const Division *d) {
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Total Annual sales:$"<<d->totalSls<<endl;
    cout<<"Average Quarterly Sales:$"<<d->avgSls;
}