#include <iostream>

using namespace std;

int main() {
    int n, x, y, p1 = 0, p2 = 0;

    do {
        cin >> n;

        if (n != 0) {

            for (int i = 0; i < n; ++i) {
                cin >> x >> y;

                if (x > y) p1++;
                else if (x < y) p2++;
            }

            cout << p1 << " " << p2 << endl;
            p1 = 0;
            p2 = 0;
        }
    } while (n != 0);

    return EXIT_SUCCESS;
}