#include <iostream>

using namespace std;

int main() {
    int n, k, f;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> k;

        for (int j = 0; j < k; ++j) {
            cin >> f;

            if (f == 1) cout << "Rolien" << endl;
            else if (f == 2) cout << "Naej" << endl;
            else if (f == 3) cout << "Elehcim" << endl;
            else cout << "Odranoel" << endl;
        }
    }

    return EXIT_SUCCESS;
}