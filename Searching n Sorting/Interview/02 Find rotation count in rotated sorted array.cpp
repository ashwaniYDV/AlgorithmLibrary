// https://www.geeksforgeeks.org/problems/rotation4723/1

/*
Given an ascending sorted rotated array arr of distinct integers of size n. 
The array is right-rotated k times. Find the value of k.


Input: arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: 
    The original sorted array is 1 2 3 4 5. 
    We can see that the array was rotated 1 times to the right.
*/

class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int lo = 0, hi = n - 1;
        int res = INT_MAX;
        int pos = -1;
        
        while (lo <= hi) {
            // array is already sorted perfectly
            if (nums[lo] <= nums[hi]) {
                if (nums[lo] < res) {
                    res = nums[lo];
                    pos = lo;
                }
                break;
            }
    
            int mid = (lo + hi) / 2;
            
            // left part is monotonic thus updating our answer 
            // and then we will look for answer in right part (lo = mid + 1)
            if (nums[lo] <= nums[mid]) {
                if (nums[lo] < res) {
                    res = nums[lo];
                    pos = lo;
                }
                lo = mid + 1;
            } 
            // right part is monotonic thus updating our answer
            // and then we will look for answer in left part (hi = mid - 1)
            else {
                if (nums[mid] < res) {
                    res = nums[mid];
                    pos = mid;
                }
                hi = mid - 1;
            }
        }
        
        return pos;
	}

};