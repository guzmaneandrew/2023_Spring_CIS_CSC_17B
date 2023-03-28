/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 12, 2023 @ 7:25 PM
 * Purpose: Class in .h and .cpp files
 */

//System Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
#include <fstream>   //Filestream Library
using namespace std; //Libraries compiled under std

//User Libraries
#include "CMovie.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes Here

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    fstream txtFile,binFile;
    int nMovies,record,input;
    CMovie *moviesDB=nullptr;
    
    //Initialize variables
    moviesDB=new CMovie;
    
    //Open the text and binary files
    txtFile.open("moviesDB.txt",ios::out);
    binFile.open("moviesDB.bin",ios::in|ios::out|ios::binary|ios::trunc);
    
    //Write to text and binary files
    moviesDB->wrtTxt(txtFile);
    moviesDB->display();
    moviesDB->wrtBin(binFile);
    
    //Read back in the structure and print out record
    cout<<"Enter a Record to Find (1-100): ";
    cin>>input;
    cout<<"Record "<<input<<" = "<<endl;
    moviesDB->readBin(binFile,input-1);

    //Close the files
    txtFile.close();
    binFile.close();
                
    //Exit 
    return 0;
}