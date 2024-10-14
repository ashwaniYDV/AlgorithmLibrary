// https://leetcode.com/problems/random-pick-with-weight/description/

/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
The probability of picking an index i is w[i] / sum(w).
For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 
Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]
*/

class Solution {
public:
    int n, total;
    vector<int> prefSum;

    Solution(vector<int>& w) {
        n = w.size();
        int sum = 0;
        for(int& x: w) {
            sum += x;
            prefSum.push_back(sum);
        }

        total = sum;
    }

    // utility function to generate random number between 1 and m (inclusive)
    int generateRandomNumber(int m) {
        return (rand() % m) + 1;
    }
    
    int pickIndex() {
        // random numner between 1 and total
        int rn = generateRandomNumber(total);
        int idx = lower_bound(prefSum.begin(), prefSum.end(), rn) - prefSum.begin();
        return idx;
    }
};
