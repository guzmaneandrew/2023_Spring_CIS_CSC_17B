/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: March 10, 2023 7:25PM
 * Purpose: Store information on household expenses and display spending report.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions
struct MonthlyBudget {
    float rent=500.00;
    float util=150.00;
    float home=65.00;
    float trans=50.00;
    float food=250.00;
    float medical=30.00;
    float insure=100.00;
    float media=150.00;
    float clothes=75.00;
    float misc=50.00;
    float ovrUndr=0.0;
};

//Function Prototypes
void getData(MonthlyBudget &);
void report(const MonthlyBudget &,MonthlyBudget &);
void print(const MonthlyBudget &);
void check(float,float,MonthlyBudget &);


//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    cout<<fixed<<setprecision(2);
    //Declare Variables
    MonthlyBudget goal,budget;

    //Initial Variables
    getData(budget);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    report(goal,budget);

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void getData(MonthlyBudget &budget) {
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>budget.rent;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>budget.util;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>budget.home;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>budget.trans;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>budget.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>budget.medical;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>budget.insure;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>budget.media;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>budget.clothes;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>budget.misc;
}

void report(const MonthlyBudget &goal,MonthlyBudget &exp) {
    cout<<"Housing ";
    check(goal.rent,exp.rent,exp);
    cout<<"Utilities ";
    check(goal.util,exp.util,exp);
    cout<<"Household Expenses ";
    check(goal.home,exp.home,exp);
    cout<<"Transportation ";
    check(goal.trans,exp.trans,exp);
    cout<<"Food ";
    check(goal.food,exp.food,exp);
    cout<<"Medical ";
    check(goal.medical,exp.medical,exp);
    cout<<"Insurance ";
    check(goal.insure,exp.insure,exp);
    cout<<"Entertainment ";
    check(goal.media,exp.media,exp);
    cout<<"Clothing ";
    check(goal.clothes,exp.clothes,exp);
    cout<<"Miscellaneous ";
    check(goal.misc,exp.misc,exp);
    if(exp.ovrUndr>0)      cout<<"You were $"<<exp.ovrUndr<<" under budget";
    else if(exp.ovrUndr<0) cout<<"You were $"<<exp.ovrUndr*-1<<" over budget";
    else if(exp.ovrUndr==0)cout<<"You were $0 under/over budget";
}

void check(float goal,float exp,MonthlyBudget &spent) {
    if(goal>exp) {
        cout<<"Under"<<endl;
        spent.ovrUndr+=(goal-exp);
    } else if(goal<exp) {
        cout<<"Over"<<endl;
        spent.ovrUndr-=(exp-goal);
        
    } else if(goal==exp)cout<<"Even"<<endl;
}

void print(const MonthlyBudget &budget) {
    cout<<budget.rent<<endl;
    cout<<budget.util<<endl;
    cout<<budget.home<<endl;
    cout<<budget.trans<<endl;
    cout<<budget.food<<endl;
    cout<<budget.medical<<endl;
    cout<<budget.insure<<endl;
    cout<<budget.media<<endl;
    cout<<budget.clothes<<endl;
    cout<<budget.misc<<endl;
}