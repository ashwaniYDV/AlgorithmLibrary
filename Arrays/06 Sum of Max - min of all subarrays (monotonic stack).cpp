// https://codeforces.com/problemset/problem/817/D
// D. Imbalanced Array
// https://youtu.be/ST408u9EnVg


/*
You are given an array a consisting of n elements. 
The imbalance value of some subsegment of this array is the difference between the maximum and minimum element from this segment. 
The imbalance value of the array is the sum of imbalance values of all subsegments of this array.

For example, the imbalance value of array [1, 4, 1] is 9, because there are 6 different subsegments of this array:
[1] (from index 1 to index 1), imbalance value is 0;
[1, 4] (from index 1 to index 2), imbalance value is 3;
[1, 4, 1] (from index 1 to index 3), imbalance value is 3;
[4] (from index 2 to index 2), imbalance value is 0;
[4, 1] (from index 2 to index 3), imbalance value is 3;
[1] (from index 3 to index 3), imbalance value is 0;
You have to determine the imbalance value of the array a.

Input
The first line contains one integer n (1 ≤ n ≤ 106) — size of the array a.
The second line contains n integers a1, a2... an (1 ≤ ai ≤ 106) — elements of the array.

Output
Print one integer — the imbalance value of a.
*/




// Method 1: Time = O(n^2*logn)
/*
For all subarrays find min and max using segment tree
*/






// Method 2: Time = O(n)
/*
Let different subarrays be a1, a2, a3, ...
res = [max(a1) - min(a1)] + [max(a2) - min(a2)] + [max(a3) - min(a3)] + ...
res = [max(a1) + max(a2) + max(a3) + ...] - [min(a1) + min(a2) + min(a3) + ...]
*/

const int N = 1e5 + 5;
int n, m;

int sumSubarrayMaxs(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    // ngl = (NGL+1)th idx, ngr = (NGR - 1)th idx
    vector<int> ngl(n), ngr(n);
    
    // getting number of element strictly smaller than nums[i] on Left.
    for(int i = 0; i < n; i++) {
        // here equality is not included
        while(!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            ngl[i] = st.top() + 1;
        } else {
            ngl[i] = 0;
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    // getting number of element larger or equal to nums[i] on Right.
    for(int i = n-1; i >= 0; i--) {
        // here equality is included
        while(!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            ngr[i] = st.top() - 1;
        } else {
            ngr[i] = n-1;
        }
        st.push(i);
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        int left = i - ngl[i] + 1;
        int right = ngr[i] - i + 1;
        int cnt = left * right;
        res += nums[i] * cnt;
    }
    
    return res;
}

int sumSubarrayMins(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    // nsl = (NSL+1)th idx, nsr = (NSR - 1)th idx
    vector<int> nsl(n), nsr(n);
    
    // getting number of element strictly larger than nums[i] on Left.
    for(int i = 0; i < n; i++) {
        // here equality is not included
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            nsl[i] = st.top() + 1;
        } else {
            nsl[i] = 0;
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    // getting number of element larger or equal to nums[i] on Right.
    for(int i = n-1; i >= 0; i--) {
        // here equality is included
        while(!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if(!st.empty()) {
            nsr[i] = st.top() - 1;
        } else {
            nsr[i] = n-1;
        }
        st.push(i);
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        int left = i - nsl[i] + 1;
        int right = nsr[i] - i + 1;
        int cnt = left * right;
        res += nums[i] * cnt;
    }
    
    return res;
}

void solve() {
    cin >> n;
    vi a(n);
    f(i, n) cin >> a[i];
    cout << sumSubarrayMaxs(a) - sumSubarrayMins(a) << endl;
}
