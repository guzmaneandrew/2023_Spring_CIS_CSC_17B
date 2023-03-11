/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 10, 2023 @ 10:33 PM
 * Purpose: Store weather data for a year
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
struct Weather {
    string month;
    float rain;     //Total rain
    int highest;   //Highest temp
    int lowest;   //Lowest temp
    int avgTemp;  //Avg temp
};

//Function Prototypes
void getData(Weather[],int);
void avgRain(Weather[],int);
void avgAvg(Weather[],int);
void highest(Weather[],int);
void lowest(Weather[],int);
void print(Weather[]);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    cout<<setprecision(0);
    //Declare Variables
    const int NUM_MONTHS=12;
    Weather year[NUM_MONTHS];
    int hiTemp,lowTemp;

    //Get weather data for the year
    getData(year,NUM_MONTHS);
    
    //Map the Inputs to the Outputs
    //Calculate average monthly rainfall
    avgRain(year,NUM_MONTHS);
    //Calculate lowest temp for the year
    lowest(year,NUM_MONTHS);
    //Calculate highest temp for the year
    highest(year,NUM_MONTHS);
    //Calculate average of average temps for the year
    avgAvg(year,NUM_MONTHS);

    //Display the Inputs and Outputs
    //print(year);

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void getData(Weather a[],int NUM_MONTHS) {
    for(int i=0;i<NUM_MONTHS;i++) {
        cin>>a[i].month>>a[i].rain>>a[i].lowest>>a[i].highest;
    }
}

void avgRain(Weather a[],int NUM_MONTHS) {
    float avg, total=0.0;
    
    for(int i=0;i<NUM_MONTHS;i++) {
        total+=a[i].rain;
    }
    avg=total/NUM_MONTHS;
    
    cout<<setprecision(2);
    cout<<"Average Rainfall "<<avg<<" inches/month"<<endl;
}

void avgAvg(Weather m[],int NUM_MONTHS) {
    float yearAvg=0,monthAvg;
    
    for(int i=0;i<NUM_MONTHS;i++) {
        monthAvg=(m[i].lowest+m[i].highest)/2;
        m[i].avgTemp=monthAvg;
    }
    
    for(int i=0;i<NUM_MONTHS;i++) {
        yearAvg+=m[i].avgTemp;
    }
    
    yearAvg/=NUM_MONTHS;
    
    cout<<"Average Temperature for the year "<<round(yearAvg)<<" Degrees Fahrenheit"<<endl;
}

void lowest(Weather m[],int NUM_MONTHS) {
    string lowMnth;
    int lowest;
    
    for(int i=0;i<NUM_MONTHS;i++) {
        if(i==0) {
            lowest=m[i].lowest;
            lowMnth=m[i].month;
        }
        if(m[i].lowest<lowest) {
            lowest=m[i].lowest;
            lowMnth=m[i].month;
        }
    }
    
    cout<<"Lowest  Temperature "<<lowMnth<<"  "<<lowest<<" Degrees Fahrenheit"<<endl;
}

void highest(Weather m[],int NUM_MONTHS) {
    string hiMnth;
    int highest;
    
    for(int i=0;i<NUM_MONTHS;i++) {
        if(i==0) {
            highest=m[i].highest;
            hiMnth=m[i].month;
        }
        if(m[i].highest>highest) {
            highest=m[i].highest;
            hiMnth=m[i].month;
        } 
    }
    
    cout<<"Highest Temperature "<<hiMnth<<"  "<<highest<<" Degrees Fahrenheit"<<endl;
}

void print(Weather a[]) {
    for(int i=0;i<12;i++) {
        cout<<a[i].month<<" "<<a[i].rain<<" "<<a[i].highest<<" "<<a[i].lowest;
    }
}