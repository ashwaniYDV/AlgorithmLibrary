#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    float a, b, c;

    cin >> n;

    cout << setprecision(1) << fixed;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << ((a*2)+(b*3)+(c*5))/(2+3+5) << endl;
    }

    return 0;
}