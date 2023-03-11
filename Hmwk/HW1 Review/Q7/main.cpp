/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 2, 2023 @ 1:54 PM
 * Purpose: Input something, output it reversed with some modifications
 * Note: Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <string>
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [], unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short, signed short &);//Output true,short or false
short subtrct(signed short, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible." << endl;
    cout<<"Input a number in the range of an unsigned short" << endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits, unShort)){
        cout << "No Conversion Possible" << endl;
        return 0;
    }
    
//    cout<<"unsigned short: "<<unShort<<endl;
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort, snShort)){
        cout << "No Conversion Possible" << endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort = subtrct(snShort, 999);
    
    //Output the result
    cout << snShort << endl;
    
    //Exit
    return 0;
}

bool  inRange(const char array[], unsigned short &unShort) {
    char newArr[5];
    int range=5,len=strlen(array),ledZeros,indx=0,number;
    
    //Check that input array only contains digits
    for(int i=0;i<len;i++) {
        if(int(array[i])<48||int(array[i])>=58) {
            return false;
        }
    }
    
    //Fill in leading zeros
    ledZeros=range-len;
    for(int i=0;i<ledZeros;i++) {
        newArr[i]='0';
    }
    
    //Fill remaining numbers
    for(int i=0;i<(range-ledZeros);i++) {
        newArr[i+ledZeros]=array[i];
    }
    
//    for(int i=0;i<5;i++) {
//        cout<<newArr[i]<<endl;
//    }
    
    //Convert newArr to int to check if in range of unsigned short
    number=atoi(newArr);
//    cout<<number<<endl;
    
    if(number>=1&&number<=65535) {
        unShort=static_cast<unsigned short>(number);
        return true;
    } else {
        return false;
    }
    
}

bool  reverse(unsigned short rvUShrt, signed short &sgnShrt) {
    char revNum[5];
    string num=to_string(rvUShrt);
    int number=0,length=num.length(),revIndx=num.length()-1, revLen;
    
    //Reverse the number
    for(int i=0;i<length;i++) {
        revNum[revIndx]=num[i];
        revIndx--;
    }
    
    revLen=num.length();
    for(int i=revLen;i<5;i++) {
        revNum[i]='0';
    }
    
//    for(int i=0;i<5;i++) {
//        cout<<revNum[i];
//    }
    
    //Convert to int to check if in range of signed short
    number=atoi(revNum);

    //Check if it's in range of a signed short
    if(number>=-32768&&number<=32767) {
        sgnShrt=static_cast<signed short>(number);
        return true;
    } else {
        return false;
    }
}

short subtrct(signed short sgnSrt, int num) {
    short tempNum;
    
    tempNum=sgnSrt-num;
    
    if(tempNum>=0) {
       tempNum=sgnSrt-num;
    } else {
       tempNum=sgnSrt;
    }
    
    return tempNum;
}
