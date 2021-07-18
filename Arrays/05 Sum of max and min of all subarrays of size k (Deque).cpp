// https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047

/*
You are given an array consisting of N integers, and an integer, K. 
Your task is to determine the total sum of the minimum element and the maximum element of all subarrays of size K.

Note :
The array may contain duplicate elements.
The array can also contain negative integers.
The size of the array is at least 2.
There exists at least one such subarray of size k.
*/

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	long long res = 0;
    deque<int> MX, MN;

    int i;
    for (i = 0; i < k; ++i) {
        // max
        while ((!MX.empty()) && nums[i] >= nums[MX.back()]) {
            MX.pop_back();
        }
        MX.push_back(i);
        
        // min
        while ((!MN.empty()) && nums[i] <= nums[MN.back()]) {
            MN.pop_back();
        }
        MN.push_back(i);
    }
    res += nums[MX.front()] + nums[MN.front()];

    for (; i < n; ++i) {
        // max
        while ((!MX.empty()) && MX.front() <= i - k) {
            MX.pop_front();
        }
        while ((!MX.empty()) && nums[i] >= nums[MX.back()]) {
            MX.pop_back();
        }
        MX.push_back(i);
        
        // min
        while ((!MN.empty()) && MN.front() <= i - k) {
            MN.pop_front();
        }
        while ((!MN.empty()) && nums[i] <= nums[MN.back()]) {
            MN.pop_back();
        }
        MN.push_back(i);
        
        res += nums[MX.front()] + nums[MN.front()];
    }
    
    return res;
}
