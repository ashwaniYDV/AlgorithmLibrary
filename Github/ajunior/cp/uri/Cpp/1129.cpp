#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, d, e;

    do {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c >> d >> e;

            if (a <= 127 && b > 127 && c > 127 && d > 127 && e > 127 ) cout << "A" << endl;
            else if (a > 127 && b <= 127 && c > 127 && d > 127 && e > 127 ) cout << "B" << endl;
            else if (a > 127 && b > 127 && c <= 127 && d > 127 && e > 127 ) cout << "C" << endl;
            else if (a > 127 && b > 127 && c > 127 && d <= 127 && e > 127 ) cout << "D" << endl;
            else if (a > 127 && b > 127 && c > 127 && d > 127 && e <= 127 ) cout << "E" << endl;
            else cout << "*" << endl;
        }
    } while (n != 0);

    return EXIT_SUCCESS;
}