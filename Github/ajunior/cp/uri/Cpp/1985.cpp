#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int p, cod, qty;
    float total = 0;

    cin >> p;

    for (int i = 0; i < p; i++) {
        cin >> cod >> qty;

        switch(cod) {
            case 1001:
                total += qty * 1.50;
                break;
            case 1002:
                total += qty * 2.50;
                break;
            case 1003:
                total += qty * 3.50;
                break;
            case 1004:
                total += qty * 4.50;
                break;
            case 1005:
                total += qty * 5.50;
                break;
        }
    }

    cout << setprecision(2) << fixed << total << endl;

    return EXIT_SUCCESS;
}
