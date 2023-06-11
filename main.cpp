#include <iostream>
#include <windows.h>

using namespace std;

void deleteRow(int**& matrix, int& rows, int cols, int position) {
    if (position < 0 || position >= rows) {
        cout << "Некоректна позиція рядка" << endl;
        return;
    }

    int** temp = new int* [rows - 1];

    for (int i = 0; i < position; i++) {
        temp[i] = matrix[i];
    }

    for (int i = position + 1; i < rows; i++) {
        temp[i - 1] = matrix[i];
    }

    delete[] matrix[position];
    delete[] matrix;

    matrix = temp;
    rows--;
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
    cout << "Введіть позицію рядка для видалення: ";
    cin >> position;

    deleteRow(matrix, rows, cols, position);

    cout << "Матриця після видалення рядка:" << endl;
    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);

    system("pause");

    return 0;
}
