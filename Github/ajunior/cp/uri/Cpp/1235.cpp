#include <iostream>

using namespace std;

int main() {
    int n, half, size;
    string line;

    cin >> n;
    for (int j = 0; j < n; j++) {
        getline(cin,line);
        //cin.ignore();
        half = line.size() / 2;
        for (int i = half; i >= 0; i--) {
            cout << line[i];
        }
        size = line.size();
        for (int i = half; i < size; i++) {
            cout << line[i];
        }
        cout << endl;
    }
    return 0;
}