#include <iostream>

using namespace std;

int main() {
    int n, t;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t;

        if (t == 2015)
            cout << "1 A.C." << endl;
        else if (t > 2015)
            // +1 do ano 0
            cout << ((t - 2015) + 1) << " A.C." << endl;
        else
            cout << (2015 - t) << " D.C." << endl;

    }
    return EXIT_SUCCESS;
}