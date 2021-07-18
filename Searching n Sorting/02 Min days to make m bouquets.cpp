// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

/*
Given an integer array bloomDay, an integer m and an integer k.
We need to make m bouquets. 
To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return min number of days you need to wait to be able to make m bouquets from the garden. 
If it is impossible to make m bouquets return -1.
*/


// FFFFTTTTT

// Method 1
class Solution {
public:
    bool check(int mid, vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int consecutiveFlowers = 0, noOfBouq = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                consecutiveFlowers++;
                if (consecutiveFlowers == k) {
                    noOfBouq++;
                    consecutiveFlowers = 0;
                }
            } else {
                consecutiveFlowers = 0;
            }
        }
        return noOfBouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (check(mid, bloomDay, m, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};



// Method 2
class Solution {
public:
    bool check(int mid, vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int consecutiveFlowers = 0, noOfBouq = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                consecutiveFlowers++;
                if (consecutiveFlowers == k) {
                    noOfBouq++;
                    consecutiveFlowers = 0;
                }
            } else {
                consecutiveFlowers = 0;
            }
        }
        return noOfBouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(mid, bloomDay, m, k)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // lo will be our answer and not hi
        // since we set hi = mid-1 when our checker function was true for mid
        return lo;
    }
};
