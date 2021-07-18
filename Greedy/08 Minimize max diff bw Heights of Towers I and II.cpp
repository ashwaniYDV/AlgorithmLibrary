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
Intuition:
----------
* First sort the array.
* The idea is to, for every idx i:
    increase first i towers [0, ..., i] by k and 
    decrease rest towers [i+1, ..., n-1] by k
* Then calculate the max height diff.
*/

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n); 
        int ans = arr[n - 1] - arr[0];
        
        for (int i = 0; i < n - 1; i++) {
            // +k for arr[0, ..., i]
            // -k for arr[i+1, ..., n-1]
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
In case height becomes negative after decreasing then we do not have to decrease and have to only increase height of this tower)
*/

/*
Note
----
For Minimize the Heights II
We need not consider where a[i] < k because the height of the tower can’t be negative so we have to neglect that case.
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
