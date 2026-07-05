#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 7;

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#'},
    {'#','P',' ',' ','#','E','#'},
    {'#',' ','#',' ','#',' ','#'},
    {'#',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#'}
};

int playerRow = 1;
int playerCol = 1;

void displayMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char move;

    while (true) {
        displayMaze();

        cout << "\nMove (W=Up, S=Down, A=Left, D=Right): ";
        cin >> move;

        int newRow = playerRow;
        int newCol = playerCol;

        switch (toupper(move)) {
            case 'W': newRow--; break;
            case 'S': newRow++; break;
            case 'A': newCol--; break;
            case 'D': newCol++; break;
            default:
                cout << "Invalid move!\n";
                continue;
        }

        // Check wall
        if (maze[newRow][newCol] == '#') {
            cout << "You hit a wall!\n";
            continue;
        }

        // Check exit
        if (maze[newRow][newCol] == 'E') {
            cout << "🎉 Congratulations! You escaped the maze!\n";
            break;
        }

        // Move player
        maze[playerRow][playerCol] = ' ';
        playerRow = newRow;
        playerCol = newCol;
        maze[playerRow][playerCol] = 'P';
    }

    return 0;
}