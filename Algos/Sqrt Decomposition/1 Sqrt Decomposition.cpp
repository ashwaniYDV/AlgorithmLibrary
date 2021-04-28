// https://cp-algorithms.com/data_structures/sqrt_decomposition.html

/*
0 Sqrt Decomposition.cpp implementation has unreasonably many division operations (which are much slower than other arithmetical operations). 
Instead, we can calculate the indices of the blocks cl and cr which contain indices l and r, 
and loop through blocks cl+1...cr−1 with separate processing of the "tails" in blocks cl and cr. 
This approach corresponds to the last formula in the description, and makes the case cl = cr a special case.
*/

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
    int c_l = l / len,  c_r = r / len;

    if (c_l == c_r) {
        for (int i=l; i<=r; ++i) {
            sum += a[i];
        }
    } else {
        for (int i=l, end=(c_l+1)*len-1; i<=end; ++i) {
            sum += a[i];
        }
        for (int i=c_l+1; i<=c_r-1; ++i) {
            sum += b[i];
        }
        for (int i=c_r*len; i<=r; ++i) {
            sum += a[i];
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
