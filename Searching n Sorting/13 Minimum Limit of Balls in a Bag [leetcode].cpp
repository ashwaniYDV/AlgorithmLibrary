// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

/*
Problem:
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.
*/


/*
Binary search the size of bag, which is called penalty in this problem.

For each penalty value, we split the balls into bags with this value.
For example, the mid = 3,
A[i] = 2, we split it into [2], and operations = 0
A[i] = 3, we split it into [3], and operations = 0
A[i] = 4, we split it into [3,1], and operations = 1
A[i] = 5, we split it into [3,2], and operations = 1
A[i] = 6, we split it into [3,3], and operations = 1
A[i] = 7, we split it into [3,3,1], and operations = 2

The number of operation we need is (a - 1) / mid

If the total operation > max operations,
the size of bag is too small,
we set left = mid + 1

Otherwise,
this size of bag is big enough,
we set right = mid

We return the final result,
where result = left = right.
*/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int x : nums)
                count += (x - 1) / mid;
            
            if (count > maxOperations)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};










class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int x : nums)
                count += (x - 1) / mid;
            
            if (count <= maxOperations)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};
