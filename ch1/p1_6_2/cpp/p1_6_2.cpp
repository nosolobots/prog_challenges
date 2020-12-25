/*
 * Minesweeper
 * */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MINE '*'

int countMines(int r, int c, int i, int j, char *b) {
    int count = 0;
    int r_ini = (i > 0) ? i - 1 : i;
    int r_end = (i < r - 1) ? i + 1 : i;
    int c_ini = (j > 0) ? j - 1 : j;
    int c_end = (j < c - 1) ? j + 1 : j;
    for (int m = r_ini; m <= r_end; m++)
        for (int n = c_ini; n <= c_end; n++)
            if (*((b + m * c) + n) == MINE) ++count;
    return count;
}

void printField(int r, int c, int f, char *b) {
    if (f > 1) std::cout << std::endl;
    std::cout << "Field #" << f << ":\n";

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            if (*((b + i * c) + j) == MINE)
                std::cout << MINE;
            else
                std::cout << countMines(r, c, i, j, b);
        std::cout << std::endl;
    }
}

int main() {
    int r, c, f = 0;
    constexpr char mine = '*';

    while (true) {
        std::cin >> r >> c;
        if (r == 0 && c == 0) break;

        char board[r][c], ch;
        std::cin.get(ch);  // skip endl
        for (int i = 0; i < r; i++) {
            std::cin.read(board[i], c);
            std::cin.get(ch);  // skip endl
        }

        printField(r, c, ++f, (char *)board);
    }

    return EXIT_SUCCESS;
}
