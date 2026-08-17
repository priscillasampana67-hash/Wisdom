#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess, attempts = 0;

    cout << "=====================================\n";
    cout << "     NUMBER GUESSING PUZZLE GAME\n";
    cout << "=====================================\n";
    cout << "I have chosen a number between 1 and 100.\n";
    cout << "Can you guess it?\n\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again.\n\n";
        }
        else {
            cout << "\n🎉 Congratulations!\n";
            cout << "You guessed the correct number: " << secretNumber << endl;
            cout << "Attempts: " << attempts << endl;

            if (attempts <= 5)
                cout << "Excellent! You're a puzzle master.\n";
            else if (attempts <= 10)
                cout << "Well done! Nice guessing.\n";
            else
                cout << "You finally got it. Keep practicing!\n";
        }

    } while (guess != secretNumber);

    return 0;
}