// https://leetcode.com/problems/2-keys-keyboard/
// https://leetcode.com/problems/2-keys-keyboard/solutions/105908/very-simple-java-solution-with-detail-explanation/

/*
There is only one character 'A' on the screen of a notepad. 
You can perform one of two operations on this notepad for each step:
a) Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
b) Paste: You can paste the characters which are copied last time.
Given an integer n, return min no of operations to get character 'A' exactly n times on the screen.

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Input: n = 1
Output: 0
 
Constraints:
1 <= n <= 1000
*/



// Naive DP solution
class Solution {
public:
    int INF = 1e9;
    int n;

    int f(int i, int len) {
        if(i > n) return INF;
        if(i == n) return 0;

        int pasteOnly = 1 + f(i + len, len);
        int copyAndPaste = 2 + f(i + i, i);

        return min(copyAndPaste, pasteOnly);
    }

    int minSteps(int n) {
        this->n = n;
        if(n == 1) return 0;
        
        return 1 + f(1, 1);
    }
};




/*
Eg: n=6
To get 6, we need to copy 3 'A's two time. (2)
To get 3 'A's, copy the 1 'A' three times. (3)
So the answer for 6 is 2+3=5

Now, take n=9.
We need the lowest number just before 9 such that (9% number = 0). So the lowest number is 3.
So 9%3=0. We need to copy 3 'A's three times to get 9. (3)
For getting 3 'A's, we need to copy 1 'A' three times. (3)
So the answer is 6

Finally to analyse the below code, take n=81.
To get 81 we check
if (81 % 2 ==0) No
if (81 % 3 ==0) Yes
So we need to copy 81/3 = 27 'A's three times (3)
Now to get 27 'A's, we need to copy 27/3= 9 'A's three times (3)
To get 9 'A's, we need to copy 9/3=3 'A's three times (3)
And to get 3 'A's, we need to copy 3/3=1 'A's three times (3)
Final answer is 3+3+3+3 = 12

Last Example, n=18
18/2 = 9 Copy 9 'A's 2 times (2)
9/3=3 Copy 3 'A's 3 times (3)
3/3=1 Copy 1'A's 3 times (3)
Answer: 2+3+3= 8
*/


class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i <= n; i++) {
            while(n % i == 0) {
                res += i;
                n /= i;
            }
        }
        return res;
    }
};


class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i*i <= n; i++) {
            while(n % i == 0) {
                res += i;
                n /= i;
            }
        }
        return res + (n > 1 ? n : 0);
    }
};
