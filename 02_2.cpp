#include <iostream>

void collatz(int number) {
    /*
     * Für alle positiven Zahlen scheint die Abfolge bei 1 zu enden. Laut
     * Wikipedia-Artikel gibt es dafür allerdings bisher keinen Beweis.
     *
     * Negative Zahlen enden bei -1, -5 oder -17. Die 0 kann nur durch
     * Start bei 0 erreicht werden, denn die Operation bei ungeraden
     * Zahlen bräuchte number=-1/3 um 0 als Ergebnis zu haben (aber -1/3
     * ist keine Ganzzahl) und die Operation bei geraden Zahlen endet nur
     * für 0 wieder bei 0.
     *
     */
    while (true) {
        std::cout << number << "\n";
        if (number % 2) {
            number = number * 3 + 1;
        }
        else {
            number = number / 2;
        }
        if (number == 1 || number == 0 || number == -1 || number == -5 || number == -17) {
            std::cout << "Ergebnis: " << number << "\n";
            break;
        }
    }
}

int main() {
    int number;
    std::cout << "number = " << std::flush;
    std::cin >> number;
    collatz(number);
    return 0;
}
