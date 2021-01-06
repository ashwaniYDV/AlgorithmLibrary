#include <iostream>

using namespace std;

int main() {
    int x[20], tmp;

    for (int i = 0; i < 20; i++) {
        cin >> x[i];
    }

    for (int i = 0, j = 19; i < 10; i++, j--) {
        tmp = x[i];
        x[i] = x[j];
        x[j] = tmp;
        //cout << tmp << " " << x[i] << " " << x[j] << endl;
    }

    for (int i = 0; i < 20; i++) {
        cout << "N[" << i << "] = " << x[i] << endl;
    }

    return 0;
}

