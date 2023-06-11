#include <iostream>
#include <windows.h>

using namespace std;

void addRowToBeginning(int**& matrix, int& rows, int cols, const int* row) {
    int** temp = new int* [rows + 1];

    temp[0] = new int[cols];
    for (int i = 0; i < cols; i++) {
        temp[0][i] = row[i];
    }

    for (int i = 1; i < rows + 1; i++) {
        temp[i] = matrix[i - 1];
    }

    delete[] matrix;
    matrix = temp;
    rows++;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Початкова матриця:" << endl;
    printMatrix(matrix, rows, cols);

    int* newRow = new int[cols];
    cout << "Введіть новий рядок:" << endl;
    for (int i = 0; i < cols; i++) {
        cin >> newRow[i];
    }

    addRowToBeginning(matrix, rows, cols, newRow);

    cout << "Матриця після додавання рядка:" << endl;
    printMatrix(matrix, rows, cols);

    delete[] newRow;
    deleteMatrix(matrix, rows);

    system("pause");

    return 0;
}
