/*
Resources
=========
1) https://www.topcoder.com/thrive/articles/Binary%20Search
*/


// FFFFFFFFTTTTTTTTTT

void solve() {
    cin >> n;
    vi a(n); f(i, n) cin >> a[i];

    int lo = 0, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(a[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    debug2(lo, hi)
}

/*
5
0 0 1 1 1
lo, hi are: 2, 2



5
0 0 0 0 0
lo, hi are: 5, 5


5
1 1 1 1 1
lo, hi are: 0, 0

1
0
lo, hi are: 1, 1


1
1
lo, hi are: 0, 0
*/


















// TTTTTTTTFFFFFFFFF

void solve() {
    cin >> n;
    vi a(n); f(i, n) cin >> a[i];

    int lo = -1, hi = n - 1;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if(a[mid]) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    debug2(lo, hi)
}

/*
5
1 1 0 0 0
lo, hi are: 1, 1



5
0 0 0 0 0
lo, hi are: -1, -1


5
1 1 1 1 1
lo, hi are: 4, 4


1
0
lo, hi are: -1, -1


1
1
lo, hi are: 0, 0
*/






















void lowerBound(vector<int>& a, int x) {
    int n = a.size();
    int lo = 0, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(a[mid] >= x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    debug2(lo, hi)
}

void upperBound(vector<int>& a, int x) {
    int n = a.size();
    int lo = 0, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(a[mid] > x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    debug2(lo, hi)
}
