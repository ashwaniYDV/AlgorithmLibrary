// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
// https://youtu.be/iiYc32-4ZJY

/*
Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.

Input : 
n = 7 
array[] = {1, 2, 3, 6, 3, 6, 1}
Output: 
1, 3, 6
*/


/*
Algorithm: 
1) Traverse the given array from start to end.
2) For every element in the array increment the (arr[i] % n)‘th element by n.
3) Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1. 
   Which guarantees that the number n has been added to that index

This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater than n only 
if a value “i” has appeared more than once.
*/


class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            arr[arr[i] % n] = arr[arr[i] % n] + n;
        }
        
        for (int i = 0; i < n; i++) {
            if (arr[i] >= n * 2) {
                res.push_back(i);
            }
        }
        
        if(res.size() == 0) res.push_back(-1);
        return res;
    }
};










/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, 
return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
*/

// Method 1
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        // Since elements are in range 1..n, make it in range o...n-1
        for (int i = 0; i < n; i++) {
            nums[i]--;
        }
        
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            nums[nums[i] % n] = nums[nums[i] % n] + n;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] >= n * 2) {
                // push i+1 and not i since original array is 1...n
                res.push_back(i+1);
            }
        }
        
        return res;
    }
};



// Method 2
/*
This approach will not work if duplicates' frequency >=3.
In that case same elements will be printed twice or as many times as their (frequency - 1)
Thus we wont be able to print uniquely duplicate elements
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(idx + 1);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        
        return res;
    }
};
