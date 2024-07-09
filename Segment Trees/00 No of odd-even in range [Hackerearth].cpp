// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

/*
Given an array of N natural numbers and asks him to solve the following queries:-
Query 0:- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

input:
First line of the input contains the number N. 
Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.
0 x y - modify the number at index x to y.
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive.
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegmentTree {
    int N;
    vector<array<int, 2>> st;
    vector<int>& arr;

    SegmentTree(int n, vector<int>& a): arr(a) {
        N = n;
        st = vector<array<int, 2>>(4 * N + 5, {0, 0});
    }

    void build() {
        build(1, 1, N);
    }
    
    void build(int si, int ss, int se) {
        if(ss == se) {
            if(arr[ss] % 2 == 0) {
                st[si] = {1, 0};
            } else {
                st[si] = {0, 1};
            }
            return;
        }
    
        int mid = (ss + se) / 2;
        build(2*si, ss, mid);
        build(2*si+1, mid+1, se);
    
        st[si][0] = st[2*si][0] + st[2*si+1][0];
        st[si][1] = st[2*si][1] + st[2*si+1][1];
    }

    void update(int qi, int newVal) {
        update(1, 1, N, qi, newVal);
    }

    void update(int si , int ss , int se , int qi, int newVal) {
        if(ss == se) {
            // here ss == se == qi
            if(arr[ss] % 2 == 0){
                // reverse even to odd
                st[si] = {0, 1};
            } else {
                // reverse odd to even
                st[si] = {1, 0};
            }

            arr[qi] = newVal;
            return;
        }

        int mid = (ss + se) / 2;

        if(qi <= mid) 
            update(2*si, ss, mid, qi, newVal);
        else 
            update(2*si + 1, mid + 1, se, qi, newVal);

        st[si][0] = st[2*si][0] + st[2*si+1][0];
        st[si][1] = st[2*si][1] + st[2*si+1][1];
    }

    int query(int qs, int qe, int type) {
        return query(1, 1, N, qs, qe, type);
    }

    int query(int si, int ss, int se, int qs, int qe, int type) {
        if (qe < ss || qs > se) return 0;

        if (ss >= qs && se <= qe) {
            if(type == 1) return st[si][0];
            if(type == 2) return st[si][1];
        }

        int mid = (ss + se) / 2;
        int l = query(2*si, ss, mid, qs, qe, type);
        int r = query(2*si + 1, mid + 1, se, qs, qe, type);
        
        return l + r;
    }
};

int32_t main() {
    int n, t, q, x, y;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    SegmentTree st(n, arr);
    st.build();

    cin >> t;
    while(t--) {
        cin >> q >> x >> y;
        if(q == 0) {
            if(arr[x] % 2 == y % 2) continue;
            st.update(x, y);
        } else {
            cout << st.query(x, y, q) << endl;
        }
    }
}
