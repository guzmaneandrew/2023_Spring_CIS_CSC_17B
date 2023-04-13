/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Headers.h
 * Author: andrewguzman
 *
 * Created on April 5, 2023, 7:59 PM
 */

#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, setting seed, etc....
#include <iomanip>    //Formatting Library
#include <vector>     //Vector library
#include <fstream>    //Filestream library
#include <cstring>    //C string library
#include <sstream>    //Stringstream library
using namespace std; //Libraries compiled under std

#include "Question.h"
#include "Survey.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
//const int QRSIZE = 100; //max size of question and response
//const int TSIZE = 50; //max size of title
const int RSIZE = 10; //max number of response options per question
const int SSIZE = 10; //max number of survey questions in a survey

#endif /* HEADERS_H */

