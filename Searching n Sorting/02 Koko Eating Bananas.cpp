// https://leetcode.com/problems/koko-eating-bananas/

// FFFFFFTTTTTTTTTT

class Solution {
public:
    bool check(int mid, int H, vector<int>& piles) {
        int total = 0;
        for (int p : piles) {
            total += (p + mid - 1) / mid;
        }

        return total <= H;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (check(mid, H, piles))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
