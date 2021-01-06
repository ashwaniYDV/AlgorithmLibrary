#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x, y;
    double b, c, r;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;

    //  Beto - b(x, y) = 2(x²) + (5y)².
    //  Carlos - c(x, y) = -100x + y³.
    //  Rafael - r(x, y) = (3x)² + y².

        b = (2 * pow(x,2)) + pow((5*y),2);
        c = (-100 * x) + pow(y,3);
        r = pow((3*x),2) + pow(y,2);

        if (b > c && b > r) cout << "Beto ganhou\n";
        else if (c > b && c > r) cout << "Carlos ganhou\n";
        else cout << "Rafael ganhou\n";
    }

    return EXIT_SUCCESS;
}