#include <iostream>

unsigned long fibonacci(int number) {
    /*
     * Mit dem Datentyp `int` erhalten wir für N=47 folgendes Ergebnis:
     *
     * f_47 = 1836311903
     *
     * Für größere Werte von N passiert ein Overflow, da der für diesen
     * Datentyp reservierte Platz im Arbeitsspeicher nicht ausreicht, um
     * die Zahl darzustellen.
     *
     * Eine Lösung hierfür wäre, auf einen anderen Datentyp umzusteigen.
     * Zunächst kann von `int` auf `unsigned int` gewechselt werden, da
     * wir sicher sein können, dass das Ergebnis keine negative Zahl
     * ist. Wir erhalten dadurch ein zusätzliches korrektes Ergebnis:
     *
     * f_48 = 2971215073
     *
     * Neben dem Hinzufügen von `unsigned` können wir auch den
     * Grund-Datentyp ändern und erhalten nun für `unsigned long`
     * richtige Ergebnisse bis N=94:
     *
     * f_94 = 12200160415121876738
     *
     * Weiterhin könnte auch `double` verwendet werden, wenn es nur um
     * eine ungefähre Idee geht, wie groß die Zahl für ein bestimmtes
     * N wird. Denn durch die Verwendung des Gleichkommazahl-Schemas
     * geht Präzision verloren.
     *
     * Der Typ des Rückgabewerts muss natürlich im Funktions-Header
     * auch noch angepasst werden.
     */
    int i;
    unsigned long tmp, a = 0, b = 1;
    for (i = 1; i <= number; i++) {
        tmp = a;
        a = b;
        b += tmp;
        std::cout << "f_" << i << " = " << tmp << "\n";
    }
    return tmp;
}

int main() {
    int N;
    std::cout << "N = " << std::flush;
    std::cin >> N;
    fibonacci(N);
    return 0;
}
