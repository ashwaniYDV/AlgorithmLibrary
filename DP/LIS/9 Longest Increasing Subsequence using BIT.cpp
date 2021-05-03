// https://www.geeksforgeeks.org/longest-increasing-subsequence-using-bit/

/*
Approach:  

1) First, use coordinate compression (replace all values of the array to numbers ranging from 1 to N). 
   This will reduce the maximum number in the array and help us solve the above problem in NlogN time. Also, this will help us to reduce memory.
2) Make a new array BIT of length N + 1.
3) Now, traverse the array from left to right and add the current element to the BIT.
4) When ith element (A[i]) is inserted in the BIT, check for the length of the longest subsequence that can be formed till A[i] – 1. 
   Let this value be x. If x + 1 is greater than the current element in BIT, update the BIT.
*/

// Method 1
#include <bits/stdc++.h>
using namespace std;

int n;

// Function to map numbers using coordinate compression
void coordinateCompression(vector<int>& arr) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    // Map will store the new elements
    int index = 1;
    map<int, int> mp;
    for (auto it: s) {
        mp[it] = index++;
    }

    for (int i = 0; i < n; i++) {
        // now change the current element to range 1 to N.
        arr[i] = mp[arr[i]];
    }
}

// Function to calculate length of maximum increasing sequence till i'th index
int query(vector<int>& BIT, int index) {
    int ans = 0;
    while (index > 0) {
        ans = max(ans, BIT[index]);
        index -= index & (-index);
    }
    return ans;
}

// Function for updating BIT array for maximum increasing sequence till i'th index
void update(vector<int>& BIT, int index) {

    // If 4 is inserted in BIT,
    // check for maximum length
    // subsequence till element 3.
    // Let this subsequence length be x.
    // If x + 1 is greater than
    // the current element in BIT,
    // update the BIT array
    int x = query(BIT, index - 1);
    int value = x + 1;
    while (index <= n) {

        // Store maximum length subsequence length till index
        // Here index is the coordinate compressed element
        BIT[index] = max(BIT[index], value);

        // Go to child node and update that node
        index += index & (-index);
    }
}

// Driver code
int main() {
    vector<int> arr = { 6, 5, 6, 1, 1, 1, 3, 2, 4, 8, 7 };
    n = arr.size();

    coordinateCompression(arr);
    vector<int> BIT(n+1, 0);

    for (int i = 0; i < n; i++) {
        // Add elements from left to right in BIT
        update(BIT, arr[i]);
    }

    int ans = query(BIT, n);

    cout << ans << endl;

    return 0;
}





















// Method 2
// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    static const int N = 1e5+5;
    int BIT[N];
    int n;
    
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

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        if(n == 0) return 0;
        
        // this preprocessing is done to make all the nums element unique
        vector<pair<int,int> > v;
        for(int i = 0; i < n; i++) v.push_back({nums[i], -i});
        sort(v.begin(), v.end());
        map<pair<int, int>, int> mp;
        int c = 1;
        for(auto i: v) mp[i] = c++;
        
        int LIS = 0;
        for(int i = 0; i < n; i++) {
            int x = query(mp[{nums[i], -i}]);
            // int x = query(mp[{nums[i], -i}] - 1);
            update(mp[{nums[i], -i}], x + 1);
            LIS = max(LIS, x + 1);
        }

        return LIS;
    }
};
