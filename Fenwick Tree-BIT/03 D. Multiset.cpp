// https://youtu.be/fgEe-iPdqeI
// https://youtu.be/imHu-B73MlI  (binary lifting)
// https://codeforces.com/problemset/problem/1354/D

/*
You are given a multiset consisting of n integers. You have to process queries of two types:
(a) add integer k into the multiset;
(b) find the k-th order statistics in the multiset and remove it.
k-th order statistics in the multiset is the k-th element in the sorted list of all elements of the multiset. 
For example, if the multiset contains elements 1, 4, 2, 1, 4, 5, 7, and k=3, 
then you have to find the 3-rd element in [1,1,2,4,4,5,7], which is 2. 
If you try to delete an element which occurs multiple times in the multiset, only one occurence is removed.

After processing all queries, print any number belonging to the multiset, or say that it is empty.
If the multiset is empty after all queries, print 0.

Input
The first line contains two integers n and q (1≤n,q≤106) — the number of elements in the initial multiset and the number of queries, respectively.
The second line contains n integers a1, a2, ..., an (1≤a1≤a2≤⋯≤an≤n) — the elements of the multiset.
The third line contains q integers k1, k2, ..., kq, each representing a query:
(a) if 1 ≤ ki ≤ n, then the i-th query is "insert ki into the multiset";
(b) if ki < 0, then the i-th query is "remove the |ki|-th order statistics from the multiset". 
For (b) this query, it is guaranteed that |ki| is not greater than the size of the multiset.
*/

// Method 1: O[N.(logN)^2]
const int N = 1e6+5;
int n, m, k;

int BIT[N+5];

void update(int i, int val) {
    while(i > 0 && i < N) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}

int find(int k) {
    int low = 1, high = N;
    while(low < high) {
        int mid = low + (high - low) / 2;
        int val = query(mid);
 
        if(val >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
 
void solve() {
    int q, x;
    cin >> n >> q;
    loop(i, 1, n) {
        cin >> x;
        update(x, 1);
    }
    while(q--) {
        cin >> x;
        if(x > 0) {
            update(x, 1);
        } else {
            x = -1*x;
            int pos = find(x);
            update(pos, -1);
        }
    }
 
    // output part
    int res = query(N);
    if(!res) {
        cout << 0 << endl;
        return;
    }
 
    cout << find(1) << endl;
}

















// Method 2: O[N.(logN)]   (Using binary lifting)
const int N = 1e6+5;
int n, m, k;
 
int BIT[N+5];
 
void update(int i, int val) {
    while(i < N) {
        BIT[i] += val;
        i += (i&-i);
    }
}
 
int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}

int prefixSumLB(int prefixSum) {
    int curr = 0, prevSum = 0;
    for (int i = log2(N); i >= 0; i--) {
        if((curr + (1 << i)) < N && BIT[curr + (1 << i)] + prevSum < prefixSum) {
            curr += (1 << i);
            prevSum += BIT[curr];
        }
    }
    return curr + 1;
}

void solve() {
    int q, x;
    cin >> n >> q;
    loop(i, 1, n) {
        cin >> x;
        update(x, 1);
    }
    
    while(q--) {
        cin >> x;
        if(x > 0) {
            update(x, 1);
        } else {
            x = -1*x;
            int pos = prefixSumLB(x);
            update(pos, -1);
        }
    }
 
    // output part
    int res = query(N);
    if(!res) {
        cout << 0 << endl;
        return;
    }
 
    cout << prefixSumLB(1) << endl;
}
