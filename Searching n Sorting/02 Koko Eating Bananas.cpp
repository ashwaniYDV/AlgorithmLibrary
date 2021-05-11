// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        int left = 1, right = 0;
        for(int x: piles) {
            right = max(right, x);
        }
        while(left <= right) {
            int mid = (left + right) / 2;
            int sum = 0;
            for(int x: piles) {
                sum += (x + mid - 1) / mid;
            }
            if(sum > H) {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};






class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        int l = 1, r = 0;
        for(int x: piles) {
            r = max(r, x);
        }
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
