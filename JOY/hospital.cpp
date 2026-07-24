#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Patient Class
class Patient {
private:
    int id;
    string name;
    int age;
    string disease;

public:
    Patient(int pid, string pname, int page, string pdisease) {
        id = pid;
        name = pname;
        age = page;
        disease = pdisease;
    }

    int getID() {
        return id;
    }

    void display() {
        cout << "\nPatient ID: " << id << endl;
        cout << "Name      : " << name << endl;
        cout << "Age       : " << age << endl;
        cout << "Disease   : " << disease << endl;
    }
};

// Hospital Class
class Hospital {
private:
    vector<Patient> patients;

public:
    void addPatient() {
        int id, age;
        string name, disease;

        cout << "\nEnter Patient ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Disease: ";
        getline(cin, disease);

        patients.push_back(Patient(id, name, age, disease));

        cout << "\nPatient Added Successfully!\n";
    }

    void displayPatients() {
        if (patients.empty()) {
            cout << "\nNo patients found.\n";
            return;
        }

        cout << "\n===== Patient Records =====\n";

        for (int i = 0; i < patients.size(); i++) {
            patients[i].display();
            cout << "---------------------------\n";
        }
    }

    void searchPatient() {
        int id;
        cout << "\nEnter Patient ID to Search: ";
        cin >> id;

        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].getID() == id) {
                cout << "\nPatient Found!\n";
                patients[i].display();
                return;
            }
        }

        cout << "\nPatient Not Found.\n";
    }
};

int main() {
    Hospital hospital;
    int choice;

    do {
        cout << "\n============================";
        cout << "\n HOSPITAL MANAGEMENT SYSTEM";
        cout << "\n============================";
        cout << "\n1. Add Patient";
        cout << "\n2. Display All Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hospital.addPatient();
                break;

            case 2:
                hospital.displayPatients();
                break;

            case 3:
                hospital.searchPatient();
                break;

            case 4:
                cout << "\nThank you for using the Hospital Management System!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}