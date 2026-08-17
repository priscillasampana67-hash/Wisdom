```cpp
#include <iostream>
using namespace std;

// Display the game board
void displayBoard(char board[3][3]) {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n";
    cout << "\n";
}

// Check if a player has won
bool checkWinner(char board[3][3], char player) {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    return false;
}

// Check if the board is full
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

int main() {

    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char player = 'X';
    int choice;
    int row, col;

    cout << "=========================\n";
    cout << "      TIC TAC TOE\n";
    cout << "=========================\n";

    cout << "Player 1: X\n";
    cout << "Player 2: O\n";

    while (true) {

        displayBoard(board);

        cout << "Player " << player << ", choose a position (1-9): ";
        cin >> choice;

        // Convert position to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if choice is valid
        if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Choose a number from 1 to 9.\n";
            continue;
        }

        // Check if position is already occupied
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That position is already taken!\n";
            continue;
        }

        // Place player's symbol
        board[row][col] = player;

        // Check for winner
        if (checkWinner(board, player)) {
            displayBoard(board);
            cout << "🎉 Player " << player << " wins!\n";
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}