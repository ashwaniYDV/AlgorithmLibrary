#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a, b, c, media = 0;

    cin >> a >> b >> c;

    // Média Ponderada
    media = ((a * 2) + (b * 3) + (c * 5)) / (2+3+5);

    cout << setprecision(1) << fixed;
    cout << "MEDIA = " << media << endl;

    return EXIT_SUCCESS;
}