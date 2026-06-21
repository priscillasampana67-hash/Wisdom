#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int rank;
    double monthlySalary;
    double hours;

    cout <<"Enter your name: " <<endl;
    getline(cin, name);

    cout << "1. CEO" << endl;
    cout << "2. Manager" << endl;
    cout << "3. Personal Assistant" << endl;
    cout << "4. Clerk" << endl;

    cout << "Enter your rank: " << endl;
    cin >> rank;

    cout << "how many hours has " << name << " worked?" << endl;
    cin >> hours;

    if(rank == 1) {
        monthlySalary = 100000.0 / 12;
    } else if(rank == 2) {
        monthlySalary = 60000.0 / 12;
    } else if(rank == 3) {
        monthlySalary = 40000.0 / 12;
    } else if(rank == 4) {
        monthlySalary = 20000.0 / 12;
    } else {
        cout << "Invalid rank!" << endl;
        return 1;
    }

    double bonus;
    if(rank == 1) {
        bonus = 0;
    } else if(hours > 40) {
        double overtime = hours - 40;
        bonus = overtime * 100;
    } else {
        bonus = 0;
    }

double incomeTax = 0.04 * monthlySalary;
    double ssnit = 0.075 * monthlySalary;
    double welfare = 100;
    double totalDeductions = incomeTax + ssnit + welfare;
    double totalSalary = monthlySalary + bonus;
    
    cout <<"__________Priscilla's corp__________" << endl;
    cout << "Name: " << name << endl;
    cout << "MonthlySalary: $ " << monthlySalary << endl;
    cout << "Bonus: $ " << bonus << endl;
    cout << "IncomeTax: $ " << incomeTax << endl;
    cout << "SSNIT: $ " << ssnit << endl;
    cout << "Welfare: $ " << welfare << endl;
    cout << "TotalSalary: $ " << totalSalary << endl;
    cout << " Remaining Salary: $" << totalSalary - totalDeductions <<endl;

    return 0;

}