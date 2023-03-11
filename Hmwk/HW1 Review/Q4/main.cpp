/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on 3/2/23 at 9:00pm
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even,vector<int> &odd) {
    int size,input;
    
    //Get values as input
    cout<<"Input the number of integers to input."<<endl;
    cin>>size;
    cout<<"Input each number."<<endl;
    for(int i=0;i<size;i++) {
        cin>>input;
        if(input%2==0) {        //is even
            even.push_back(input);
        } else {
            odd.push_back(input);
        }
    }
}

void copy(vector<int> even,vector<int> odd,int arr[][COLMAX]) {
    int evenSize=even.size(),oddSize=odd.size();
    
    //Copy even numbers into col 0 of array
    for(int i=0;i<evenSize;i++) {
        arr[i][0]=even[i];
    }
    
    //Copy odd numbers into col 1 of array
    for(int i=0;i<oddSize;i++) {
        arr[i][1]=odd[i];
    }
}

void prntVec(vector<int> even,vector<int> odd,int width) {
    int i=0,j=0;    //even and odd counters
    
    cout<<setw(width)<<"Vector"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
    while(i<odd.size() && j<even.size()) { //while values are all even or odd
        cout<<setw(width*2)<<even[i]<<setw(width)<<odd[j]<<endl;
        i++;
        j++;
    }
    
    while(i<even.size()) {  //while there are more even values to add, continue to output
        cout<<setw(2*width)<<even[i]<<setw(width)<<" "<<endl;
        i++;
    }
    
    while(j<odd.size()) {  //while there are more odd values to add, continue to output
        cout<<setw(3*width)<<odd[j]<<endl;
        j++;
    }
}

void prntAry(const int arr[][COLMAX],int evnSize,int oddSize,int width) {
    int minSize,maxSize;
    
    if(evnSize>oddSize) {       //if there are more even values than odd
        minSize=oddSize;
        maxSize=evnSize;
        
        cout<<setw(width)<<"Array"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
        for(int i=0;i<minSize;i++) {
            cout<<setw(2*width)<<arr[i][0]<<setw(width)<<arr[i][1]<<endl;
        }
        for(int i=minSize;i<maxSize;i++) {
            cout<<setw(2*width)<<arr[i][0]<<setw(width)<<" "<<endl;
        }
    } else {                //else if there are more odd values than even
        minSize=evnSize;
        maxSize=oddSize;
        
        cout<<setw(width)<<"Array"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
        for(int i=0;i<minSize;i++) {
            cout<<setw(2*width)<<arr[i][0]<<setw(width)<<arr[i][1]<<endl;
        }
        for(int i=minSize;i<maxSize;i++) {
            cout<<setw(3*width)<<arr[i][1]<<endl;
        }
    }
}