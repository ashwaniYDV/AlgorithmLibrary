#include <iostream>

using namespace std;

int main() {

    float x, y;
    cin >> x >> y;

    if (x == y && y == 0.0) cout << "Origem" << endl;
    if (x == 0.0 && y != 0.0) cout << "Eixo Y" << endl;
    if (x != 0.0 && y == 0.0) cout << "Eixo X" << endl;
    if (x > 0.0 && y > 0.0) cout << "Q1" << endl;
    if (x < 0.0 && y > 0.0) cout << "Q2" << endl;
    if (x < 0.0 && y < 0.0) cout << "Q3" << endl;
    if (x > 0.0 && y < 0.0) cout << "Q4" << endl;

    return EXIT_SUCCESS;
}