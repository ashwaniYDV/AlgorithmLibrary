
// O(n.log(n))
// https://youtu.be/on2hvxBXJH4?si=dCzecFQHRgUGpfav

// O(nlog(n))          [Increasing Subsequence]

/*
Intuition1
==========
A  = 1, 7, 8, 4, 5, 6, -1, 9

d1 = 1, 7, 8, 9
d2 = 1, 4, 5, 6, 9
d3 = -1, 9

max length = d2 = 5

Intuition2
==========
A  = 1, 7, 8, 4, 5, 6, -1, 9

instead of using 3 arrays d1, d2, d3 -> we can form a single array in steps as shown
seq = 1
seq = 1, 7
seq = 1, 7, 8
seq = 1, 4, 8
seq = 1, 4, 5
seq = 1, 4, 5, 6
seq = -1, 4, 5, 6
seq = -1, 4, 5, 6, 9


Intuition3
==========
What happens is that lets suppose you have a LIS upto a particular index.
Now you encountered an element which is greater than the rightmost element.
We will obviously take it to increase our length of LIS.
But, if the new element is smaller than last element in LIS, we can't increase our LIS length.
What we can do is, find an element just greater than it (ie lowerbound) in the LIS and replace it with this element.
This ensures that upto that index we can have an LIS.
And it will help when future values come.
Eg: 1 2 4 5 3 4 5.
    In this case, 1 2 4 5 - upto this it's obvious.
    Now 3 < 5, so what we can do is that we can replace 4 with 3,
    it doesn't mean that the LIS is 1 2 3 5, it's still 1 2 4 5 but we get a smaller LIS of 1 2 3.
    Now when 4 comes, again 4 < 5, so we cant't increase our LIS, but we can create a new LIS upto 4 which is 1 2 3 4 
    now when 5 comes we can increase our LIS (1, 2, 3, 4, 5) and finally length is 5.
    We are storing the min elements because it helps to update future values.
I myself struggled to understand it a few months back, but with experience things become clear.
*/
class Solution {
public:
    int lower_bound(vector<int>& a, int x) {
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
        return lo;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > seq.back()) {
                seq.push_back(nums[i]);
            } else {
                // int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                int idx = lower_bound(seq, nums[i]);
                seq[idx] = nums[i];
            }
        }
        
        return seq.size();
    }
};



// O(nlog(n))          [Non decreasing Subsequence]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] >= seq.back()) {
                seq.push_back(nums[i]);
            } else {
                int idx = upper_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[idx] = nums[i];
            }
        }
        
        return seq.size();
    }
};


// Using BIT 
// https://codeforces.com/problemset/problem/340/D
// O(nlog(n))          [Increasing Subsequence]
const int N = 2e5+5;
int n, m;
int BIT[N];

void update(int i, int val) {
    while(i <= n) {
        BIT[i] = max(BIT[i], val);
        i += (i&-i);
    }
}
int query(int i) {
    int mx = 0;
    while(i > 0) {
        mx = max(mx, BIT[i]);
        i -= (i&-i);
    }
    return mx;
}

void solve() {
    cin >> n;
    vi nums(n);
    f(i, n) cin >> nums[i];
    
    // coordinate compression in sorted order
    vi temp = nums;
    sort(all(temp));
    map<int, int> mp;
    int c = 1;
    f(i, n) {
        if(mp.count(temp[i]) == 0) {
            mp[temp[i]] = c++;
        }
    }

    f(i, n) nums[i] = mp[nums[i]];
    
    int LIS = 0;
    for(int i = 0; i < n; i++) {
        int x = query(nums[i]);
        update(nums[i], x + 1);
        LIS = max(LIS, x + 1);
    }

    cout << LIS;
}
