#include <iostream>
#include <fstream>
using namespace std;

class temp{
    string userName, Email, Password;
    fstream file;
    public :
    void login();
    void signUp();
    void forgotPassword();
}obj;
int main() {
char choice;
cout << " \n1- login";
cout << " \n2- Sign-up";
cout << " \n3- Forgot password";
cout << " \n4- Exit";
cout << " \nEnter your choice :: ";
cin >> choice;

switch(choice){
    case '1':
        obj.login();
     break;
    case '2':
        obj.signUp();
     break;
    case '3':
        obj.forgotPassword();
     break;
    case '4':
     return 0;
     break;
        default:
            cout << "Invalid Selection...!";

    }
}
void temp :: signUp(){
    cout <<" \nEnter Your user Name :: ";
getline(cin,userName);
    cout <<"Enter Your Email Address :: ";
    getline(cin,Email);
    cout <<"Enter Your Password :: ";
    getline(cin,Password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}
void temp:: login() {
    string searchName,searchpassword,searchEmail;
    cout<<"__________LOGIN_________" <<endl;
    cout<<"Enter Your User Name :: " <<endl;
    getline(cin,searchName);
    cout<<"Enter YOur password :: " <<endl;
    getline(cin,searchpassword);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(Password == searchpassword){
                cout<<"\nAccount Login Succesfull...!";
                cout<<"\nUsername :: " <<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }else{
                cout<<"Password is incorrect...!";
            }
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
    file.close();
}
void temp :: forgotPassword(){
    cout<<"\nEnter Your UserName :: ";
    getline(cin,userName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin,Email);

    file.open("loginData.txt",ios ::   in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while(!file.eof()){
        if(userName == userName){
            if(Email == Email){

                cout<<"\nAccount Found...!"<<endl;
                cout<<"Yoour Password ::"<<Password<<endl;
            }else{
                cout<<"Not found...!\n";
            }
        }else{
            cout<<"\nNot found...!\n";
        }
    }
}
