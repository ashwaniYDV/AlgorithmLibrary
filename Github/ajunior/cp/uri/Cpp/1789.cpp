#include <iostream>

using namespace std;

int main() {
    int t, x, maior = 0;

    while(cin >> t) {

        for (int i = 0; i < t; i++) {
            cin >> x;
            if (x > maior) maior = x;
        }

        if (maior < 10) cout << "1" << endl;
        else if (maior >= 10 && maior < 20) cout << "2" << endl;
        else cout << "3" << endl;

        maior = 0;
    }

    return EXIT_SUCCESS;
}