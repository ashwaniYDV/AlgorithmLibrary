#include <iostream>

using namespace std;

int main() {
    int count;
    float n, soma;

    for (int i = 0; i < 6; i++) {
        cin >> n;
        if (n > 0) {
            count++;
            soma += n;
        }
    }

    cout << count << " valores positivos\n"
         << soma/count << endl;

    return EXIT_SUCCESS;
}