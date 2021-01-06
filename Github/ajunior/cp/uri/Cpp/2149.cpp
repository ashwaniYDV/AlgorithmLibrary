#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long double>fib;

    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);
    fib.push_back(1);
    fib.push_back(2);
    fib.push_back(2);
    fib.push_back(4);
    fib.push_back(8);
    fib.push_back(12);

    for (int i = 9; i < 17; i++) {
        int next = fib[i-1] * fib[i-2];
        fib.push_back(next);
    }

//    for(int j = 0; j < fib.size(); j++) {
//        cout << fib[j] << " ";
//    }
//    cout << endl;
    int pos;
    while(cin >> pos) {
        cout << fib[pos-1] << endl;
    }

    return 0;
}