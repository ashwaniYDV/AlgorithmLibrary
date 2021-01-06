#include <iostream>

using namespace std;

int main() {
    int n, days = 0;
    float x;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;

        while (x > 1.00) {
            x /= 2;
            days++;
        }

        cout << days << " dias" << endl;
        days = 0;
    }
    return EXIT_SUCCESS;
}