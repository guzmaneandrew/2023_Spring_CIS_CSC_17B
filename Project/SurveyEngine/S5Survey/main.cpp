/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 8, 2023 @ 10:44 PM
 * Purpose: v5) Modify previous implementations of Survey class to implement
 * new Question class
 */

//System Libraries
#include "Headers.h"


//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    Survey survey("this is title", 1);

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    survey.display();
    cout << "Writing to binary..." << endl;
    survey.writeBin();
    cout << "Reading from binary... and creating new Survey" << endl;
    Survey *newSurv=survey.readBin();
    newSurv->display();

    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}
