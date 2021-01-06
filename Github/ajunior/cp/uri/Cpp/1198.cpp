#include <iostream>

using namespace std;

int main() {
    long long int a, b;

    while(cin >> a >> b) {
        if (a < b) swap(a,b);
        cout << (a-b) << "\n";
    };

    return EXIT_SUCCESS;
}