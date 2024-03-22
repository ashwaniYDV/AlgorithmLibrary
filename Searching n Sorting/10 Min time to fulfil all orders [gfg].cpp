// https://practice.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1

/*
Geek is organizing a party at his house. For the party, he needs exactly N donuts for the guests. 
Geek decides to order the donuts from a nearby restaurant, which has L chefs and each chef has a rank R. 
A chef with rank R can make 1 donut in the first R minutes, 1 more donut in the next 2R minutes, 1 more donut in 3R minutes, and so on.
For example. a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, 
and one more in the next 6 minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. 
A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.
Since, it's time for the party, Geek wants to know the minimum time required in completing N donuts. 
Return an integer denoting the minimum time
*/

// FFFFFFFTTTTTTTT

class Solution {
public:
    bool check(int mid, int N, vector < int > & a, int l) {
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            int p = 1, sum = 0;
            while (sum + p * a[i] <= mid) {
                cnt++;
                sum += (p * a[i]);
                p++;
            }
        }
        return cnt >= N;
    }

    int findMinTime(int N, vector < int > & a, int l) {
        int lo = 1;
        int hi = 1e9;

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (check(mid, N, a, l))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
