#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int player = 2;   // Player starts in the middle
    int enemy = rand() % 5;
    char move;

    while (true) {
        system("cls");   // Use "clear" instead if you're on Linux/macOS

        // Draw game
        for (int i = 0; i < 5; i++) {
            if (i == enemy)
                cout << " E ";
            else
                cout << " . ";
        }
        cout << endl;

        for (int i = 0; i < 5; i++) {
            if (i == player)
                cout << " A ";
            else
                cout << " . ";
        }
        cout << endl;

        cout << "\nControls: A = Left, D = Right, F = Fire, Q = Quit\n";
        cin >> move;

        if (move == 'a' || move == 'A') {
            if (player > 0)
                player--;
        }
        else if (move == 'd' || move == 'D') {
            if (player < 4)
                player++;
        }
        else if (move == 'f' || move == 'F') {
            if (player == enemy) {
                cout << "\n💥 Enemy Destroyed!\n";
                enemy = rand() % 5;
            } else {
                cout << "\n❌ Missed!\n";
            }
            system("pause");
        }
        else if (move == 'q' || move == 'Q') {
            break;
        }
    }

    cout << "Game Over!\n";

    return 0;
}