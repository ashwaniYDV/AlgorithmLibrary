// https://www.scaler.com/test/2e8ead8609/?signature=BAhpAx3hCw%3D%3D--5ed15454665d66c73f5e5bc250274ca2b6918459#/problem_8

/*
Problem Description 
Given two integer arrays A and B of size N each, that represent 2 rows of N tiles each. 
Assuming 0 based indexing, you can start from the first tile of either row A or B (i.e you can start from A[0] or B[0]) 
and your goal is to reach the last tile of either row (i.e the terminating position must be A[N-1] or B[N-1]). 
You are supposed to reach the end of either row A or B through a series of jumps. 
You can jump from one tile to another tiLe, that is atmost C distance away from your current tile, in either row. 
If you are at tile i of either of the 2 rows, in 1 move you can jump to any of the tiles from index i+1 to i+C (both inclusive) of any row. 
Let's call this index j. Every tile has a cost associated with it, which is added to your total cost if you choose to use that tiLe. 
Depending on the row you choose to start with, cost of tile A[0] or B[0] is initially added, and 
then depending on the jumps made, the cost of each chosen tile is added. 
There is one small problem though, if you jump from a tile in row A to a tile in row B, or vice-versa, 
an additional cost of D is incurred for changing rows (i.e if you jump from A[i] to any element from B[1+1] to B[i+C] 
or from B[i] to any element from A[1+1] to A[i-tC]). 
If you make the jump in the same array, no extra cost will be incurred (i.e jumping from A[i] to any element from AP+1] to AD+C] 
or from B[i] to any element iTOT 13[1.1] to B[i+C]). 
Find the minimum cost needed to reach from the starting tiles to the ending tiles. NOTE: As the answer can be very Large, return your answer MOD 1n-7. 
Problem Constraints 1 v N v 106 0 <= A[i] <-= 105 o <= <-= 106 1 v C 106 0<-=-D<=106 

*/

int Solution::solve(vector<int> &a, vector<int> &b, int c, int d) {
    int n = a.size();
    int mod = 1000000007;
    vector<long long> dp1(n), dp2(n);
    multiset<long long> st1, st2;

    dp1[0] = a[0];
    dp2[0] = b[0];
    st1.insert(dp1[0]);
    st2.insert(dp2[0]);

    for(int i = 1; i < n; i++) {
    	dp1[i] = a[i] + min(*st1.begin(), *st2.begin() + d);
    	dp2[i] = b[i] + min(*st2.begin(), *st1.begin() + d);

    	if(i >= c) {
    		auto it = st1.find(dp1[i - c]);
    		st1.erase(it);
    		it = st2.find(dp2[i - c]);
    		st2.erase(it);
    	}

    	st1.insert(dp1[i]);
    	st2.insert(dp2[i]);
    }

    return min(dp1[n-1], dp2[n-1]) % mod;
}
