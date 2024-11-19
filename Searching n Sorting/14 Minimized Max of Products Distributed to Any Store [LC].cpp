// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

/*
You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, 
where quantities[i] represents the number of products of the ith product type.
You need to distribute all products to the retail stores following these rules:
a) A store can only be given at most one product type but can be given any amount of it.
b) After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.


Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

Input: n = 7, quantities = [15,10,10]
Output: 5
Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

Constraints:
m == quantities.length
1 <= m <= n <= 10^5
1 <= quantities[i] <= 10^5
*/

class Solution {
public:
    #define ll long long
    
    bool check(ll mid, int n, vector<int>& quantities) {
        ll cnt = 0;
        for(int q: quantities) {
            cnt += ((q + mid - 1) / mid);
            if(cnt > n) return 0;
        }
        return 1;
    }

    // FFFFTTTT
    int minimizedMaximum(int n, vector<int>& quantities) {
        ll total = accumulate(quantities.begin(), quantities.end(), 0LL);
        if(total <= n) return 1;
        ll l = 0, h = total;

        while(l <= h) {
            ll mid = l + (h - l) / 2;
            if(check(mid, n, quantities)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};