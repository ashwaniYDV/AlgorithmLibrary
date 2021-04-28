// https://cp-algorithms.com/data_structures/sqrt_decomposition.html

// Range sum and point update
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

void pointUpdate(int idx, int oldValue, int newValue) {
    b[idx / len] += (newValue - oldValue);
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
int n, len;
vector<int> b;


// preprocessing
void Sqrt_Decomposition() {
    len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    b.resize(len, INT_MAX);

    for (int i=0; i<n; ++i) {
        b[i / len] = min(b[i / len], a[i]);
    }
}

void pointUpdate(int idx) {
    b[idx / len] = min (b[idx / len], a[idx]);
}

void query(int l, int r) {
    int mn = INT_MAX;
    for (int i=l; i<=r; ) {
        if (i % len == 0 && (i + len - 1 <= r)) {
            // if the whole block starting at i belongs to [l, r]
            mn = min(mn, b[i / len]);
            i += len;
        } else {
            mn = min(mn, a[i]);
            ++i;
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
