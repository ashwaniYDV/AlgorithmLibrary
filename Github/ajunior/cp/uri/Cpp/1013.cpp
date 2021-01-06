#include <iostream>
#include <cmath>

using namespace std;

int maiorAB(int a, int b, int c);

int main() {
    int a, b, c, maior;

    cin >> a >> b >> c;

    maior = maiorAB(a,b,c);

    cout << maior << " eh o maior" << endl;

    return EXIT_SUCCESS;
}

int maiorAB(int a, int b, int c) {
    int maior_ab, maior_bc;
    maior_ab = (a + b + abs(a-b))/2;
    maior_bc = (b + c + abs(b-c))/2;
    return (maior_ab + maior_bc + abs(maior_ab-maior_bc))/2;
}