// https://www.geeksforgeeks.org/the-stock-span-problem/
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is less than or equal to its price on the given day.

For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
*/

/*
Solution:
Similar to NGL problem.
I just have to find the position of the nearest greater element on left side.
*/

class Solution {
public:
    vector < int > calculateSpan(int price[], int n) {
        stack < int > st;
        vector < int > res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = i + 1;
            } else {
                res[i] = (i - st.top());
            }
            st.push(i);
        }

        return res;
    }
};
