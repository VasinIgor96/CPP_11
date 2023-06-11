#include <iostream>
#include <windows.h>

using namespace std;

void addRow(int**& matrix, int& rows, int cols, const int* row, int position) {
    int** temp = new int* [rows + 1];

    for (int i = 0; i <= rows; i++) {
        if (i < position)
            temp[i] = matrix[i];
        else if (i > position)
            temp[i] = matrix[i - 1];
        else
            temp[i] = new int[cols];
    }

    for (int i = 0; i < cols; i++) {
        temp[position][i] = row[i];
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

    int position;
    cout << "Введіть позицію для додавання рядка: ";
    cin >> position;

    int* newRow = new int[cols];
    cout << "Введіть новий рядок:" << endl;
    for (int i = 0; i < cols; i++) {
        cin >> newRow[i];
    }

    addRow(matrix, rows, cols, newRow, position);

    cout << "Матриця після додавання рядка:" << endl;
    printMatrix(matrix, rows, cols);

    delete[] newRow;
    deleteMatrix(matrix, rows);

    system("pause");

    return 0;
}
