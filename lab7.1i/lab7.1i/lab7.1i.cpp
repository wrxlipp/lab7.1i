#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для створення матриці із випадкових чисел в заданому діапазоні
void CreateMatrix(int** matrix, int rows, int cols, int Low, int High) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Функція для виведення матриці
void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Функція для обчислення суми та кількості елементів, що відповідають критерію
void Calc(int** matrix, int rows, int cols, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Умови для елементів: всі, крім додатних парних
            if (!(matrix[i][j] > 0 && matrix[i][j] % 2 == 0)) {
                sum += matrix[i][j];
                count++;
                matrix[i][j] = 0; // Заміна елементів на 0
            }
        }
    }
}

// Функція для сортування матриці
void SortMatrix(int** matrix, int rows, int cols) {
 
    sort(matrix, matrix + rows, [cols](int* row1, int* row2) {
        if (row1[0] != row2[0]) return row1[0] > row2[0]; // Сортування за першим стовпчиком спадання
        if (row1[1] != row2[1]) return row1[1] < row2[1]; // Якщо перший стовпчик однаковий, сорт за другим зростанням
        return row1[3] > row2[3]; // Якщо перший і другий однакові, сорт за четвертим спаданням
        });
}

// Основна функція
int main() {
    srand(static_cast<unsigned>(time(0))); // Ініціалізація генератора випадкових чисел

    const int rows = 8;
    const int cols = 6;
    const int Low = -26;
    const int High = 23;

    // Створення динамічної матриці
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Генерація матриці
    CreateMatrix(matrix, rows, cols, Low, High);

    // Виведення початкової матриці
    cout << "Initial matrix:\n";
    PrintMatrix(matrix, rows, cols);

    // Обчислення кількості та суми елементів, що відповідають критерію
    int count = 0, sum = 0;
    Calc(matrix, rows, cols, count, sum);

    // Виведення результатів
    cout << "Number of elements: " << count << endl;
    cout << "Sum of elements: " << sum << endl;

    // Виведення модифікованої матриці
    cout << "Modified matrix:\n";
    PrintMatrix(matrix, rows, cols);

    // Сортування матриці
    SortMatrix(matrix, rows, cols);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:\n";
    PrintMatrix(matrix, rows, cols);

    // Звільнення пам'яті
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
