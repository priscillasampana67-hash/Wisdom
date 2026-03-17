#include <iostream>
#include <fstream>
using namespace std;

class temp{

    string id, name, author;
    fstream file;
    public:
    void addBook();
    void showAll();
    void extractBook();
    
}obj;

int mai() {

    char Choice;
    cout << "__________" <<endl;
    cout <<"1-Show All Books"<<endl;
    cout << "2-Extract Book"<<endl;
    cout << "3-Add books(ADMIN)" <<endl;
    cout << "4-Exit"<<endl;
    cout << "__________" <<endl; 
    cout << "Enter Your Choice : " <<endl;
    cin >> Choice ;

    switch(Choice){
        case '1' :
            cin.ignore();
            obj.showAll();
        break;
        case '2' :
            cin.ignore();
            obj.extractBook();
        break;
        case '3' :
            cin.ignore();
            obj.addBook();
        break;
        case '4':
        return 0;
        break;
        default:
            cout <<"Invalid choice...!";
    }


    return 0;
}
void temp :: addBook(){
    cout <<"\nEnter Book ID : ";
    getline(cin,id);
    cout <<"Enter Book Name : ";
    getline(cin,name);
    cout <<"Enter BOok's Author : ";
    getline(cin,author);

    file.open("bookData.txt",ios :: out | ios ::app);
    file <<id<<"*"<<name<<"*"<<author <<endl;
    file.close();
}
void temp :: showAll(){
    file.open("bookData.txt",ios ::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
        cout <<"\n\n";
        cout <<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" <<endl;
         while(!file.eof()){
            cout <<"\t\t "<<id<<" \t\t\t "<<author <<endl;
           }
           file.close();
}
void temp :: extractBook(){

    showAll();
    cout <<"Enter Book Id :: ";
    getline(cin,id);

    file.open("bookData.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

    
    cout <<"\n\n";
    cout <<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" <<endl;
    while(!file.eof()){
        if(id  == id){
            cout<<"\t\t "<<id<<"\t\t\t "<<name<<" \t\t\t "<<author<<endl;
            cout <<"Book Extracted Successfuly...!";
        }
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    }
    file.close();
    
}