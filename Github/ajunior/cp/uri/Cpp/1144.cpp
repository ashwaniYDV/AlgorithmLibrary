#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;

    cin >> n;

    cout << a << " " << b << " ";
    for (int i = 3; i <= n; i++) {
        tmp = a;
        a = b;
        b = tmp + a;
        
        if (i == n) cout << b << endl;
        else cout << b << " ";
    }

    return 0;
}

