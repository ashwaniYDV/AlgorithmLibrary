#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n, count = 0;
    double sum = 0.0;
    string name;

    while(getline(cin, name)) {
        cin >> n;
        cin.ignore();
        sum += n;
        count++;
    }
    cout << fixed << setprecision(1) << (sum/count) << endl;

    return 0;
}