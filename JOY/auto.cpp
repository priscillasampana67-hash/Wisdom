#include <iostream>
using namespace std;

int main() {
    auto choice = 0;
    auto num1 = 0.0;
    auto num2 = 0.0;
    auto result = 0.0;

    cout << "===== SIMPLE CALCULATOR =====" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;

    cout << "\nEnter your choice (1-4): ";
    cin >> choice;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result = " << result << endl;
            break;

        case 2:
            result = num1 - num2;
            cout << "Result = " << result << endl;
            break;

        case 3:
            result = num1 * num2;
            cout << "Result = " << result << endl;
            break;

        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}