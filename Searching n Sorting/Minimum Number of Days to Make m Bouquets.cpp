// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        if(m * k > n) return -1;
        
        int left = 1, right = 1e9;
        while(left <= right) {
            int mid = (left + right) / 2;
            int consecutiveFlowers = 0, noOfBouq = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] > mid) {
                    consecutiveFlowers = 0;
                } else {
                    consecutiveFlowers++;
                    if(consecutiveFlowers == k) {
                        noOfBouq++;
                        consecutiveFlowers = 0;
                    }
                }
            }
            if(noOfBouq < m) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};














class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size(), left = 1, right = 1e9;
        if (m * k > n) return -1;
        
        while (left < right) {
            int mid = (left + right) / 2, consecutiveFlowers = 0, noOfBouq = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > mid) {
                    consecutiveFlowers = 0;
                } else {
                    consecutiveFlowers++;
                    if (consecutiveFlowers == k) {
                        noOfBouq++;
                        consecutiveFlowers = 0;
                    }
                }
            }
            if (noOfBouq < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
