/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float num1, num2, num3, num4;
    
    //Initialize or input data here
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << right;  //format outputs to right of fields
    cout << setw(9) <<  num1;
    cout << setw(10) << setprecision(1) << fixed << showpoint << num1;
    cout << setw(10) << setprecision(2) << fixed << showpoint << num1 << endl;
    
    cout << right << setw(9) << setprecision(0) << noshowpoint << num2; //clear the showpoint format flag
    cout << setw(10) << setprecision(1) << fixed << showpoint << num2;
    cout << setw(10) << setprecision(2) << fixed << showpoint << num2 << endl;
    
    cout << right << setw(9) << setprecision(0) << noshowpoint << num3;
    cout << setw(10) << setprecision(1) << fixed << showpoint << num3;
    cout << setw(10) << setprecision(2) << fixed << showpoint << num3 << endl;
    
    cout << right << setw(9) << setprecision(0) << noshowpoint << num4;
    cout << setw(10) << setprecision(1) << fixed << showpoint << num4;
    cout << setw(10) << setprecision(2) << fixed << showpoint << num4;
    
    //Clean up allocated memory here
    //Exit stage left
    return 0;
}