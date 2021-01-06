#include <iostream>
#include <cmath>

using namespace std;

int main() {
    uint64_t x = 0, kg = 0;
    int s, n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s == 64)
            cout << "1537228672809129 kg\n";
        else {
            for (int j = 0; j <= s; j++)
                x = pow(2, j);

            kg = x / 12000; // 1g = 12 1kg = 12000
            cout << kg << " kg\n";
        }
    }

    return EXIT_SUCCESS;
}