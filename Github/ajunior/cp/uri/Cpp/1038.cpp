#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int x, y;
    double preco;

    cin >> x >> y;

    switch(x) {
        case 1:
            preco = 4.00;
            break;
        case 2:
            preco = 4.50;
            break;
        case 3:
            preco = 5.00;
            break;
        case 4:
            preco = 2.00;
            break;
        case 5:
            preco = 1.50;
            break;
    }

    cout << setprecision(2) << fixed;
    cout << "Total: R$ " << y * preco << endl;

    return EXIT_SUCCESS;

}
