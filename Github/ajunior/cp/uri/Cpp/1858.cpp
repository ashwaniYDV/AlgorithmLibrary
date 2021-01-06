#include <iostream>

using namespace std;

int main() {
    int n, t, smallest = 21, position = 0;

    cin >> n;

    for (int i = 1; i <= n ; ++i) {
        cin >> t;

        if (t < smallest) {
            smallest = t;
            position = i;
        }
    }

    cout << position << endl;

    return EXIT_SUCCESS;
}