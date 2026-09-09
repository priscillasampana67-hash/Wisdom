#include <iostream>
#include <fstream>
using namespace std;

class temp{
string rollNum, name, fName, address, searrch;
    fstream file;
    public:
    void addStu();
    void viewStu();
    void searchStu();
}obj;

int main(){
    
    char choice;
    cout <<"_____________________" <<endl;
    cout <<"1- Add Student Record" <<endl;
    cout <<"2- View All Student Record" <<endl;
    cout <<"3- Search Student Record" <<endl;
    cout <<"4- Exit" <<endl;
    cout <<"______________________" <<endl;
    cin >>choice;

    switch(choice){
        case '1' :
            obj.addStu();
        break;
        case '2' :
            obj.viewStu();
        break;
        case '3' :
            obj.searchStu();
        
        break;
        case '4' :
            return 0;
        break;
        default :
        cout <<"Invalid Choice...!";
    }


}

void temp :: addStu(){

    cout <<"Enter Student Roll Number :: " <<endl;
    getline(cin,rollNum);
    cout <<"Enter Student Name :: " <<endl;
    getline(cin,name);
    cout <<"Enter Student Father Name :: " <<endl;
    getline(cin,fName);
    cout <<"Enter Student Adress :: " <<endl;
    getline(cin,address);
    
    file.open("stuData.txt",ios :: out | ios :: app);
    file<<rollNum<<"*" <<endl;
    file<<name<<"*" <<endl;
    file<<fName<<"*" <<endl;
    file<<address<<endl;
    file.close();
}

void temp :: viewStu(){

    file .open("stuData.txt",ios :: in);
    getline(file,rollNum,'*') ;
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        cout <<"\n";
        cout <<"Student Roll Number :: "<<rollNum;
        cout <<"Student Name :: "<<name;
        cout <<"Student Father Name :: "<<fName;
        cout <<"Student Address :: "<<address;

        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
    }
    file.close();
}

void temp :: searchStu(){
    string searchID;
    cout <<"Enter Student Roll Number :: ";
    getline(cin,rollNum);

    file.open("stuData.txt",ios :: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        if(rollNum == searchID){
            cout <<"Student Roll Number :: " <<rollNum;
            cout <<"Student Name :: " <<name;
            cout <<"Student Father Name :: " <<fName;
            cout <<"Student Address :: " <<address;
        }
        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');

    }
    file.close();
}
