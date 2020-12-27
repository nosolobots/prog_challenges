/*
 * The Trip
 * */

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (!n) break;  // break if 0

        // read expenses
        double expense;
        int expenses[n], sum = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> expense;
            expenses[i] = static_cast<int>(std::round(expense * 100.0));
            sum += expenses[i];
        }
        double mean = static_cast<double>(sum) / n;

        // compute change
        double diff, given = .0, taken = .0;
        for (int i = 0; i < n; i++) {
            diff = expenses[i] - mean;
            if (diff < 0)
                taken -= static_cast<int>(diff) / 100.0;
            else
                given += static_cast<int>(diff) / 100.0;
        }
        std::cout << "$" << std::fixed << std::setprecision(2)
                  << ((taken > given) ? taken : given) << std::endl;
    }

    return EXIT_SUCCESS;
}
