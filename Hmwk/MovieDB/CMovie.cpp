/* 
 * File:   CMovie.h
 * Author: andrewguzman
 *
 * Created on March 12, 2023, 7:27 PM
 */

#include <iostream>     //I/O Library
#include <cstdlib>      //Random Number Generator, Setting Seed, etc...
#include <iomanip>      //Formatting Library
#include <fstream>      //Filestream Library
using namespace std;    //Libraries compiled under std

#include "CMovie.h"

CMovie::CMovie() {
    movies=new Movies;          //Declare the structures array
    
    movies->nMovies=100;          //Set the size of the structures
    
    movies->mvInfo=new MovieInfo[movies->nMovies];      //Allocate the array of structures
    
    for(int mv=0;mv<movies->nMovies;mv++) {    //Fill each of the MovieInfo structures
        movies->mvInfo[mv].mvName="Movie #"+to_string(mv+1);
        
        string dName="The Daniels "+to_string(mv+1); 
        const char *dirN=dName.c_str();           //string to c-string
        int nameSiz=strlen(dirN);                //need size to create char array dynamically
        movies->mvInfo[mv].dirName=new char[nameSiz];   //Dynamic char array allocated
        strcpy(movies->mvInfo[mv].dirName,dirN);
        
//        if(dirN[size]=='\0') cout<<"NULL"<<endl;
        
        movies->mvInfo[mv].runTime=120+(rand()%75);
        movies->mvInfo[mv].yearRel=1950+(rand()%73);
    }
}

CMovie CMovie::operator=(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;
    
    //Dynamically allocate the array of structures
    movies->mvInfo=new MovieInfo[movies->nMovies];
    
    //Now you can loop on the data as many times as it takes!
    for(int mv=0;mv<movies->nMovies;mv++){
        movies->mvInfo[mv].mvName=obj.movies->mvInfo[mv].mvName;
        
        int size=81;    //size needed to create char array dynamically
        movies->mvInfo[mv].dirName=new char[size];   //Dynamic char array allocated
        strcpy(movies->mvInfo[mv].dirName,"The Daniels ");
        
        movies->mvInfo[mv].yearRel=obj.movies->mvInfo[mv].yearRel;
        movies->mvInfo[mv].runTime=obj.movies->mvInfo[mv].runTime;
    }   
    
    return *this;
}

CMovie::CMovie(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies; 
    
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;
    
    //Dynamically allocate the array of structures
    movies->mvInfo=new MovieInfo[movies->nMovies];
    
    for(int movie=0;movie<movies->nMovies;movie++){
        movies->mvInfo[movie].mvName=obj.movies->mvInfo[movie].mvName;
        
        int size=81;            //need size to create char array dynamically
        movies->mvInfo[movie].dirName=new char[size];   //Dynamic char array allocated
        strcpy(movies->mvInfo[movie].dirName,obj.movies->mvInfo[movie].dirName);
        
        movies->mvInfo[movie].yearRel=obj.movies->mvInfo[movie].yearRel;
        movies->mvInfo[movie].runTime=obj.movies->mvInfo[movie].runTime;
    }   
}

CMovie::~CMovie() {
    //Clean up the dynamic stuff
    for(int mv=0;mv<movies->nMovies;mv++) {
        delete []movies->mvInfo[mv].dirName;    //De-allocate dynamically allocated
                                            //char array in each structure
    }
    delete [] movies->mvInfo;       //De-allocate array of structures
    delete movies;                  //De-allocate the final Movie structure    
}

void CMovie::display() {
    for(int mv=0;mv<movies->nMovies;mv++) {
        cout<<left<<endl;
        cout<<setw(11)<<"Movie: "<<movies->mvInfo[mv].mvName<<endl;
        cout<<setw(11)<<"Director: "<<movies->mvInfo[mv].dirName<<endl;
        cout<<setw(11)<<"Length: "<<movies->mvInfo[mv].runTime<<" Minutes"<<endl;
        cout<<setw(11)<<"Released: "<<movies->mvInfo[mv].yearRel<<endl;        
    }       
} 

void CMovie::wrtTxt(fstream &out) {
    for(int mv=0;mv<this->movies->nMovies;mv++) {
        out<<left<<endl;
        out<<setw(11)<<"Movie: "<<this->movies->mvInfo[mv].mvName<<endl;
        out<<setw(11)<<"Director: "<<this->movies->mvInfo[mv].dirName<<endl;
        out<<setw(11)<<"Length: "<<this->movies->mvInfo[mv].runTime<<" Minutes"<<endl;
        out<<setw(11)<<"Released: "<<this->movies->mvInfo[mv].yearRel<<endl;        
    }       
} 

void CMovie::wrtBin(fstream &out) {
    for(int mv=0;mv<movies->nMovies;mv++) {
        int mvSize,dirSize;       //size of string and char array
                
        //Write string
        mvSize=movies->mvInfo[mv].mvName.size();
        out.write((char *)&mvSize,sizeof(int));
        out.write(&movies->mvInfo[mv].mvName[0],mvSize*sizeof(char));
        //Write char array
        dirSize=strlen(movies->mvInfo[mv].dirName);
        out.write((char *)(&dirSize),sizeof(int));
        out.write((movies->mvInfo[mv].dirName),dirSize*sizeof(char));
        //Write integers
        out.write(reinterpret_cast<char *>(&movies->mvInfo[mv].runTime),sizeof(int));
        out.write(reinterpret_cast<char *>(&movies->mvInfo[mv].yearRel),sizeof(int));
    }
}

Movies* CMovie::readBin(fstream &in, int record) {
    char nameSiz, dirSize;      //Movie name size, director name size
    int mvSize;
    Movies *mv=nullptr;
    
    mv=new Movies;                 //Allocate Movies
    mv->mvInfo=new MovieInfo;        //Allocate structure in Movies
    
    nameSiz=mv->mvInfo->mvName.size();      //Store sizes
    mvSize=sizeof(Movies);
    
    in.seekg(record*mvSize,ios::beg);   //Set reading position
    
    //Need to read in number of bytes as well as the property for string and char array
    in.read(&nameSiz,sizeof(char)); 
    mv->mvInfo->mvName.resize(nameSiz);
    in.read(&mv->mvInfo->mvName[0],nameSiz);
    
    //Read in char array
    char *cArr; //Create new char array
    int cArrSiz;
    in.read((char * )&cArrSiz,sizeof(int));
    cArr=new char[cArrSiz];
    in.read(cArr,cArrSiz * sizeof(char));
//    
//    in.read(&dirSize,sizeof(char));
//    in.read(mv->mvInfo->dirName,dirSize*sizeof(char));
    
    in.read(reinterpret_cast<char *>(&mv->mvInfo->runTime),sizeof(int));
    in.read(reinterpret_cast<char *>(&mv->mvInfo->yearRel),sizeof(int));
    
    cout<<"Movie:"<<mv->mvInfo->mvName<<endl;

    return mv;
}