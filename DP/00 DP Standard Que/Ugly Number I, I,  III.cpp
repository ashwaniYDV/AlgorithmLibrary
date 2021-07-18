// https://leetcode.com/problems/ugly-number/

/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number.
*/

class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        
        while(n % 2 == 0) 
            n /= 2;
        while(n % 3 == 0) 
            n /= 3;
        while(n % 5 == 0) 
            n /= 5;
        
        return n == 1;
    }
};





















// https://leetcode.com/problems/ugly-number-ii/

/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. 
Given a number n, the task is to find n’th Ugly number.
*/


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


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n+1);
        a[1] = 1;
        int t2 = 1, t3 = 1, t5 = 1; //pointers for 2, 3, 5
        
        for(int i = 2; i <= n ; i++) {
            a[i] = min({a[t2]*2, a[t3]*3, a[t5]*5});
            if(a[i] == a[t2]*2) t2++; 
            if(a[i] == a[t3]*3) t3++;
            if(a[i] == a[t5]*5) t5++;
        }
        return a[n];
    }
};




















// https://leetcode.com/problems/ugly-number-iii/
// https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template

/*
An ugly number is a positive integer that is divisible by a, b, or c.
Given four integers n, a, b, and c, return the nth ugly number.

Example 1:
Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Example 2:
Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
 

Constraints:
1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
It is guaranteed that the result will be in range [1, 2 * 109].
*/


/*
For every integer N, 
F(N) = (total number of positive integers <= N which are divisible by a or b or c.)
F(N) = a + b + c - a ∩ c - a ∩ b - b ∩ c + a ∩ b ∩ c
F(N) = N/a + N/b + N/c - N/lcm(a, b) - N/lcm(b, c) - N/lcm(c, a) + N/lcm(a, b, c)
*/

class Solution {
public:
    #define ll long long
    int nthUglyNumber(int n, int A, int B, int C) {
        ll a = (ll)(A);
        ll b = (ll)(B);
        ll c = (ll)(C);
        
        // ll lcm_ab = (a*b)/(__gcd(a, b));
        ll lcm_ab = (a / __gcd(a, b)) * b;
        ll lcm_bc = (b / __gcd(b, c)) * c;
        ll lcm_ac = (a / __gcd(a, c)) * c;
        // ll lcm_abc = (a * lcm_bc) / __gcd(a, lcm_bc));
        ll lcm_abc = (a / __gcd(a, lcm_bc)) * lcm_bc;
        
        int lo = 1, hi = 2 * (int) 1e9;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = mid/a + mid/b + mid/c - mid/lcm_ab - mid/lcm_bc - mid/lcm_ac + mid/lcm_abc;
            if(cnt < n) 
                lo = mid + 1;
            else
			   //the condition: F(N) >= n
                hi = mid;
        }
        return lo;
    }
};
