#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float x, y, media = 0;

    cin >> x >> y;

    // Média Ponderada
    media = ((x * 3.5) + (y * 7.5)) / (3.5+7.5);

    cout << setprecision(5) << fixed;
    cout << "MEDIA = " << media << endl;

    return EXIT_SUCCESS;
}