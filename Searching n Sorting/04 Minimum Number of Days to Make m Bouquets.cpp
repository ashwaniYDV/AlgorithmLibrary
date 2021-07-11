// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// FFFFTTTTT

class Solution {
public:
    bool check(int mid, vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int consecutiveFlowers = 0, noOfBouq = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] > mid) {
                consecutiveFlowers = 0;
            } else {
                consecutiveFlowers++;
                if (consecutiveFlowers == k) {
                    noOfBouq++;
                    consecutiveFlowers = 0;
                }
            }
        }
        return noOfBouq >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;
        
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
