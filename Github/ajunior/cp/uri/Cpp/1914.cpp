#include <iostream>

using namespace std;

int main() {
    int qt, x, y;
    string p1, p1Choice, p2, p2Choice;

    cin >> qt;

    for (int i = 0; i < qt; ++i) {
        cin >> p1 >> p1Choice >> p2 >> p2Choice >> x >> y;

        if (p1Choice == "PAR" && ((x+y) % 2 == 0)) cout << p1 << endl;
        else if (p1Choice == "IMPAR" && ((x+y) % 2 != 0)) cout << p1 << endl;
        else cout << p2 << endl;
    }

    return EXIT_SUCCESS;
}