#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float s = 1;

    for (int i = 2; i <= 100; i++) {
        s += 1.0/i;
    }

    cout << setprecision(2) << fixed;
    cout << s << endl;

    return 0;
}