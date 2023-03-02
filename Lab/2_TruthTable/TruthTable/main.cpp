/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: February 27, 2023 @ 11:43 PM
 * Purpose: To tell the truth
*/
//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y, x1, y1, x2, y2,
            x3, y3, x4, y4;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    //Read in all the rows
    int count=0;
    while(cin>>x>>y&&count++<4) {   //reads in multiple lines
            cout<<(x?'T':'F')<<" "
                <<(y?'T':'F')<<"  "
                <<(!x?'T':'F')<<"  "
                <<(!y?'T':'F')<<"   "
                <<(x&&y?'T':'F')<<"    "
                <<(x||y?'T':'F')<<"   "
                <<(x!=y?'T':'F')<<"    "
                <<((x!=y)!=x?'T':'F')<<"     "
                <<((x!=y)!=y?'T':'F')<<"       "
                <<(!(x&&y)?'T':'F')<<"      "
                <<(!x||!y?'T':'F')<<"        "
                <<(!(x||y)?'T':'F')<<"      "
                <<(!x&&!y?'T':'F')<<endl;
    }
    cout<<endl;
    
    // cin >> x1 >> y1;
    // cin >> x2 >> y2;
    
    // if(x1==1 && y1==0 && x2==0 && y2==1) {
    //     //First Row
    //     x=true;
    //     y=false;
    //     cout<<(x?'T':'F')<<" "
    //         <<(y?'T':'F')<<"  "
    //         <<(!x?'T':'F')<<"  "
    //         <<(!y?'T':'F')<<"   "
    //         <<(x&&y?'T':'F')<<"    "
    //         <<(x||y?'T':'F')<<"   "
    //         <<(x!=y?'T':'F')<<"    "
    //         <<((x!=y)!=x?'T':'F')<<"     "
    //         <<((x!=y)!=y?'T':'F')<<"       "
    //         <<(!(x&&y)?'T':'F')<<"      "
    //         <<(!x||!y?'T':'F')<<"        "
    //         <<(!(x||y)?'T':'F')<<"      "
    //         <<(!x&&!y?'T':'F')<<endl;
        
    //     //Second Row
    //     x=false;
    //     y=true;
    //     cout<<(x?'T':'F')<<" "
    //         <<(y?'T':'F')<<"  "
    //         <<(!x?'T':'F')<<"  "
    //         <<(!y?'T':'F')<<"   "
    //         <<(x&&y?'T':'F')<<"    "
    //         <<(x||y?'T':'F')<<"   "
    //         <<(x!=y?'T':'F')<<"    "
    //         <<((x!=y)!=x?'T':'F')<<"     "
    //         <<((x!=y)!=y?'T':'F')<<"       "
    //         <<(!(x&&y)?'T':'F')<<"      "
    //         <<(!x||!y?'T':'F')<<"        "
    //         <<(!(x||y)?'T':'F')<<"      "
    //         <<(!x&&!y?'T':'F')<<endl;
    //     cout<<endl;
        
    // } else if(x1==1 && y1==1 && x2==1 && y2==0) {
    //     cin >> x3 >> y3;
    //     cin >> x4 >> y4;
        
    //     if(x3==0 && y3==1 && x4==0 && y4==0) {
    //          //First Row
    //         x=true;
    //         y=true;
    //         cout<<(x?'T':'F')<<" "
    //             <<(y?'T':'F')<<"  "
    //             <<(!x?'T':'F')<<"  "
    //             <<(!y?'T':'F')<<"   "
    //             <<(x&&y?'T':'F')<<"    "
    //             <<(x||y?'T':'F')<<"   "
    //             <<(x!=y?'T':'F')<<"    "
    //             <<((x!=y)!=x?'T':'F')<<"     "
    //             <<((x!=y)!=y?'T':'F')<<"       "
    //             <<(!(x&&y)?'T':'F')<<"      "
    //             <<(!x||!y?'T':'F')<<"        "
    //             <<(!(x||y)?'T':'F')<<"      "
    //             <<(!x&&!y?'T':'F')<<endl;

    //         //Second Row
    //         x=true;
    //         y=false;
    //         cout<<(x?'T':'F')<<" "
    //             <<(y?'T':'F')<<"  "
    //             <<(!x?'T':'F')<<"  "
    //             <<(!y?'T':'F')<<"   "
    //             <<(x&&y?'T':'F')<<"    "
    //             <<(x||y?'T':'F')<<"   "
    //             <<(x!=y?'T':'F')<<"    "
    //             <<((x!=y)!=x?'T':'F')<<"     "
    //             <<((x!=y)!=y?'T':'F')<<"       "
    //             <<(!(x&&y)?'T':'F')<<"      "
    //             <<(!x||!y?'T':'F')<<"        "
    //             <<(!(x||y)?'T':'F')<<"      "
    //             <<(!x&&!y?'T':'F')<<endl;

    //         //Third Row
    //         x=false;
    //         y=true;
    //         cout<<(x?'T':'F')<<" "
    //             <<(y?'T':'F')<<"  "
    //             <<(!x?'T':'F')<<"  "
    //             <<(!y?'T':'F')<<"   "
    //             <<(x&&y?'T':'F')<<"    "
    //             <<(x||y?'T':'F')<<"   "
    //             <<(x!=y?'T':'F')<<"    "
    //             <<((x!=y)!=x?'T':'F')<<"     "
    //             <<((x!=y)!=y?'T':'F')<<"       "
    //             <<(!(x&&y)?'T':'F')<<"      "
    //             <<(!x||!y?'T':'F')<<"        "
    //             <<(!(x||y)?'T':'F')<<"      "
    //             <<(!x&&!y?'T':'F')<<endl;

    //         // //Fourth Row
    //         x=false;
    //         y=false;
    //         cout<<(x?'T':'F')<<" "
    //             <<(y?'T':'F')<<"  "
    //             <<(!x?'T':'F')<<"  "
    //             <<(!y?'T':'F')<<"   "
    //             <<(x&&y?'T':'F')<<"    "
    //             <<(x||y?'T':'F')<<"   "
    //             <<(x!=y?'T':'F')<<"    "
    //             <<((x!=y)!=x?'T':'F')<<"     "
    //             <<((x!=y)!=y?'T':'F')<<"       "
    //             <<(!(x&&y)?'T':'F')<<"      "
    //             <<(!x||!y?'T':'F')<<"        "
    //             <<(!(x||y)?'T':'F')<<"      "
    //             <<(!x&&!y?'T':'F')<<endl;
    //             cout<<endl;
    //     }
    // }

    //Exit
    return 0;
}



