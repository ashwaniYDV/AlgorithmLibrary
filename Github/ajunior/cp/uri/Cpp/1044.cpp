#include <iostream>

using namespace std;

void multiplos(int a, int b);

int main() {
    int a, b, tmp;

    cin >> a >> b;

    if (a > b) { multiplos(a,b); }
    else { multiplos(b,a); }

    return EXIT_SUCCESS;
}

void multiplos(int a, int b) {
    if (a%b == 0) { cout << "Sao Multiplos\n"; }
    else { cout << "Nao sao Multiplos\n"; }
}
