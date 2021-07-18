// https://www.scaler.com/hire/test/problem/max-sum-queries/

/*
You are given an array A of size N consisting of integers.
You have to process Q queries of two types on it:
1) i, x: change the i-th element of A to x.
2) l, r: find the maximum value of (A[i]+A[i+1]...A[j]) over all pairs (i,j) such that l <= i <= j <= r.


Problem Constraints
1 <= N,Q <= 10^5
-1000 <= A[i] <= 1000 (for all i in [1...N])

For query of the 1st type,
1 <= i <= N
-1000 <= x <= 1000

For query of the 2nd type,
1 <= l <= r <= N
*/



/*
We need to keep 4 values in the segment tree node.

maxSum - It is the value of max subarray sum of this segment.
maxPrefix - It is the value of max prefix sum (sum of beginning elements)
maxSuffix - It is the value of max suffix sum (sum of last few elements)
sum - It is the value of sum of all values in the node

How do we get the value of a node from its children?

We do the following:

sum = sum of left child + sum of right child

maxPrefix - either we take the prefix entirely from the left child, or the whole left child and some prefix from the right child.

maxPrefix = max(left.maxPrefix,left.sum+right.maxPrefix)

maxSuffix - either we take the suffix entirely from the right child, or we take the whole right child and some suffix from the left child.

maxSuffix = max(right.maxSuffix,right.sum+left.maxSuffix)

maxSum - either we take the sum entirely from the left child or the right child, or we take sum partially from both (some suffix of left child and some prefix of right child).

maxSum = max(left.maxSum, right.maxSum, left.maxSuffix + right.maxPrefix)
*/


#include<bits/stdc++.h>
using namespace std;

struct node {
    int maxPrefix, maxSuffix, sum, maxSum;
}
neg;
vector < node > a, tree;
node merge(node a, node b) {
    struct node ret;
    ret.sum = a.sum + b.sum;
    ret.maxSuffix = max(b.maxSuffix, b.sum + a.maxSuffix);
    ret.maxPrefix = max(a.maxPrefix, a.sum + b.maxPrefix);
    ret.maxSum = max(max(a.maxSum, b.maxSum), a.maxSuffix + b.maxPrefix);
    return ret;
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    } else {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx].maxPrefix = val;
        a[idx].maxSuffix = val;
        a[idx].sum = val;
        a[idx].maxSum = val;
        tree[node] = a[idx];
    } else {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
}
struct node query(int node, int start, int end, int l, int r) {
    if (r < start or end < l) {
        return neg;
    }
    if (l <= start and end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    struct node p1 = query(2 * node + 1, start, mid, l, r);
    struct node p2 = query(2 * node + 2, mid + 1, end, l, r);
    return merge(p1, p2);
}

vector < int > Solution::solve(vector < int > & A, vector < vector < int > > & B) {
    a.clear();
    tree.clear();
    int n = A.size();
    vector < int > v;
    neg.sum = 0;
    neg.maxPrefix = -1e9;
    neg.maxSuffix = -1e9;
    neg.maxSum = -1e9;
    a.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        a[i].maxPrefix = A[i];
        a[i].maxSuffix = A[i];
        a[i].sum = A[i];
        a[i].maxSum = A[i];
    }
    build(0, 0, n - 1);
    for (auto q: B) {
        int type = q[0];
        if (type == 1) {
            int i = q[1];
            --i;
            int x = q[2];
            update(0, 0, n - 1, i, x);
        } else {
            int l = q[1];
            int r = q[2];
            --l;
            --r;
            struct node ret = query(0, 0, n - 1, l, r);
            int ans = ret.maxSum;
            v.push_back((int) ans);
        }
    }
    return v;
}
