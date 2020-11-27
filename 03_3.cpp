#include <iostream>
#include <cmath>
#include <cstring>

double root_iterative(double q, int n, int steps) {
    int i;
    double a = 1;
    for (i = 0; i < steps; i++) {
        a = a + (q / std::pow(a, n - 1) - a) / n;
    }
    return a;
}

void test_root(double q, int n, int steps) {
    double a = root_iterative(q, n, steps);
    std::cout << "q = " << q << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "steps = " << steps << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "q - a^n = " << q - std::pow(a, n) << std::endl;
}

int main(int argc, char ** argv) {

    if (argc != 4) {
        std::cout << "Falsche Anzahl an Parametern" << std::endl;
        return EXIT_FAILURE;
    }

    /* atoi gibt 0 zurück, wenn die Umwandlung nicht funktioniert hat */
    /* atof gibt 0.0 zurück, wenn die Umwandlung nicht funktioniert hat */
    double q = atof(argv[1]);
    int n = atoi(argv[2]);
    int steps = atoi(argv[3]);
    if ((q == 0.0 && strcmp(argv[1], "0.0")) || (n == 0 && strcmp(argv[2], "0")) || (steps == 0 && strcmp(argv[3], "0"))) {
        std::cout << "Mindestens ein Parameter hat den falschen Typ" << std::endl;
        return EXIT_FAILURE;
    }

    if (n < 0) {
        std::cout << "Wert kleiner 0 ist für n nicht erlaubt" << std::endl;
        return EXIT_FAILURE;
    }

    if (steps < 0) {
        std::cout << "Wert kleiner 0 ist für steps nicht erlaubt" << std::endl;
        return EXIT_FAILURE;
    }

    test_root(q, n, steps);

    return EXIT_SUCCESS;

}
