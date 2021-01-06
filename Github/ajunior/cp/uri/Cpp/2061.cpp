#include <iostream>

using namespace std;

int main () {
    int n, m;
    string action;

    cin >> n >> m;

    while (cin >> action) {
        if (action == "fechou") n++;
        else n--;
    }

    cout << n << "\n";

    return EXIT_SUCCESS;
}