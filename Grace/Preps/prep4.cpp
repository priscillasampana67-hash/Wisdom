#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout <<"Enter two numbers: ";
    cin >> a >> b;

    try {
        if (b == 0) {
            throw "cannot divide by zero";
        }
        cout << "Result = " << a / b;
    }
    catch (const char* message) {
        cout << "Error: " << message;
    }
    return 0;

}