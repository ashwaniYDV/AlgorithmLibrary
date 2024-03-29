// https://cp-algorithms.com/data_structures/sqrt_decomposition.html

/*
0 Sqrt Decomposition.cpp implementation has unreasonably many division operations (which are much slower than other arithmetical operations). 
Instead, we can calculate the indices of the blocks cl and cr which contain indices l and r, 
and loop through blocks cl+1...cr−1 with separate processing of the "tails" in blocks cl and cr. 
This approach corresponds to the last formula in the description, and makes the case cl = cr a special case.
*/

// Range sum and point update
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];
int n, BLK;
vector<int> b;

// preprocessing
void Sqrt_Decomposition() {
    BLK = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    b.resize(BLK);

    for (int i=0; i<n; ++i) {
        b[i / BLK] += a[i];
    }
}

void pointUpdate(int idx, int oldValue, int newValue) {
    b[idx / BLK] += (newValue - oldValue);
}

void query(int l, int r) {
    int sum = 0;
    int LB = l / BLK,  RB = r / BLK;

    if (LB == RB) {
        for (int i=l; i<=r; ++i) {
            sum += a[i];
        }
    } else {
        for (int i=l; i <= (LB+1)*BLK-1; ++i) {
            sum += a[i];
        }
        for (int i=LB+1; i<=RB-1; ++i) {
            sum += b[i];
        }
        for (int i=RB*BLK; i<=r; ++i) {
            sum += a[i];
        }
    }

    cout << sum << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    Sqrt_Decomposition();

    int q, l, r, type, idx, oldValue, newValue;
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 0) {
            cin >> l >> r;
            query(l, r);
        } else {
            cin >> idx >> newValue;
            oldValue = a[idx];
            a[idx] = newValue;
            pointUpdate(idx, oldValue, newValue);
        }
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
5
0 0 3
1 0 5
0 0 4
1 1 4
0 2 6


10
19
25
*/





















// Range minimum and point update
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];
int n, BLK;
vector<int> b;

// preprocessing
void Sqrt_Decomposition() {
    BLK = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    b.resize(BLK, INT_MAX);

    for (int i=0; i<n; ++i) {
        b[i / BLK] = min(b[i / BLK], a[i]);
    }
}

void pointUpdate(int idx) {
    b[idx / BLK] = min (b[idx / BLK], a[idx]);
}

void query(int l, int r) {
    int mn = INT_MAX;
    int LB = l / BLK,  RB = r / BLK;

    if (LB == RB) {
        for (int i=l; i<=r; ++i) {
            mn = min(mn, a[i]);
        }
    } else {
        for (int i=l; i < (LB+1)*BLK; ++i) {
            mn = min(mn, a[i]);
        }
        for (int i=LB+1; i<RB; ++i) {
            mn = min(mn, b[i]);
        }
        for (int i=RB*BLK; i<=r; ++i) {
            mn = min(mn, a[i]);
        }
    }

    cout << mn << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    Sqrt_Decomposition();

    int q, l, r, type, idx;
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 0) {
            cin >> l >> r;
            query(l, r);
        } else {
            cin >> idx >> a[idx];
            pointUpdate(idx);
        }
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
6
0 0 3
1 0 -5
0 0 4
0 2 6
1 3 -4
0 2 6


1
-5
3
-4
*/
