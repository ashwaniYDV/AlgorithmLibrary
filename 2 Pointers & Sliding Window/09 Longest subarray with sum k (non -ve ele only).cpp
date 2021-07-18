// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size(), res = 0;
    long long sum = 0;

    int l = 0;
    for(int r = 0; r < n; r++) {
        sum += a[r];
        while(sum > k) {
            sum -= a[l];
            l++;
        }
        if(sum == k) {
            res = max(res, r - l + 1);
        }
    }
    return res;
}