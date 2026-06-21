#include <iostream>
using namespace std;

const int MAX = 10;

void inputMatrix(int matrix[] [MAX], int rows, int columns);
void displayMatrix(int matrix[] [MAX], int rows, int columns);
void addMatrices(
    int A[] [MAX],
    int B[] [MAX],
    int C[] [MAX],
    int rows,
    int columns
);

int main() {
    int rows, columns;
    cout << "Enter rows: " << endl;
    cin >> rows;

     cout << "Enter columns: " << endl;
    cin >> columns;

    int A[MAX] [MAX];
    int B[MAX] [MAX];
    int C[MAX] [MAX];

    cout << "Enter Matrix A: " << endl;
    inputMatrix(A, rows, columns);

    cout << "Enter Matrix B: " << endl;
    inputMatrix(B, rows, columns);

    addMatrices(A, B, C, rows, columns);

    cout << "Result: " << endl;
    displayMatrix(C, rows, columns);

    cout << "Result (A + B): " << endl;
    displayMatrix(C, rows, columns);

    return 0;
}

    void inputMatrix(int matrix[] [MAX], int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "Matrix [" << i <<"][" << j << "]: ";
                cin >> matrix[i] [j]; 
            }
        }
    }


    void displayMatrix(int matrix[] [MAX], int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "matrix[" << i <<"][" << j << "] = " << endl;
            }
            cout << endl;
        }
    }

    void addMatrices(
        int A[] [MAX],
        int B[] [MAX],
        int C[] [MAX],
        int rows,
        int columns
    ) {
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                C[i] [j] = A[i] [j] + B[i] [j];
            }
        }
    }



