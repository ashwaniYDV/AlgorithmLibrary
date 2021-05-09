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

/*
Let me try to explain this using an example. 
Let's say we have the first 3 ugly numbers 1, 2, 3. What would be the next number? 
Given the definition, the next number has to be the the smallest number among 2*(1,2,3), 3*(1,2,3), 5*(1,2,3). 
Obviously, the smallest number is 2 * 1 = 2. But wait, 2 is already in there. 
So precisely speaking, the next number has to be the the smallest number among all the existing numbers multiplied by 2, 3,5 that isn't in the list already. 
Now, we can traverse all numbers and maintain a hashset if we want, but it would become O(N^2). 
Good news is that we can solve this in a DP-like approach. First, we assume there is only one number in the list, which is 1. 
The next number is Min(2 * 1, 3 * 1, 5 * 1) = 2 and it is not in the list. 
Because we have already considered 2*1 (we move the pointer to its next position, which is 2), 
now we only need to consider 2 * 2, 3 * 1, 5 * 1 in the next iteration. This way, we don't have to worry about finding a number that is already in the list.

Edge case:
a[i] = min({a[t2]*2, a[t3]*3, a[t5]*5});
Conside the case when a[t2]*2 == a[t3]*3
in this case we update both t1 and t2 as
    if(a[i] == a[t2]*2) t2++; 
    if(a[i] == a[t3]*3) t3++;
i.e both if() will be called here

same goes for any combination of t2, t3, t5
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
