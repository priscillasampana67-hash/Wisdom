#include <iostream>
#include <vector>
using namespace std;

class Student {
    private:
    int id;
    string name;
    int age;

    public:
    Student(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "_____________________" << endl;
    }

    int getId() {
        return id;
    }
};

int main() {
    vector<Student> student;

    student.push_back(Student(1, "Ama", 20));
    student.push_back(Student(2, "Kojo", 21));

    cout << "Student Records" << endl;

    for(int i =0; i < student.size(); i++) {
        student[i].display();
    }

    return 0;
}