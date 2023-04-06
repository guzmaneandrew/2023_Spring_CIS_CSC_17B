/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: April 5, 2023 3:50 PM
 * Purpose: v9) Class in separate files.
 *              Survey class
 */

//System Libraries

//User Libraries
#include "Headers.h"
#include "SurveyQ.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare & Initialize Variables
    SurveyQ survQ;

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    survQ.display();
    survQ.deleteResponse(3);
    survQ.display();
    survQ.deleteResponse(6);
    survQ.display();
    
    //Clean Up the Dynamic Stuff

    //Exit 
    return 0;
}