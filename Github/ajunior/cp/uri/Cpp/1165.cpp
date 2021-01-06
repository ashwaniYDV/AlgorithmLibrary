#include <iostream>

using namespace std;

int main() {
    int n, p, count = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p;

        for (int j = p; j > 0; j--)
            if (p % j == 0) count++;

        if (count == 2) cout << p << " eh primo" << endl;
        else cout << p << " nao eh primo" << endl;

        count = 0;
    }

    return EXIT_SUCCESS;
}
