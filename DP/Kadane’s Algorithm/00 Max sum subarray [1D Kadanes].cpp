// https://leetcode.com/problems/maximum-subarray/
// https://www.techiedelight.com/print-continuous-subarray-with-maximum-sum/

/*
Maximum sum subarray
*/

// Method 1.1 (answer can be negative, i.e. we have to include atleast one element)
void kadane() {
    vector < int > arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    int maxSoFar = INT_MIN, maxEndingHere = 0;
    int start = 0, end = 0;

    // stores starting index of a positive-sum sequence
    int beg = 0;

    // traverse the given array
    for (int i = 0; i < n; i++) {
        // update the maximum sum of subarray "ending" at index `i`
        maxEndingHere += arr[i];

        // update result if the current subarray sum is found to be greater
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = beg;
            end = i;
        }

        // if the maximum sum is negative, set it to 0
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            beg = i + 1;
        }
    }

    cout << "Sum = " << maxSoFar << endl;
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
}



// Method 1.2 (answer is non-negative, i.e. we can return empty array)
void kadane() {
    vector < int > arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    int maxSoFar = INT_MIN, maxEndingHere = 0;
    int start = 0, end = 0;

    // stores starting index of a positive-sum sequence
    int beg = 0;

    // traverse the given array
    for (int i = 0; i < n; i++) {
        // update the maximum sum of subarray "ending" at index `i`
        maxEndingHere += arr[i];

        // if the maximum sum is negative, set it to 0
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            beg = i + 1;
        }

        // update result if the current subarray sum is found to be greater
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = beg;
            end = i;
        }
    }

    cout << "Sum = " << maxSoFar << endl;
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
}


// Method 2 (answer can be negative, i.e. we have to include atleast one element)
/*
For i'th index:
curr_max = max contiguous subarray sum ending at index i (including a[i]) 
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_mx = 0, res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            cur_mx = max(nums[i], cur_mx + nums[i]);
            res = max(res, cur_mx);
        }
        return res;
    }
};




// another way to store start, end indices
void kadane() {
    int maxSoFar = INT_MIN, maxEndingHere = 0;
    int start = 0, end = 0;
    int beg = 0;

    for (int i = 0; i < n; i++) {
        if (maxEndingHere == 0) {
            beg = i;
        }
        maxEndingHere += arr[i];

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = beg;
            end = i;
        }

        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
}