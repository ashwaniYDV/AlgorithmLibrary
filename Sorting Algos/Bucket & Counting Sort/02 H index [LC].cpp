// https://leetcode.com/problems/h-index/
// https://leetcode.com/problems/h-index-ii/
// https://leetcode.com/problems/h-index/solutions/70768/java-bucket-sort-o-n-solution-with-detail-explanation/

/*
Given an array of integers where 
citations[i] = no of citations a researcher received for their ith paper.
Return the researcher's h-index.
h-index is defined as max value of h such that given researcher has published at least h papers that have each been cited at least h times.
*/

/*
Note:
* What are the possible values of h-index? => 1 to n
* An easy approach is to sort the array first.
* A faster approach is to use extra space.
*/



// Method 1: Normal sort [Time = O(n*logn)]
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }

        return 0;
    }
};


// Method 2.1: Sorting + Binary search [Time = O(n*logn)]
// TTTTTFFFFFF
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin(), c.end());

        int l = 0, h = n;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            int cnt = c.end() - lower_bound(c.begin(), c.end(), mid);
            if(cnt >= mid) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return h;
    }
};

// Method 2.2: Sorting + Binary search [Time = O(n*logn)]
// FFFFFFTTTTTT
// This method is similar to Method 1
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin(), c.end());

        int l = 0, h = n-1;
        int res = 0;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(c[mid] >= n - mid) {
                h = mid - 1;
                res = n - mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};


// Method 3: Counting Sort [Time = O(n)]
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1, 0);
        
        for (int c: citations) {
            if (c >= n) {
                freq[n]++;
            } else {
                freq[c]++;
            }
        }
        
        int cnt = 0;
        for (int i = n; i >= 0; i--) {
            cnt += freq[i];
            if (cnt >= i) {
                return i;
            }
        }
        
        return 0;
    }
};