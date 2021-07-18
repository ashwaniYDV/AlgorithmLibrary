// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


class Solution{
public:
    int maxLen(vector<int>&arr, int n) { 
        long long sum = 0;
        int max_len = 0;
        
        // Map to store the previous sums
        unordered_map<long long, int> prevSums;
        prevSums[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (prevSums.count(sum)) {
                // mex length subarray ending at idx i and having sum = 0
                max_len = max(max_len, i - prevSums[sum]);
            }  else {
                prevSums[sum] = i;
            }
        }

        return max_len;
    }
};




class Solution{
    public:
    int maxLen(vector<int>&arr, int n) {
        int sum = 0, max_len = 0;

        // Map to store the previous sums
        unordered_map<int, int> prevSums;

        // Traverse through the given array
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                max_len = i + 1;
            }

            if (prevSums.count(sum)) {
                max_len = max(max_len, i - prevSums[sum]);
            }  else {
                prevSums[sum] = i;
            }
        }

        return max_len;
    }
};
