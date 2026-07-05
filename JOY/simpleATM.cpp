#include <iostream>
using namespace std;

int main(){
    int pin = 1234;
    int enteredPin;
    double balance = 1000;
    int choice;
    double amount;

    cout <<"====== SIMPLE ATM ======" << endl;

    cout << "Enter your PIN: " << endl;
    cin >> enteredPin;

    if (enteredPin != pin) {
        cout << "WRONG PIN! Access denied." << endl;
        return 0;
    }
    
    cout << "PIN correct. Welcome!" << endl;

    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Exit" << endl;
        cout << " Enter choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        cout << "Your balance is GHC " << balance << endl;
            break;
        case 2:
        cout << "Enter amount to withdraw: " << endl;
        cin >> amount;
            if (amount > balance) {
                cout << "Insufficient funds!" << endl;
            } else {
                balance -= amount;
                cout << "Please collect your cash." << endl;
            }
            break;

            case 3:
        cout << "Enter amount to deposit: " << endl;
        cin >> amount;
        balance += amount;
        cout << "Deposit successful!" << endl;
            break;

            case 4:
        cout << "Thank you for using ATM. Goodbye!"  << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
