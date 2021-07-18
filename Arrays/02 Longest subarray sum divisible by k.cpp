// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

/*
Given an arr[] containing n integers and a positive integer k. 
Find the length of the longest subarray with sum of the elements divisible by the given value k.

Input:
A[] = {-2, 2, -5, 12, -11, -1, 7}
K = 3
Output: 5
Explanation:
The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.

Input : arr[] = {2, 7, 6, 1, 4, 5}, k = 3
Output : 4
Explanation:
The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.
*/


class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0, prefSumMod = 0;

        for (int i = 0; i < n; i++) {
            prefSumMod = (prefSumMod + arr[i]) % k;
            if (prefSumMod < 0) prefSumMod += k;

            if (mp.find(prefSumMod) != mp.end()) {
                res = max(res, i - mp[prefSumMod]);
            } else {
                mp[prefSumMod] = i;
            }
        }

        return res;
    }
};






// More optimized
class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        vector<int> mp(k + 1, -2);
        mp[0] = -1;
        int res = 0, prefSumMod = 0;

        for (int i = 0; i < n; i++) {
            prefSumMod = (prefSumMod + arr[i]) % k;
            if (prefSumMod < 0) prefSumMod += k;

            if (mp[prefSumMod] != -2) {
                res = max(res, i - mp[prefSumMod]);
            } else {
                mp[prefSumMod] = i;
            }
        }

        return res;
    }
};
