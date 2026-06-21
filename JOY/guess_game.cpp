#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "=== Number Guessing Game ===" << endl;
    cout << "I'm Thinking Of A Number Between 1 and 100" << endl;

    do{
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again" << endl;
        }
        else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the number" << endl;
            cout << "Number of attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    return 0;



}