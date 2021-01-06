#include <iostream>

using namespace std;

int main() {
    int repeat = 1;

    for (int i = 1; i < 10; i += 2) {
        for (int j = 7; j >= 5; j--) {
            cout << "I=" << i << " J=" << j << endl;
        }
    }

    return 0;
}