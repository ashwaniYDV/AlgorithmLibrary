// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// https://youtu.be/nhEMDKMB44g?si=Di0GU4dC1FInJFpQ
// https://youtu.be/j3187M1P2Xg

/*
Note:
* It is not like non-monotonical part will always contains answer. Monotonical part may also contain answer.

if (nums[lo] <= nums[hi]) we can update answer with nums[lo]
if (nums[lo] <= nums[mid]) we can update answer with nums[lo]
if (nums[mid] <= nums[hi]) we can update answer with nums[mid]
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int res = INT_MAX;
        
        while (lo <= hi) {
            // array is already sorted perfectly
            if (nums[lo] <= nums[hi]) {
                res = min(res, nums[lo]);
                break;
            }

            int mid = (lo + hi) / 2;
            
            // left part is monotonic thus updating our answer 
            // and then we will look for answer in right part (lo = mid + 1)
            if (nums[lo] <= nums[mid]) {
                res = min(res, nums[lo]);
                lo = mid + 1;
            } 
            // right part is monotonic thus updating our answer
            // and then we will look for answer in left part (hi = mid - 1)
            else {
                res = min(res, nums[mid]);
                hi = mid - 1;
            }
        }
        
        return res;
    }
};



/*
Looking at subarray with index [lo, hi]. We can find out that if the first member is less than the last member, there's no rotation in the array. 
So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. 
If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. 
Else, it is in the first half in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        
        while (lo < hi) {
            if (nums[lo] < nums[hi]) return nums[lo];
            
            int mid = (lo + hi) / 2;
            
            // left part is monotonic thus pivot lies in right part
            if (nums[lo] <= nums[mid]) {
                lo = mid + 1;
            } 
            // right part is monotonic thus pivot lies in left part
            else {
                hi = mid;
            }
        }
        
        return nums[lo];
    }
};
