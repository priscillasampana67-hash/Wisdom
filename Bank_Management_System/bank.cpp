#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){

    int accNo;
    char name[25];
    char Fname[25];
    char cnic[25];
    char P_no[25];
    char email[25];
    float amount;

    srand(time(0));
    accNo=rand()*rand()*rand()*rand();

    cout<<"Enter Your Name :: ";
    cin>>name;

    cout <<"Enter Your Father name :: ";
    cin>>Fname;

    cout <<"Enter Your cnic :: ";
    cin>>cnic;

    cout<<"Enter Your phone no. :: ";
    cin>>P_no;

    cout<<"Enter Your email :: ";
    cin>>email;

    cout<<"Enter Youor amount :: ";
    cin>>amount;

    cout<<accNo<<" This is your account number... \n";
    cout<<"Please save it ";

    fstream file;

    file.open("data.txt",ios::out|ios::app);
    file<<accNo<<"\t"<<name<<"\t"<<cnic<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
    file.close();

    return 0;
}