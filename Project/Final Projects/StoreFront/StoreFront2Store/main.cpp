/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 17, 2023 @ 1:36 AM
 * Purpose: v2: Store class
 */

//System and User Libraries
#include "Headers.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int num;
    
    cout<<"Enter Number of Items in Store: ";
    cin>>num;
    cin.ignore();
    Store store(num);
//    store.display();
    cout<<"Saving to Binary File..."<<endl;
    store.saveBin("Store.dat");
    cout<<"Reading from Binary File..."<<endl;
    store.readBin("Store.dat");
    
    store.deleteItem(1);
    store.display();
    
    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}

