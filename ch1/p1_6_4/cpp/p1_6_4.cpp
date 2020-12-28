/*
 * LCD Display [ID: 706]
 * */

#include <cstdlib>
#include <iostream>
#include <string>

#define NUMS 10
#define ROWS 5
#define COLS 3

int numbers[NUMS][ROWS][COLS]{
    // 0
    {{0, 1, 0}, {1, 0, 1}, {0, 0, 0}, {1, 0, 1}, {0, 1, 0}},
    // 1
    {{0, 0, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 1}, {0, 0, 0}},
    // 2
    {{0, 1, 0}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 0}},
    // 3
    {{0, 1, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, 1}, {0, 1, 0}},
    // 4
    {{0, 0, 0}, {1, 0, 1}, {0, 1, 0}, {0, 0, 1}, {0, 0, 0}},
    // 5
    {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 1, 0}},
    // 6
    {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}, {1, 0, 1}, {0, 1, 0}},
    // 7
    {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}, {0, 0, 1}, {0, 0, 0}},
    // 8
    {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}, {1, 0, 1}, {0, 1, 0}},
    // 9
    {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}, {0, 0, 1}, {0, 1, 0}}};

void printDigitRow(int digit, int row, int size) {
    int* data = numbers[digit][row];

    // first column
    std::cout << (data[0] ? "|" : " ");

    // middle columns
    for (int i = 0; i < size; i++) std::cout << (data[1] ? "-" : " ");

    // last column
    std::cout << (data[2] ? "|" : " ");
}

int main() {
    int s;
    std::string digits;

    while (true) {
        std::cin >> s >> digits;
        if (!s && digits == "0") break;

        int rows = 2 * s + 3;
        for (int i = 0, row_line; i < rows; i++) {
            if (i == 0)
                row_line = 0;
            else if (i > 0 && i < rows / 2)
                row_line = 1;
            else if (i == rows / 2)
                row_line = 2;
            else if (i > rows / 2 && i < rows - 1)
                row_line = 3;
            else
                row_line = 4;

            for (int j = 0; j < digits.length(); j++) {
                int digit = digits[j] - '0';
                if (j) std::cout << " ";
                printDigitRow(digit, row_line, s);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}

