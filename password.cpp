#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;

    cout << "Enter your password: ";
    cin >> password;

    if (password.length() >= 8) {
        cout << "Password is long enough." << endl;
    } else {
        cout << "Password is too short. It must be at least 8 characters long." << endl;
    }

    return 0;
}