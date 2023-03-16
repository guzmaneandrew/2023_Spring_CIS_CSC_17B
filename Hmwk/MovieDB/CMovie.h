/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   CMovie.h
 * Author: andrewguzman
 *
 * Created on March 12, 2023, 7:27 PM
 */

#ifndef CMOVIE_H
#define CMOVIE_H

#include "Movies.h"

class CMovie {
    private:
        Movies *movies;     //Pointer to dynamic Movies structure
    public:
        CMovie();           //Constructor
        CMovie(const CMovie &); //Copy Constructor
        CMovie operator=(const CMovie &);        //Overloaded Equality Operator
        ~CMovie();          //Destructor
        void display();     //Display structures
        void wrtTxt(fstream &);      //Write to text file
        void wrtBin(fstream &);      //Write to binary file
        Movies* readBin(fstream &,int);     //Read from a binary file
};

#endif /* CMOVIE_H */

