#include <iostream>

using namespace std;

int main() {
    int x, z, count = 1;

    cin >> x >> z;

    while (z <= x)
        cin >> z;

    for (int i = x+1; x <= z ; ++i) {
        x += i;
        count++;
    }

    cout << count << endl;

    return EXIT_SUCCESS;
}
