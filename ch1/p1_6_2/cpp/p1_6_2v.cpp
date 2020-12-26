/*
 * Minesweeper
 *
 * using C++ vector
 * */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#define MINE '*'

int countMines(int i, int j, const std::vector<std::vector<char>>& b) {
    int count = 0;
    int r_ini = (i > 0) ? i - 1 : i;
    int r_end = (i < b.size() - 1) ? i + 1 : i;
    int c_ini = (j > 0) ? j - 1 : j;
    int c_end = (j < b[0].size() - 1) ? j + 1 : j;
    for (int m = r_ini; m <= r_end; m++)
        for (int n = c_ini; n <= c_end; n++)
            if (b[m][n] == MINE) ++count;
    return count;
}

void printField(int f, const std::vector<std::vector<char>>& b) {
    if (f > 1) std::cout << std::endl;
    std::cout << "Field #" << f << ":\n";

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[0].size(); j++)
            if (b[i][j] == MINE)
                std::cout << MINE;
            else
                std::cout << countMines(i, j, b);
        std::cout << std::endl;
    }
}

int main() {
    int r, c, f = 0;
    constexpr char mine = '*';

    while (true) {
        std::cin >> r >> c;
        if (r == 0 && c == 0) break;

        std::vector<std::vector<char>> board(r, std::vector<char>(c));

        char ch;
        std::cin.get(ch);  // skip endl

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) std::cin.get(board[i][j]);
            std::cin.get(ch);  // skip endl
        }

        printField(++f, board);
    }

    return EXIT_SUCCESS;
}
