#include <iostream>

using namespace std;

int main() {
    long long int fib[61];
    int n, x;

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 61; i++) {
        fib[i] = fib[i-1]+fib[i-2];
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << "Fib(" << x << ") = " << fib[x] << endl;
    }

    return 0;
}

//Fib(0) = 0
//Fib(20) = 6765
//Fib(60) = 1548008755920