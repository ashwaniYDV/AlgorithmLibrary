// https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/0/
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// https://youtu.be/Av7vSnPSCtw



/*
Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Note: Assume that height of the tower can be negative.
(It is mandatory to either decrease or increase height of every tower by k)
*/



/*
First, we try to sort the array and make each height of the tower maximum. 
We do this by decreasing the height of all the towers towards the right by k and increasing all the height of the towers towards the left (by k). 
It is also possible that the tower you are trying to increase the height doesn’t have the maximum height. 
Therefore we only need to check whether it has the maximum height or not by comparing it with the last element towards the right side which is a[n]-k. 
Since the array is sorted if the tower’s height is greater than the a[n]-k then it’s the tallest tower available. 
Similar reasoning can also be applied for finding the shortest tower.  

Note:
For Minimize the Heights II
We need not consider where a[i] < k because the height of the tower can’t be negative so we have to neglect that case.
*/


class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n); 
        int ans = arr[n - 1] - arr[0];
        
        for (int i = 0; i < n - 1; i++) {
            int high = max(arr[n-1] - k, arr[i] + k);
            int low = min(arr[0] + k, arr[i+1] - k);
            ans = min(ans, high - low);
        }
        return ans;
    }
};













/*
Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once. 
After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

(It is mandatory to either decrease or increase height of every tower by k.
In case height becomes negative after decreasing then we do not have to decrease and have to only increase th height of this tower)
*/

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n); 
        int ans = arr[n - 1] - arr[0];
        
        for (int i = 0; i < n - 1; i++) {
            if(arr[i + 1] >= k) {
                int high = max(arr[n - 1] - k, arr[i] + k);
                int low = min(arr[0] + k, arr[i + 1] - k);
                ans = min(ans, high - low);
            }
        }
        return ans;
    }
};
