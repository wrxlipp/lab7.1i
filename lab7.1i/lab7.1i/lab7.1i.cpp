#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ��������� ������� �� ���������� ����� � �������� �������
void CreateMatrix(int** matrix, int rows, int cols, int Low, int High) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// ������� ��� ��������� �������
void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// ������� ��� ���������� ���� �� ������� ��������, �� ���������� �������
void Calc(int** matrix, int rows, int cols, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // ����� ��� ��������: ��, ��� �������� ������
            if (!(matrix[i][j] > 0 && matrix[i][j] % 2 == 0)) {
                sum += matrix[i][j];
                count++;
                matrix[i][j] = 0; // ����� �������� �� 0
            }
        }
    }
}

// ������� ��� ���������� �������
void SortMatrix(int** matrix, int rows, int cols) {
 
    sort(matrix, matrix + rows, [cols](int* row1, int* row2) {
        if (row1[0] != row2[0]) return row1[0] > row2[0]; // ���������� �� ������ ���������� ��������
        if (row1[1] != row2[1]) return row1[1] < row2[1]; // ���� ������ �������� ���������, ���� �� ������ ����������
        return row1[3] > row2[3]; // ���� ������ � ������ �������, ���� �� ��������� ���������
        });
}

// ������� �������
int main() {
    srand(static_cast<unsigned>(time(0))); // ����������� ���������� ���������� �����

    const int rows = 8;
    const int cols = 6;
    const int Low = -26;
    const int High = 23;

    // ��������� �������� �������
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // ��������� �������
    CreateMatrix(matrix, rows, cols, Low, High);

    // ��������� ��������� �������
    cout << "Initial matrix:\n";
    PrintMatrix(matrix, rows, cols);

    // ���������� ������� �� ���� ��������, �� ���������� �������
    int count = 0, sum = 0;
    Calc(matrix, rows, cols, count, sum);

    // ��������� ����������
    cout << "Number of elements: " << count << endl;
    cout << "Sum of elements: " << sum << endl;

    // ��������� ������������ �������
    cout << "Modified matrix:\n";
    PrintMatrix(matrix, rows, cols);

    // ���������� �������
    SortMatrix(matrix, rows, cols);

    // ��������� ����������� �������
    cout << "Sorted matrix:\n";
    PrintMatrix(matrix, rows, cols);

    // ��������� ���'��
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
