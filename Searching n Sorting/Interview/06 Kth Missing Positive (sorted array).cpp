// https://leetcode.com/problems/kth-missing-positive-number/
// https://youtu.be/uZ0N_hZpyps?si=Jf-adf6Qh_QR9UqX

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Input: 
    arr = [2, 3, 4, 7, 11], k = 5
Output: 
    9
Explanation: 
    The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
    The 5th missing positive integer is 9.
*/



// Method 1 (Time = n)
// We have to do it in logn
/*
* Suppose all elements less than k are absent in array, then res = k
* Then we can loop through the array and whenever arr[i] < k, we can increment k
* Since arr[i] (< k or res) is present in array so our answer will be > k
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int res = k;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > res) return res;
            
            // when arr[i] <= res, we have to increment res
            res++;
        }
        return res;
    }
};




// Method 2 (Time = logn*logn)
// FFFFFFFFTTTTTTTTTT
class Solution {
public:
    bool check(int mid, vector<int>& arr, int k) {
        // int nmbrsLessThanEqToMid = 0;
        // for(int i = 0; i < arr.size(); i++) {
        //     if(arr[i] > mid) break;
        //     nmbrsLessThanEqToMid++;
        // }

        int nmbrsLessThanEqToMid = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();

        return (mid - nmbrsLessThanEqToMid) >= k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 1;
        // suppose a = [1, 2, 3, 4] and k = 3, then res = 4 (max ele) + 3 (k) = 7
        int hi = *max_element(arr.begin(), arr.end()) + k;

        while(lo < hi) {
            int mid = (lo + hi) / 2;
            
            if(check(mid, arr, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;


        /*
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if(check(mid, arr, k)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
        */
    }
};







// Method 3 (Most optimal, Time = logn)
// https://youtu.be/uZ0N_hZpyps?si=Jf-adf6Qh_QR9UqX
// FFFFFFFFFTTTTTTTTT

/*
idx           =   0    1    2    3    4
idx 1 based   =   1    2    3    4    5
arr           =   2,   3,   4,   7,   11
no of missing =  2-1  3-2  4-3  7-4  11-5
              =   1    1    1    3    6

but want k = 5th missing number
since at arr[i] = 7 (3 numbers are missing) and arr[i] = 11 (6 numbers are missing)
thus answer lies bw 7 and 11


idx           =   0    1    2    3    4
idx 1 based   =   1    2    3    4    5
arr           =   2,   3,   4,   7,   11
no of missing =   1    1    1    3    6
                                hi    lo

when while loop ends hi(idx) = 3, lo(idx) = 4

res = k + (no of elements less than k which are there in the arr)
    = k + (1 based index of hi)
    = k + (hi + 1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size()-1;

        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            int noOfMissingNumbers = arr[mid] - (mid+1);

            if(noOfMissingNumbers >= k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // hi < lo when while loop ends
        // lo if true condition, hi is false condition
        // FFFFTTTTTT
        return k + (hi + 1);
        // Note: hi+1=lo, thus we can return (k+lo) also
    }
};


// Method 3.2
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();

        while(lo < hi) {
            int mid = (lo + hi) / 2;

            int noOfMissingNumbers = arr[mid] - (mid+1);

            if(noOfMissingNumbers >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // hi == lo when while loop ends
        // lo, hi are true condition
        // idx = lo-1 (or hi-1) is false condition
        // FFFFTTTTTT
        int idx = lo - 1;
        return k + (idx + 1);
        // Note: idx+1=lo, thus we can return (k+lo) also
    }
};