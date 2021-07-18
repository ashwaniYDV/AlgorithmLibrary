// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

/*
While the Euclidean algorithm calculates only the GCD of two integers a & b,
the extended version also finds a way to represent GCD in terms of a & b, 
i.e. coefficients x and y for which:
 
ax + by = gcd(a, b)
*/

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}



// https://www.hackerrank.com/contests/test-contest-47/challenges/m158-multiple-euclid/problem
/*
You will be given two relatively prime (co-prime) integers a and b. 
You must give two coefficients x and y, such that ax + by = 1.
*/

#include<bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void solve() {
    int a, b, x, y;
    cin >> a >> b;
    gcd(a, b, x, y);
    cout << x << " " << y << endl;
}

int32_t main() {
    solve();
    return 0;
}