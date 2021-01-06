#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float x, y;
    int n;

    cin >> n;

    cout << setprecision(1) << fixed;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (y == 0) cout << "divisao impossivel\n";
        else cout << x / y << endl;
    }
    return 0;
}