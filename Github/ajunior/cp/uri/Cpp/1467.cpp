#include <iostream>

using namespace std;

int main() {
    bool a, b, c;

    while (cin >> a >> b >> c) {
        if (a == b && b == c) cout << "*" << endl;
        else if (a == b && b != c) cout << "C" << endl;
        else if (a != b && b == c) cout << "A" << endl;
        else cout << "B" << endl;
    }

    return EXIT_SUCCESS;
}