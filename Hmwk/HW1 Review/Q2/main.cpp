/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 2, 2023 @ 1:00 PM
 * Purpose: Input the size of the 2 dimensional character array, then sort by row.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <cstring>  //strlen(),strcopy(),strcmp()
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Structure Definitions

//Function Prototypes
int read(char [][COLMAX],int &);    //Outputs row and columns detected from input
void sort(char [][COLMAX],int,int); //Sort by row
void print(const char [][COLMAX],int,int);  //Print the sorted 2D array
void swap(char [],char [],int);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);

    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }

    //Exit the code
    return 0;
}

int read(char array2D[][COLMAX],int &rows) {
    int colNum,     //Number of columns
        totCol;     //Total number of columns allowed
    
    totCol=0;
    
    //Read in 2D array
    for(int i=0;i<rows;i++) {
        cin>>array2D[i];        //reading in row by row
    }
    
    //For each row in the 2D array, determine total number of columns
    for(int i=0;i<rows;i++) {
        colNum=1;           //number of columns = 1 at start of each new row
        while(array2D[i][colNum]!='\0') {
            colNum++;       //Increase colNum until we reach null terminator
        }
        
        if(colNum>totCol) totCol=colNum;        //Determine the max column size
    }
    
    return totCol;
}

void sort(char array2D[][COLMAX],int rows,int cols) {
    //Sort the string by row
    for(int i=0;i<rows-1;i++) {
        for(int j=i+1;j<rows;j++) {
            //Use strcmp to compare the first array and second array
            if(strcmp(array2D[i],array2D[j])>0) {
                swap(array2D[i],array2D[j],cols);
            }
        }
    }
}

void swap(char row1Arr[],char row2Arr[],int cols) {
    //Temp char array
    char *temp=new char[cols];
    //Copy c strings with strcpy for swapping
    strcpy(temp,row1Arr);
    strcpy(row1Arr,row2Arr);
    strcpy(row2Arr,temp);
}

void print(const char array2D[][COLMAX],int rows,int cols) {
    for(int i=0;i<rows;i++) {
        cout<<array2D[i]<<endl;
    }
}