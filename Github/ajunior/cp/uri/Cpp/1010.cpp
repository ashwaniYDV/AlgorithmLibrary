#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct venda {
    int codigo;
    int quantidade;
    double preco;
};

int main() {
    vector<venda> vetor;
    venda v;
    double total = 0;

    for (int i = 0; i < 2; i++) {
        cin >> v.codigo;
        cin >> v.quantidade >> v.preco;
        vetor.push_back(v);
    }

    for (int i = 0; i < 2; i++) {
        total += vetor[i].quantidade * vetor[i].preco;
    }
    cout << setprecision(2) << fixed;
    cout << "VALOR A PAGAR: R$ " << total << endl;

    return EXIT_SUCCESS;
}
