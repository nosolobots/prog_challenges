/*
 * The 3n+1 problem
 * */

#include <cstdlib>
#include <iostream>

int computeCiclos(int n) {
    int ciclos = 1;

    while (n > 1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        ++ciclos;
    }

    return ciclos;
}

int main() {
    int n1, n2, max, ini, end, ciclos;

    while (std::cin >> n1) {
        std::cin >> n2;

        max = 0;
        if (n1 <= n2) {
            ini = n1;
            end = n2;
        } else {
            ini = n2;
            end = n1;
        }
        for (int i = ini; i <= end; i++) {
            ciclos = computeCiclos(i);
            if (ciclos > max) max = ciclos;
        }

        std::cout << n1 << " " << n2 << " " << max << std::endl;
    }

    return EXIT_SUCCESS;
}
