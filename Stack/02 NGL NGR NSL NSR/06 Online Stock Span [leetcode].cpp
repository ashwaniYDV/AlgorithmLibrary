// https://leetcode.com/problems/online-stock-span/

/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days 
(starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], 
then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/

class StockSpanner {
public:
    // {i, price[i]}
    stack<pair<int, int>> st;
    vector<int> priceVec;
    int i;
    
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        while (!st.empty() && st.top().second <= price) {
            st.pop();
        }

        int res;
        if (st.empty()) {
            res = i + 1;
        } else {
            res = (i - st.top().first);
        }
        st.push({i, price});
        i++;
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
