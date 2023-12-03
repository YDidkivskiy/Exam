#include <iostream>
#include <cstdlib>
#include <ctime>

const int row = 22, col = 2;
int matrix[col][row];

void sort(int matrix[col][row], int rowIndex) {
    for (int i = 0; i < col - 1; ++i) {
        for (int j = i + 1; j < col; ++j) {
            if (matrix[i][rowIndex] < matrix[j][rowIndex]) {
                std::swap(matrix[i][rowIndex], matrix[j][rowIndex]);
            }
        }
    }
}

int main() {
    system("chcp 65001"); // через setlocale не працює

    std::srand(time(0));

    int maxSum = 0;
    int maxSumRow1 = 0, maxSumRow2 = 0;

    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            matrix[i][j] = rand() % 22 + 1;
        }
    }

    std::cout << "Початкова матриця:" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < row - 1; ++i) {
        int Summa = matrix[0][i] + matrix[1][i] + matrix[0][i + 1] + matrix[1][i + 1];
        if (Summa > maxSum) {
            maxSum = Summa;
            maxSumRow1 = i;
            maxSumRow2 = i + 1;
        }
    }

    std::cout << "Номера рядків з максимальною сумою: " << maxSumRow1 << " та " << maxSumRow2 << std::endl;
    std::cout << "Сума максимальних елементів: " << maxSum << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < row; ++i) {
        sort(matrix, i);
    }

    std::cout << "Відсортована матриця за спаданням" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}