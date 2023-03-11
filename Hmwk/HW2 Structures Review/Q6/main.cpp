/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 7,2023 10:36PM
 * Purpose: Store movie data for a year
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
struct Movie {
    string title;
    string director;
    string yrRel;
    string time;
};


//Function Prototypes
void getData(Movie [],int);
void print(Movie [],int);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int numMovs;
    
    //Initialize Variables
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, "
        <<"Year Released, and the Running Time in (minutes).\n"<<endl;
    cin>>numMovs;
    Movie movies[numMovs];
    
    //Create structure varaibles and store values in
    getData(movies,numMovs);
    
    //Map the Inputs to the Outputs


    //Display the Inputs and Outputs
    print(movies,numMovs);

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void getData(Movie a[],int numMovs) {
    cin.ignore();
    for(int i=0;i<numMovs;i++) {
        getline(cin,a[i].title);
        getline(cin,a[i].director);
        getline(cin,a[i].yrRel);
        getline(cin,a[i].time);
    }
}

void print(Movie a[],int numMovs) {
    for(int i=0;i<numMovs;i++) {
        cout<<setw(11)<<left<<"Title:"<<a[i].title<<endl;
        cout<<setw(11)<<left<<"Director:"<<a[i].director<<endl;
        cout<<setw(11)<<left<<"Year:"<<a[i].yrRel<<endl;
        cout<<setw(11)<<left<<"Length:"<<a[i].time<<endl;
        if(i!=numMovs-1) cout<<endl;
    }
}