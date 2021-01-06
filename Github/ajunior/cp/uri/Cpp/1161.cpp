#include <iostream>

using namespace std;

uint64_t fatorial (int n);

int main() {
    int a, b;

    while (cin >> a >> b) {
        cout << (fatorial(a) + fatorial(b)) << "\n";
    }

    return EXIT_SUCCESS;
}

uint64_t fatorial (int n)
{
    uint64_t fat = n;

    if (n == 0) return 1;

    while (n > 1) {
        fat = (fat * (n - 1));
        n--;
    }

    return fat;
}