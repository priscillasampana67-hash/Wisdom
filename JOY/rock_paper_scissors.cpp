#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int playerChoice, computerChoice;

    cout << "===== Rock, Paper, Scissors ====" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;

    cout << "Enter your choice (1 - 3): " << endl;
    cin >> playerChoice;

    computerChoice = rand() % 3 + 1;

    cout << "Computer Chose: ";
    switch (computerChoice) {
        case 1:
            cout << "Rock" << endl;
            break;
        case 2:
            cout << "Paper" << endl;
            break;
        case 3:
            cout <<"Scissors" <<endl;
            break;
    }
    if(playerChoice == computerChoice) {
        cout << "It's a draw!" << endl;
    }
    else if((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2)) {
        cout << "You Win!" << endl;
    }
    else {
        cout << "Computer Wins!" << endl;
    }

    return 0;
}