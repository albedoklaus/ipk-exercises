#include <iostream>
#include <cstring>

/* 
 * Auf dem Aufgabenblatt steht:
 *
 * "Alle folgenden Funktionen sollen testen, ob die Eingabe gültig
 * ist. Bei einem Fehler schreiben Sie eine Meldung nach std::cout
 * und geben 0 zurück"
 *
 * Wir setzen diese Überprüfung lieber in die main Funktion, sodass
 * sie in den Funktionen nicht wiederholt werden muss und geben bei
 * fehlerhafter Eingabe EXIT_FAILURE zurück. Die Fehlerbehandlung
 * ist damit nicht verstreut sondern an einer Stelle zusammen.
 *
 */

namespace power {

    int iterative(int q, int n) {
        int i;
        int result = 1;
        for (i = 0; i < n; i++) {
            result *= q;
        }
        return result;
    }

    int recursive(int q, int n) {
        if (n == 0) {
            return 1;
        }
        return q * recursive(q, n - 1);
    }

    int recursive_improved(int q, int n) {
        if (n == 0) {
            return 1;
        }
        int result = recursive_improved(q, n / 2);
        result *= result;
        if (n % 2) {
            result *= q;
        }
        return result;
    }

}

int main(int argc, char ** argv) {

    if (argc != 3) {
        std::cout << "Falsche Anzahl an Parametern" << std::endl;
        return EXIT_FAILURE;
    }

    /* atoi gibt 0 zurück, wenn die Umwandlung nicht funktioniert hat */
    int q = atoi(argv[1]);
    int n = atoi(argv[2]);
    if ((q == 0 && strcmp(argv[1], "0")) || (n == 0 && strcmp(argv[2], "0"))) {
        std::cout << "Parameter müssen Ganzzahlen sein" << std::endl;
        return EXIT_FAILURE;
    }

    if (n < 0) {
        std::cout << "Wert kleiner 0 ist für n nicht erlaubt" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "iterative: " << power::iterative(q, n) << std::endl;
    std::cout << "recursive: " << power::recursive(q, n) << std::endl;
    std::cout << "recursive_improved: " << power::recursive_improved(q, n) << std::endl;

    return EXIT_SUCCESS;

}
