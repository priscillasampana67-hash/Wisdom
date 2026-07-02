#include <iostream>
using namespace std;

int main() {
    int choice;
    float balance = 1000.00, amount;

    do {
        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your balance is: GH¢" << balance << endl;
                break;

            case 2:
                cout << "Enter amount to deposit: GH¢";
                cin >> amount;
                balance += amount;
                cout << "Deposit successful!" << endl;
                break;

            case 3:
                cout << "Enter amount to withdraw: GH¢";
                cin >> amount;

                if (amount <= balance) {
                    balance -= amount;
                    cout << "Withdrawal successful!" << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
                break;

            case 4:
                cout << "Thank you for using the ATM!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}