#include <iostream>

using namespace std;

int main() {
    int j = 7;

    for (int i = 1; i < 10; i += 2) {
        for (int x = 0; x < 3; x++) {
            cout << "I=" << i << " J=" << j << endl;
            j--;
        }
        j += 5;
    }

    return 0;
}