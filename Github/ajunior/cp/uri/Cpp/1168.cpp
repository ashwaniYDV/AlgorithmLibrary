#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int led[10] = {6,2,5,5,4,5,6,3,7,6};
    int n, tamanho, soma = 0;
    string s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        tamanho = (int)s.size(); // Cast pq a função size retorna um unsigned long

        for (int j = 0; j < tamanho; j++)
            soma += led[(int)(s[j] - 48)]; // Uso do literal 48 por causa da tabela ASCII

        cout << soma << " leds" << endl;
        soma = 0;
    }

    return 0;
}