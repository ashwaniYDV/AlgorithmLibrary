/*
Resources
=========
1) Errichto => https://youtu.be/GU7DpgHINWQ?si=K28Wj39P8GQbhNt3
1) https://www.topcoder.com/thrive/articles/Binary%20Search
2) https://leetcode.com/discuss/general-discussion/786126/python-powerful-ultimate-binary-search-template-solved-many-problems
*/


/*
Type 1: FFFFFFFFTTTTTTTTTT
*/

// Method 1
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


// Method 2
/*
Step(1)
F   F   F   F   T   T   T   T
lo                          hi
...
...
...
Step(n)
F   F   F   F   T   T   T   T
           hi   lo

When while loop ends => lo > hi (reverse parity), and our answer is lo

Note (variable initializatio): lo = 0, hi = n-1
*/
void solve() {
    cin >> n;
    vector<int> a(n); 
    f(i, n) cin >> a[i];

    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(a[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    // lo will be our answer and not hi
    // since we set hi = mid-1 when our checker function was true for mid
    cout << "lo = " << lo << endl;
}














/*
Type 2: TTTTTTTTFFFFFFFFF
*/

// Method 1
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


// Method 2
/*
Step(1)
T   T   T   T   F   F   F   F
lo                          hi
...
...
...
Step(n)
T   T   T   T   F   F   F   F
           hi   lo

When while loop ends => lo > hi (reverse parity), and our answer is hi

Note (variable initializatio): lo = 0, hi = n-1
*/

void solve() {
    cin >> n;
    vector<int> a(n); 
    f(i, n) cin >> a[i];

    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(a[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    // hi will be our answer and not lo
    // since we set lo = mid+1 when our checker function was true for mid
    cout << "hi = " << hi << endl;
}












// Method 1
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


// Method 2
void lowerBound(vector<int>& a, int x) {
    int n = a.size();
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(a[mid] >= x) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
void upperBound(vector<int>& a, int x) {
    int n = a.size();
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(a[mid] > x) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
