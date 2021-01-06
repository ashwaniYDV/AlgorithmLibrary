#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int senha;

    do {
        cin >> senha;

        if (senha != 2002) cout << "Senha Invalida\n";
        else cout << "Acesso Permitido\n";

    } while(senha != 2002);

    return 0;
}