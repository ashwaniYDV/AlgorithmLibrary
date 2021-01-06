#include <iostream>

using namespace std;

int main() {
    int h, m, delayed_h, delayedInMinutes;

    while (scanf("%d:%d", &h, &m) != EOF) {
        delayed_h = h + 1; // Incrementando uma hora, devido o delay máximo que é de 60 minutos.

        // 8 é o literal para a hora marcada do encontro dos amigos no terminal
        if (delayed_h > 8) delayedInMinutes = ((delayed_h - 8) * 60) + m;
        else if (delayed_h == 8) delayedInMinutes = m;
        else delayedInMinutes = 0;

        cout << "Atraso maximo: " << delayedInMinutes << "\n";
    }

    return EXIT_SUCCESS;
}