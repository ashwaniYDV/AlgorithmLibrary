/*
Given a positive integer N. Return an array of minimum length whose elements represent the powers of 3 and the sum of all the elements is equal to N.

Input: 13
Output: [1, 3, 9]

Input: 3
Output: [3]

Problem Constraints
1 <= N <= 10^9
*/

/*
Hint 1
-------
Think of what would have you done if you are asked to find the powers of 2.
Think what does minimum number of powers of 3 means.
Can you do anything with the number written in base-3 format.

Concept
--------
We convert the given number in base-3 and store it in a vector which gives the minimum powers of 3 required to sum to get the number.
Now any digit will be either 0, 1 or 2.

Suppose N=10, in base-3 it can be written as 101.
It means 10 = 1*(3^2) + 0*(3^1) + 1*(3^0).

Suppose N=16, in base-3 it can be written as 121.
It means 10 = 1*(3^2) + 2*(3^1) + 1*(3^0).
*/

vector<int> Solution::solve(int N) {
    vector<int> bits, res;

    while (N) {
        bits.push_back(N % 3);
        N /= 3;
    }

    for (int i = 0; i < bits.size(); ++i) {
        for (int j = 0; j < bits[i]; j++) {
            res.push_back(pow(3, i));
        }
    }
    return res;
}
