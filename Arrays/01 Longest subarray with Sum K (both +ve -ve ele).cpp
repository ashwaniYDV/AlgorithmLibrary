// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// https://youtu.be/frf7qxiN2qU?si=knLB_Z9CwivvGEUL


class Solution{
public:
    int lenOfLongSubarr(int arr[],  int n, int k) { 
        long long sum = 0;
        int maxLen = 0;
        
        unordered_map<long long, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
  
            if (mp.count(sum - k)) {
                // mex length subarray ending at idx i and having sum = k
                maxLen = max(maxLen, i - mp[sum - k]);
            }

            if (!mp.count(sum)) mp[sum] = i;
        }

        return maxLen;
    }
};


class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) { 
        int sum = 0, maxLen = 0, startIdx, endIdx;

        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
  
            if (mp.count(sum - k)) {
                if (maxLen < (i - mp[sum - k])) {
                    maxLen = i - mp[sum - k];
                    startIdx = mp[sum - k] + 1;
                    endIdx = i;
                }
            }

            if (!mp.count(sum)) mp[sum] = i;
        }

        return maxLen;
    }
};






class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) { 
        int sum = 0, maxLen = 0, startIdx, endIdx;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum == k) {
                maxLen = i + 1;
                startIdx = 0;
                endIdx = i;
            }
  
            if (mp.count(sum - k)) {
                if (maxLen < (i - mp[sum - k])) {
                    maxLen = i - mp[sum - k];
                    startIdx = mp[sum - k] + 1;
                    endIdx = i;
                }
            }

            if (!mp.count(sum)) mp[sum] = i;
        }

        return maxLen;
    }
};