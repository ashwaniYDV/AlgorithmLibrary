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
    static bool compare(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, compare);

        int curWeight = 0;
        double res = 0;

        for (int i = 0; i < n; i++) {
            // If adding Item won't overflow, add it completely
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                res += arr[i].value;
            }
            // If we can't add current Item, add fractional part of it
            else {
                double remain = W - curWeight;
                res += arr[i].value * (remain / arr[i].weight);
                break;
            }
        }

        // Returning final value
        return res;
    }
};
