/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match;                          //Index of single match
    int matches[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
//    srch1(sntnce,pattern,match);
    srchAll(sntnce,pattern,matches);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(matches);
    
    //Exit
    return 0;
}

int srch1(const char sntnce[],const char pattern[],int match) {
    char tmpWrd[strlen(pattern)];
    int index;
    int count=0;
    
    //Search for one occurrence of the pattern in the sentence
    for(int i=0;i<strlen(sntnce);i++) {
        if(sntnce[i]==pattern[0]) { //Look for first letter from pattern in sentence
            cout<<i<<endl;
            cout<<strlen(pattern)<<endl;
            for(int j=i,k=0;k<strlen(pattern);j++,k++) {
                tmpWrd[k]=sntnce[j];
            }
        }
    }
    
    //Check if word following first letter found matches pattern

    //Print
//    for(int i=0;i<1;i++) {
//        cout<<tmpWrd[i];
//    }
    
    return index;
}

void srchAll(const char sntnce[],const char pattern[],int matches[]) {
    char tmpWrd[strlen(pattern)];
    int index=0;
    bool match;
    
    //Initialize matches indexes to invaid index -1
    for(int i=0;i<81;i++) {
        matches[i]=-1;
    }
    
    //Search for occurrences of the pattern in the sentence
    for(int i=0;i<strlen(sntnce);i++) {
        //Search for first letter from pattern in sentence
        if(sntnce[i]==pattern[0]) {
            for(int j=i,k=0;k<strlen(pattern);j++,k++) {
                if(sntnce[j]==pattern[k]) {
                    tmpWrd[k]=sntnce[j];
                }
            }
            
            //Check if tmpWrd extracted from sentence matches the pattern
            match=strncmp(tmpWrd,pattern,strlen(pattern));
            if(match==0) {
                matches[index]=i;   //If match, add index to array
                index++;
            }
        }
    }
}

void print(const char words[]) {
    for(int i=0;i<strlen(words);i++) {
        cout<<words[i];
    }
    cout<<endl;
}

void print(const int matches[]) {
    int index=0;

    while(matches[index]!=-1) {
        cout<<matches[index]<<endl;
        index++;
    }
    
    //If index never updates, there were no matches
    if(index==0) {
        cout<<"None"<<endl;
    }
}