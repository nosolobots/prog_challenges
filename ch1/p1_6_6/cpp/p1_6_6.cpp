/*
 * Interpreter
 * */

#include <bits/stdint-uintn.h>

#include <cstdlib>
#include <iostream>
#include <string>

#define SIGINT -1

#define MEMSIZE 1000
#define NREG 10

#define HALT 1  // halt
#define SETi 2  // set immediate
#define ADDi 3  // sum immediate
#define MULi 4  // mul immediate
#define SETr 5  // set from register
#define ADDr 6  // add from register
#define MULr 7  // mul from register
#define SEfm 8  // set register from memory
#define SEtm 9  // set memory from register
#define GOTO 0  // goto

uint8_t MEM[MEMSIZE][3];    // Memory
int REG[NREG];              // Registers
int PC;                     // Program Counter

int executeInstruction() {
    // Read instruction code & operands
    uint8_t opc = MEM[PC][0];
    uint8_t op1 = MEM[PC][1];
    uint8_t op2 = MEM[PC][2];
    int val;

    ++PC;  // increment program counter

    if (!opc && !op1 && !op2)   // NOP
        return 0;

    switch (opc) {
        case HALT:
            return SIGINT;      // Stop execution
        case SETi:
            REG[op1] = op2;
            break;
        case ADDi:
            REG[op1] += op2;
            REG[op1] %= 1000;
            break;
        case MULi:
            REG[op1] *= op2;
            REG[op1] %= 1000;
            break;
        case SETr:
            REG[op1] = REG[op2];
            break;
        case ADDr:
            REG[op1] += REG[op2];
            REG[op1] %= 1000;
            break;
        case MULr:
            REG[op1] *= REG[op2];
            REG[op1] %= 1000;
            break;
        case SEfm:
            val = REG[op2];
            REG[op1] = MEM[val][0] * 100 + MEM[val][1] * 10 + MEM[val][2];
            break;
        case SEtm:
            val = REG[op1];
            MEM[REG[op2]][2] = val % 10;
            val /= 10;
            MEM[REG[op2]][1] = val % 10;
            val /= 10;
            MEM[REG[op2]][0] = val % 10;
            val /= 10;
            break;
        case GOTO:
            if (REG[op2]) PC = REG[op1];
    }

    return 0;
}

int main() {
    int n;   // number of cases
    int ni;  // number of executed instructions

    std::cin >> n;
    std::cin.get();  // skip ending nl

    std::string cmd;
    std::getline(std::cin, cmd, '\n');  // skip first blank line

    while (n--) {
        // Free memory
        for (int i = 0; i < MEMSIZE; i++)
            for (int j = 0; j < 3; j++) MEM[i][j] = 0;

        // Free registers
        for (int i = 0; i < NREG; i++) REG[i] = 0;

        // Read program into memory
        int proglen = 0;
        do {
            std::getline(std::cin, cmd);
            if (cmd.length()) {
                for (int i = 0; i < 3; i++) MEM[proglen][i] = (cmd[i] - '0');
                ++proglen;
            }
        } while (cmd.length());

        // Execute instructions
        PC = 0;
        ni = 0;
        while (true) {
            ++ni;
            if (executeInstruction() == SIGINT) break;
        }

        std::cout << ni << std::endl;

        if (n) std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
