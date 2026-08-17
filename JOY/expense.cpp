#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void addExpense() {
    string name;
    double amount;

    cout << "\nEnter expense name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter amount (GHC): ";
    cin >> amount;

    ofstream file("expenses.txt", ios::app);

    if (file.is_open()) {
        file << name << "|" << amount << endl;
        file.close();
        cout << "Expense added successfully!\n";
    } else {
        cout << "Error opening file.\n";
    }
}

void viewExpenses() {
    ifstream file("expenses.txt");

    string name;
    double amount;
    double total = 0;

    cout << "\n========== EXPENSES ==========\n";

    while (getline(file, name, '|') && file >> amount) {
        file.ignore();

        cout << left << setw(20) << name
             << " GHC " << fixed << setprecision(2)
             << amount << endl;

        total += amount;
    }

    file.close();

    cout << "------------------------------\n";
    cout << "Total: GHC " << fixed << setprecision(2)
         << total << endl;
}

int main() {
    int choice;

    do {
        cout << "\n====== EXPENSE TRACKER ======\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                cout << "Thank you for using Expense Tracker!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}