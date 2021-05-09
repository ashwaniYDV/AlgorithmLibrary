// https://leetcode.com/problems/ugly-number-ii/

/*
We have an array a of first n ugly number. We only know, at the beginning, the first one, which is 1. 
a[0] = 1
Then,
a[1] = min( a[0]*2, a[0]*3, a[0]*5). The answer is a[0]*2. So we move 2's pointer to 1. 
Then we test:
a[2] = min( a[1]*2, a[0]*3, a[0]*5). And so on. 

Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n);
        a[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        
        for(int i = 1; i < n ; i++) {
            a[i] = min({a[t2]*2, a[t3]*3, a[t5]*5});
            if(a[i] == a[t2]*2) t2++; 
            if(a[i] == a[t3]*3) t3++;
            if(a[i] == a[t5]*5) t5++;
        }
        return a[n-1];
    }
};
