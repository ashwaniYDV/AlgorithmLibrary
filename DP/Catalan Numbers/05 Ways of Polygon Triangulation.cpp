// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/number-of-ways-of-triangulation-official/ojquestion
// https://youtu.be/jSGW3YKkyHQ
// tags = { gap strategy, catalan number, Ways of Polygon Triangulation }

/*
A convex polygon with n sides (n >= 3) can be cut into triangles by connecting vertices with non-crossing line segments (a form of polygon triangulation). 
The number of triangles formed is (n - 2) and the number of different ways that this can be achieved is Catalan(n - 2).
*/

#include <bits/stdc++.h>
using namespace std;

int catalan_Number(int n) {
    int catalan[n + 1];
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; ++i) {
        catalan[i] = 0;
        for (int j = 0; j < i; ++j)
            catalan[i] += catalan[j] * catalan[i - 1 - j];
    }
    return catalan[n];
}

int main() {
    int n;
    cin >> n;
    cout << catalan_Number(n - 2);
}
