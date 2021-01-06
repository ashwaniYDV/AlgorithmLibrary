#include <iostream>

using namespace std;

int main() {
    int n, soma = 0;
    string num;

    while(cin >> n >> num) {

        for (int i = 0; i < n; i++) {
            soma += (int)num[i]-48;
        }

        if (soma % 3 == 0) cout << soma << " sim" << endl;
        else cout << soma << " nao" << endl;

        soma = 0;
    }

    return EXIT_SUCCESS;
}