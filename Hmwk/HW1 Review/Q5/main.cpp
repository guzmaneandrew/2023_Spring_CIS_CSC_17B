/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created 3/3/2023, 11:45AM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int arr[][COLMAX],int &row,int &col) {
    cout<<"Input a table and output the Augment row,col and total sums."<<endl;
    cout<<"First input the number of rows and cols. <20 for each"<<endl;
    cin>>row>>col;
    
    cout<<"Now input the table."<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>arr[i][j];
        }
    }
}

void sum(const int arr[][COLMAX],int rows,int cols,int augArr[][COLMAX]) {
    int sum=0;
    
    //Create augArr and copy arr to augArr
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            augArr[i][j]=arr[i][j];
        }
    }
    
    //Calculate sums of rows and add sum to new col on same row
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            sum+=arr[i][j];
            if(j==cols-1) augArr[i][j+1]=sum;
        }
        sum=0;
    }
    
    //Calculate sums of cols and add sum to new row on same col
    for(int j=0;j<cols;j++) {
        for(int i=0;i<rows;i++) {
            sum+=arr[i][j];
            if(i==rows-1) augArr[i+1][j]=sum;
        }
        sum=0;
    }
    
    //Calculate sum of last row in augRow
    for(int i=0;i<cols;i++) {
        sum+=augArr[rows][i];
    }
    augArr[rows][cols]=sum;
}

void print(const int arr[][COLMAX],int rows,int cols,int width) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout<<setw(width)<<arr[i][j];
        }
        cout<<endl;
    }
}