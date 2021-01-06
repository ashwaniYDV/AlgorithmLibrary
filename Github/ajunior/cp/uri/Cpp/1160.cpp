#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t, pa, pb, tempo = 0;
    double g1, g2;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> pa >> pb >> g1 >> g2;

        while(pa <= pb) {
            pa += (pa * (g1/100));
            pb += (pb * (g2/100));

            tempo++;

            if (tempo > 100) break;
        }

        if (tempo > 100) cout << "Mais de 1 seculo." << endl;
        else cout << tempo << " anos." << endl;

        tempo = 0;
    }

    return EXIT_SUCCESS;
}