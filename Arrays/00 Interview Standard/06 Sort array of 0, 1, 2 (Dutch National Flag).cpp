// https://leetcode.com/problems/sort-colors/
// https://youtu.be/tp8JIuCXBaU

/*
Dutch national flag algorithm (Rules:)
======================================

0 to (lo-1)      =>  filled with 0s
lo to (mid-1)    =>  filled with 1s
mid to hi        =>  filled with random numbers (0, 1, 2)
(hi+1) to (n-1)  =>  filled with 2s

[0 -------- lo-1]  [lo -------- mid-1]  [mid -------- hi]  [hi+1 -------- n-1]
    00000000            11111111                               22222222


Observations:
* Thus, array is unsorted from mid to hi indexes only
* Since in the begining, entire array is unsorted, so => (mid = 0 and hi = n-1)



Inside while loop => check the 3 possible values of mid (0 or 1 or 2)

Case 1: (nums[mid] == 0)
========================
0               lo-1    lo             mid-1   mid                      hi   hi+1              n-1
0     0     0     0     1     1     1     1     0     2     1     1     0     2     2     2     2
-------------------    ---------------------   ---------------------------   ----------------------

If we swap (nums[lo] = 1, nums[mid] = 0), then also array will be sorted as defined by above rules

0               lo-1    lo             mid-1   mid                      hi   hi+1              n-1
0     0     0     0     0     1     1     1     1     2     1     1     0     2     2     2     2
-------------------    ---------------------   ---------------------------   ----------------------

Now to follow the above defined rules, we have to do (lo++) and (mid++)

0                     lo-1    lo             mid-1   mid               hi   hi+1              n-1
0     0     0     0     0     1     1     1     1     2     1     1     0     2     2     2     2
--------------------------    --------------------   --------------------   ----------------------



Case 2: (nums[mid] == 1)
========================
0               lo-1    lo             mid-1   mid                      hi   hi+1              n-1
0     0     0     0     1     1     1     1     1     2     1     1     0     2     2     2     2
--------------------    --------------------   ---------------------------   ----------------------

Just do mid++ to follow the above defined rules

0               lo-1    lo                   mid-1   mid                hi   hi+1              n-1
0     0     0     0     1     1     1     1     1     2     1     1     0     2     2     2     2
--------------------    ---------------------------  ---------------------   ----------------------



Case 3: (nums[mid] == 2)
========================

0               lo-1    lo             mid-1   mid                      hi   hi+1              n-1
0     0     0     0     1     1     1     1     2     2     1     1     0     2     2     2     2
--------------------    -------------------    ---------------------------   ---------------------

If we swap (nums[mid] = 2, nums[hi] = 0), then also array will be sorted as defined by above rules

0               lo-1    lo             mid-1   mid                      hi   hi+1              n-1
0     0     0     0     1     1     1     1     0     2     1     1     2     2     2     2     2
--------------------    -------------------    ---------------------------   ---------------------

Now to follow the above defined Rules, we have to do (hi--)

0               lo-1    lo             mid-1   mid                hi   hi+1                    n-1
0     0     0     0     1     1     1     1     0     2     1     1     2     2     2     2     2
--------------------    -------------------    --------------------    ----------------------------
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            // check the 3 possible values of mid (0 or 1 or 2)
            if(nums[mid] == 0) {
                swap(nums[lo++], nums[mid++]); 
            } 
            else if(nums[mid] == 1) {
                mid++; 
            }
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[hi--]); 
            }
        }
    }
};
