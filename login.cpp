#include <iostream>
#include <string>

using namespace std;

int main()
{
    string username, password;
    string loginUser, loginPass;

    // Registration
    cout << "===== CREATE ACCOUNT =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    cout << "\nAccount created successfully!\n" << endl;


    // Login
    cout << "===== LOGIN =====" << endl;

    cout << "Username: ";
    cin >> loginUser;

    cout << "Password: ";
    cin >> loginPass;


    // Authentication
    if (loginUser == username && loginPass == password)
    {
        cout << "\nLogin successful!" << endl;
        cout << "Welcome, " << username << "!" << endl;
    }
    else
    {
        cout << "\nInvalid username or password." << endl;
    }

    return 0;
}