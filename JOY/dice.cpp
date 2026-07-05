#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    char choice;

    do {
        int dice = rand() % 6 + 1; // Generate a number from 1 to 6

        cout << "You rolled: " << dice << endl;

        cout << "Roll again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}