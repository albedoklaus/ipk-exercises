#include <iostream>
#include <cmath>

int main() {
    std::cout << "a * x^2 + b * x + c = 0\n";
    /* Einlesen der Werte */
    double a, b, c;
    std::cout << "a = " << std::flush;
    std::cin >> a;
    std::cout << "b = " << std::flush;
    std::cin >> b;
    std::cout << "c = " << std::flush;
    std::cin >> c;
    /* Fallunterscheidung */
    if (a == 0) {
        /* Lineare Gleichung */
        if (b == 0) {
            if (c == 0) {
                std::cout << "x beliebig wählbar\n";
            }
            else {
                std::cout << "keine Lösung\n";
            }
        }
        else {
            if (c == 0) {
                std::cout << "Lösung: 0\n";
            }
            else {
                std::cout << "Lösung: " << -b / c << "\n";
            }
        }
    }
    else {
        /* Quadratische Gleichung */
        double diskriminante = b * b - 4 * a * c;
        if (diskriminante < 0) {
            std::cout << "keine Lösung im Raum der reellen Zahlen\n";
        }
        else if (diskriminante == 0) {
            std::cout << "Lösung: " << -b / (2 * a) << "\n";
        }
        else {
            double wurzel = std::sqrt(diskriminante);
            std::cout << "Lösungen: " << (-b - wurzel) / (2 * a) << " und " << (-b + wurzel) / (2 * a) << "\n";
        }
    }
    return 0;
}
