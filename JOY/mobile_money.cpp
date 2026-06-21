#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
void createAccount(string &name, string &phone, string &network, int &pin, bool &accountCreated);
bool verifyPin(int savedPin);
void showMenu();
void transferMoney(double &balance);
void payBill(double &balance);
void buyAirtime(double &balance);
void checkBalance(double balance);
void withdrawCash(double &balance);
void depositMoney(double &balance);

// Global variables
double balance = 0.0;

int main()
{
    string name, phone, network;
    int pin;
    bool accountCreated = false;
    int choice;

    cout << "=====================================\n";
    cout << "   MOBILE MONEY TRANSACTION SYSTEM\n";
    cout << "=====================================\n";

    while (true)
    {
        cout << "\nMAIN MENU\n";
        cout << "1. Create Account\n";
        cout << "2. Transfer Money\n";
        cout << "3. Pay Bill\n";
        cout << "4. Buy Airtime/Bundles\n";
        cout << "5. Check Balance\n";
        cout << "6. Withdraw Cash\n";
        cout << "7. Deposit Money\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            createAccount(name, phone, network, pin, accountCreated);
            break;

        case 2:
            if (!accountCreated)
            {
                cout << "Please create an account first.\n";
            }
            else if (verifyPin(pin))
            {
                transferMoney(balance);
            }
            break;

        case 3:
            if (!accountCreated)
            {
                cout << "Please create an account first.\n";
            }
            else if (verifyPin(pin))
            {
                payBill(balance);
            }
            break;

        case 4:
            if (!accountCreated)
            {
                cout << "Please create an account first.\n";
            }
            else if (verifyPin(pin))
            {
                buyAirtime(balance);
            }
            break;

        case 5:
            if (!accountCreated)
            {
                cout << "Please create an account first.\n";
            }
            else if (verifyPin(pin))
            {
                checkBalance(balance);
            }
            break;

        case 6:
            if (!accountCreated)
            {
                cout << "Please create an account first.\n";
            }
            else if (verifyPin(pin))
            {
                withdrawCash(balance);
            }
            break;

        case 7:
            if (!accountCreated)
            {
                cout << "Please create an account first.\n";
            }
            else
            {
                depositMoney(balance);
            }
            break;

        case 8:
            cout << "Thank you for using Mobile Money.\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

// Function definitions

void createAccount(string &name, string &phone, string &network,
                   int &pin, bool &accountCreated)
{
    if (accountCreated)
    {
        cout << "Account already exists.\n";
        return;
    }

    cout << "\nEnter full name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter phone number: ";
    getline(cin, phone);

    int option;

    cout << "\nSelect Network\n";
    cout << "1. MTN\n";
    cout << "2. Telecel\n";
    cout << "3. AirtelTigo\n";

    do
    {
        cout << "Enter option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            network = "MTN";
            break;

        case 2:
            network = "Telecel";
            break;

        case 3:
            network = "AirtelTigo";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (option < 1 || option > 3);

    do
    {
        cout << "Set a 4-digit PIN: ";
        cin >> pin;

        if (pin < 1000 || pin > 9999)
        {
            cout << "PIN must be exactly 4 digits.\n";
        }

    } while (pin < 1000 || pin > 9999);

    accountCreated = true;

    cout << "\nAccount created successfully.\n";
    cout << "Welcome, " << name << "!\n";
}

bool verifyPin(int savedPin)
{
    int enteredPin;
    int attempts = 3;

    while (attempts > 0)
    {
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == savedPin)
        {
            return true;
        }

        attempts--;

        cout << "Incorrect PIN. Attempts left: "
             << attempts << endl;
    }

    cout << "Transaction cancelled.\n";
    return false;
}

void transferMoney(double &balance)
{
    string recipient;

    double amount;

    cout << "Enter recipient number: ";
    cin >> recipient;

    cout << "Enter amount: GH¢";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance.\n";
        return;
    }

    balance -= amount;

    cout << fixed << setprecision(2);
    cout << "Transfer successful.\n";
    cout << "New balance: GH¢" << balance << endl;
}

void payBill(double &balance)
{
    string biller;
    double amount;

    cout << "Enter bill name: ";
    cin.ignore();
    getline(cin, biller);

    cout << "Enter amount: GH¢";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance.\n";
        return;
    }

    balance -= amount;

    cout << "Bill paid successfully to "
         << biller << ".\n";

    cout << "Remaining balance: GH¢"
         << fixed << setprecision(2)
         << balance << endl;
}

void buyAirtime(double &balance)
{
    double amount;

    cout << "Enter airtime/bundle amount: GH¢";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance.\n";
        return;
    }

    balance -= amount;

    cout << "Purchase successful.\n";
    cout << "Remaining balance: GH¢"
         << fixed << setprecision(2)
         << balance << endl;
}

void checkBalance(double balance)
{
    cout << fixed << setprecision(2);
    cout << "Wallet Balance: GH¢"
         << balance << endl;
}

void withdrawCash(double &balance)
{
    double amount;

    cout << "Enter withdrawal amount: GH¢";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance.\n";
        return;
    }

    balance -= amount;

    cout << "Withdrawal successful.\n";
    cout << "Remaining balance: GH¢"
         << fixed << setprecision(2)
         << balance << endl;
}

void depositMoney(double &balance)
{
    double amount;

    cout << "Enter deposit amount: GH¢";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount.\n";
        return;
    }

    double reward = amount * 0.02; // 2% bonus

    balance += amount + reward;

    cout << fixed << setprecision(2);

    cout << "Deposit successful.\n";
    cout << "Reward bonus: GH¢" << reward << endl;
    cout << "Current balance: GH¢" << balance << endl;
    
}