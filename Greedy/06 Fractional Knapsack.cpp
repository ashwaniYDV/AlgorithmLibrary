// https://www.geeksforgeeks.org/fractional-knapsack-problem/
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:
Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack. 
*/


class Solution {
public:
    // sort Item according to val / weight ratio
    static bool compare(Item& a, Item& b) {
        return ((double)a.value / a.weight) > ((double)b.value / b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, compare);
        double res = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i].weight <= W) {
                W -= arr[i].weight;
                res += arr[i].value;
            } else {
                double d = (double)arr[i].value / arr[i].weight;
                res += d * W;
                break;
            }
        }
        
        return res;
    }
};