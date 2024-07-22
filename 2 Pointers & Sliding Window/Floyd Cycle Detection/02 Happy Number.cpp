// https://leetcode.com/problems/happy-number/submissions/1239689429/
// https://youtu.be/wjYnzkAhcNk?si=11nB8vKcCN2j3Na4

/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Input: n = 2
Output: false
*/

// Method 1 (Not space optimized)
class Solution {
public:
    bool isHappy(int n) {
        set<int> st;

        while(n != 1) {
            // cyclicity
            if(st.count(n)) return false;
            st.insert(n);

            int x = 0;
            while(n) {
                int rem = n % 10;
                n /= 10;
                x += rem * rem;
            }
            n = x;
        }

        return true;
    }
};


// Method 2 (Space = O(1))
class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, rem;
        while (n) {
            rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        while(1) {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));

            if(slow == fast) break;
        }

        return slow == 1;
    }
};
