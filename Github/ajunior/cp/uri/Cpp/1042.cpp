#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v, y;
    int n;

    for (int i = 0; i < 3; i++) {
        cin >> n;
        v.push_back(n);
        y.push_back(n);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++) {
        cout << v[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << y[i] << endl;
    }

    return 0;
}