// https://cp-algorithms.com/data_structures/sqrt_decomposition.html

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];
int n, len;
vector<int> b;


// preprocessing
void Sqrt_Decomposition() {
    len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    b.resize(len);

    for (int i=0; i<n; ++i) {
        b[i / len] += a[i];
    }
}

void query(int l, int r) {
    int sum = 0;
    for (int i=l; i<=r; ) {
        if (i % len == 0 && (i + len - 1 <= r)) {
            // if the whole block starting at i belongs to [l, r]
            sum += b[i / len];
            i += len;
        } else {
            sum += a[i];
            ++i;
        }
    }
    cout << sum << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    Sqrt_Decomposition();

    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        query(l, r);
    }
    return 0;
}
