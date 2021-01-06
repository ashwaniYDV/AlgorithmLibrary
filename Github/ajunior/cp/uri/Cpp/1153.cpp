#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;
    int i = n-1;
    for (; i > 0; i--) {
        n *= i;
    }

    cout << n << endl;

    return 0;
}

