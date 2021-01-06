#include <iostream>

using namespace std;

int main() {
    int n, r, rHighest = 0;
    float score, highest = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> r >> score;
        if (score > highest) {
            highest = score;
            rHighest = r;
        }
    }

    if (highest < 8.0) cout << "Minimum note not reached" << endl;
    else cout << rHighest << endl;

    return EXIT_SUCCESS;
}
