/*
 * Check the Check
 * */

#include <iostream>
#include <cstdlib>
#include <string>

#define ROWS 8
#define COLS 8

#define FREE '.'

char board[ROWS][COLS];

int main() {
    std::string line;
    bool empty = false;

    while(!empty) {
        empty = true;
   
        do {
            std::getline(std::cin, line, '\n');
        } while(!line.size()); // skip blank lines

        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                board[i][j] = line[j];
                empty = !(empty && line[j]!=FREE);
            }
            std::getline(std::cin, line, '\n');
        }
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
    }
}
