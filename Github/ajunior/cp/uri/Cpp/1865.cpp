#include <iostream>

using namespace std;

int main() {
    int c, n;
    string character;

    cin >> c;

    for (int i = 0; i < c; ++i) {
        cin >> character >> n;

        if (character == "Thor") cout << "Y" << endl;
        else cout << "N" << endl;

    }
    return EXIT_SUCCESS;
}