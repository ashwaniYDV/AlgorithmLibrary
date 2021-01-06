#include <iostream>

using namespace std;

int main() {
    int inter, gremio, repetir, qtdeJogos = 0;
    int vitoriasInter = 0, vitoriasGremio = 0, empates = 0;

    do {
        cin >> inter >> gremio;

        qtdeJogos++;

        if (inter > gremio) vitoriasInter++;
        else if (inter < gremio) vitoriasGremio++;
        else empates++;

        cout << "Novo grenal (1-sim 2-nao)" << endl;

        cin >> repetir;

    } while (repetir == 1);

    cout << qtdeJogos << " grenais\n"
         << "Inter:" << vitoriasInter << endl
         << "Gremio:" << vitoriasGremio << endl
         << "Empates:" << empates << endl;

    if (vitoriasInter > vitoriasGremio) cout << "Inter venceu mais" << endl;
    else if (vitoriasGremio > vitoriasInter) cout << "Gremio venceu mais" << endl;
    else cout << "Não houve vencedor" << endl;

    return EXIT_SUCCESS;
}