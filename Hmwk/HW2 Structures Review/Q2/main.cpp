/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 7, 2023 12:30PM
 * Purpose: Store weather data for a particular month
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries  

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
enum Month { 
    JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE,
    JULY, AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER
};

//Structure Definitions
struct WeatherData {
    float rain;
    float high;
    float low;
    float avgTemp;
};

//Function Prototypes
void getData(WeatherData &);
float totRain(WeatherData[],int);
float avgRain(WeatherData[],int);
float avgTemp(WeatherData[],int);
float hiTemp(WeatherData[],int,int &);
float lowTemp(WeatherData[],int,int &);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    const int MONTHS=12;
    //Create of WeatherData structures
    WeatherData year[MONTHS];
    int hiMnth,lowMnth;
    float highest,lowest;

    //Initial Variables
    //Set Month for each weather data structure in array
//    for(int i=0;i<MONTHS;i++) {
//        year[i].month=(Month)i;
//    }

    //Map the Inputs to the Outputs
    for(int i=JANUARY;i<=JUNE;i++) {
        getData(year[i]);
    }

    //Display the Inputs and Outputs
    //Avg monthly rain
    cout<<"Average monthly rainfall:"<<avgRain(year,MONTHS)<<endl;
    
    //Highest temp and month
    highest=hiTemp(year,MONTHS,hiMnth);
    cout<<"High Temp:"<<highest<<endl;

    //Lowest temp and month
    lowest=lowTemp(year,MONTHS,lowMnth);
    cout<<"Low Temp:"<<lowest<<endl;
    
    //Avg monthly temp
    cout<<"Average Temp:"<<avgTemp(year,MONTHS);
    
    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void getData(WeatherData &data) {
    //Get total rain for month
    cout<<"Enter the total rainfall for the month:"<<endl;
    cin>>data.rain;
    
    //Get high temp
    cout<<"Enter the high temp:"<<endl;
    cin>>data.high;
    
    //Input validation
    while(data.high<-100||data.high>140) {
        cout<<"Error: Temperature is Out of Range.\n";
        cout<<"\tHigh Temperature: ";
        cin>>data.high;
    }
    
    //Get low temp
    cout<<"Enter the low temp:"<<endl;
    cin>>data.low;
    
    //Input validation
    while(data.low<-100||data.low>140) {
        cout<<"Error: Temperature is Out of Range.\n";
        cout<<"\tLow Temperature: ";
        cin>>data.low;
    }
    //Calculate avg temp
    data.avgTemp=(data.high+data.low);
}

float totRain(WeatherData data[],int months) {
    float total=0;
    
    //Get total of all rain members
    for(int i=0;i<months;i++) {
        total+=data[i].rain;
    }
    
    return total;
}

float avgRain(WeatherData data[],int months) { 
    //Calculate avg by diving total/month
    return totRain(data,months)/months;
}

float avgTemp(WeatherData data[],int months) {
    float avgTot=0, avgAvg;
    
    //Get total of all avg temps
    for(int i=0;i<months;i++) {
        avgTot+=data[i].avgTemp;
    }
    
    //Calculate avg of the avg
    avgAvg=avgTot/months;
    
    return avgAvg;
}

float hiTemp(WeatherData data[],int months,int &hiMonth) {
    //Set the first months as month with highest temp
    float highest=data[0].high;
    
    //Look for highest temp in the array
    for(int i=0;i<months;i++) {
        if(data[i].high>highest) {
            //Set new highest temp value
            highest=data[i].high;
            //Set highest month
            hiMonth=i+1;
        }
    }
    
    return highest;
}

float lowTemp(WeatherData data[],int months,int &loMonth) {
    //Set the lowest months as month with highest temp
    float lowest=data[0].low;
    
    //Look for lowest temp in the array
    for(int i=0;i<months;i++) {
        if(data[i].low<lowest) {
            //Set new lowest temp value
            lowest=data[i].low;
            //Set lowest month
            loMonth=i+1;
        }
    }
    
    return lowest;
}
