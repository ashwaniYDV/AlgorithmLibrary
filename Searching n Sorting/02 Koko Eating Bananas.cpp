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
