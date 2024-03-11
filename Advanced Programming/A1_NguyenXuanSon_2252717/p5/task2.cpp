#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void displayMatrix(int matrix[][COLS]) {
    cout << "Matrix:" << endl;
    cout << "=========" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // Matrix manually indicated
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Display the matrix
    displayMatrix(matrix);

    // Calculate the sum of all elements in the matrix
    int totalSum = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            totalSum += matrix[i][j];
        }
    }
    cout << "\nSum of all elements in the matrix: " << totalSum << endl;

    // Calculate the sum of all elements in each row
    cout << "Sum of all elements in each row:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0;
        for (int j = 0; j < COLS; ++j) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    // Calculate the sum of all elements in each column
    cout << "\nSum of all elements in each column:" << endl;
    for (int j = 0; j < COLS; ++j) {
        int colSum = 0;
        for (int i = 0; i < ROWS; ++i) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }

    // Calculate the sum of all elements in the main diagonal
    int mainDiagonalSum = 0;
    for (int i = 0; i < ROWS; ++i) {
        mainDiagonalSum += matrix[i][i];
    }
    cout << "\nSum of all elements in the main diagonal: " << mainDiagonalSum << endl;

    // Calculate the sum of all elements in the secondary diagonal
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < ROWS; ++i) {
        secondaryDiagonalSum += matrix[i][COLS - i - 1];
    }
    cout << "Sum of all elements in the secondary diagonal: " << secondaryDiagonalSum << endl;

    return 0;
}
