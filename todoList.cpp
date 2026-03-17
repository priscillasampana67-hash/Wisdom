#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct todolist
{
    int id;
    string task;
};

int ID;


void banner();
void addTask();
void showTask();
void searchTask();
void deleteTask();
void updateTask();
int main(){
    system("cls");
    while (true)
    {
        banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Show Task";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. Update Task";

        int choice;
        cout << "\n\tEnter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                // addTask();
                break;
                
            case 2:
                // showTask();
                break;
                
            case 3:
                // searchTask();
                break;
                
            case 4:
                // updateTask();
                break;

            case 5:
                // deleteTask();
            default:
                break;
        }
    }

    return 0;
}
void banner(){
    cout << "______________________________" << endl;
    cout << "\t    My Todo" << endl;
    cout << "_______________________________" << endl;
}

void addTask(){
    system("cls");
    banner();
    todolist todo;
    
    cout << "Enter new task: " <<endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout << "save? (y/n): ";
    cin >> save;
    if(save == 'y'){
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout << "\n" << ID;
        fout << "\n" << todo.task;
        fout.close();

        char more;
        cout << "Add more task? (y/n): ";
        cin >> more;

        if(more == 'y'){
            addTask();
        }
        else{
            system("cls");
            cout << "Added Successfully!" <<endl;
            return;
        }
    }
    system("cls");
}

void showTask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout << "Task: " <<endl;

    while (!fin.eof())
    {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if(todo.task != ""){
            cout << "\t" << todo.id << ": " << todo.task << endl;
        }
        else{
            cout << "\tEmpty!" << endl;
        }
    }
    fin.close();
    char exit;
    cout << "Enter? (y/n): ";
    cin >> exit;
    if(exit != 'y'){
        showTask();
    }

    void searchTask(){
        system("cls");
        banner();
        int id;
        cout << "Enter task id: ";
        cin >> id;
        todolist todo;
        ifstream fin("todo.txt");
        while (!fin.eof())
        {
            fin >> todo.id;
            fin.ignore();
            getline(fin, todo.task);
            
        }

    }
}