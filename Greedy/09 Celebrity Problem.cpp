// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

/*
A celebrity is a person who is known to all but does not know anyone at a party. 
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party 
such that if an element of row i and column j  is set to 1 it means ith person knows jth person. 
Here M[i][i] will always be 0.
Note: 
    There will be exactly one celebrity if they are at the party.
    Follow 0 based indexing.

Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 

Example 2:
Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
*/


class Solution  {
public:
    int celebrity(vector<vector<int> >& M, int n) {
        int i = 0, j = n - 1;
        while (i < j) {
            // i knows j, thus i cannot be celebrity
            if (M[i][j] == 1)
                i++;
            // i does not know j, thus j cannot be celebrity
            else
                j--;
        }
        
        // i == j here
        // i points to our celebrity candidate
        int candidate = i;
 
        // Now, check that whether the candidate is actually a celebrity 
        // ie: he is known by everyone but he knows no one
        for (i = 0; i < n; i++) {
            if (i == candidate) continue;

            if (M[i][candidate] == 0 || M[candidate][i] == 1) return -1;
        }
        // if we reach here this means that the candidate is really a celebrity
        return candidate;
    }
};





// https://leetcode.com/problems/find-the-celebrity/
/*
Suppose you are at a party with n people labeled from 0 to n - 1 
and among them, there may exist one celebrity. 
The definition of a celebrity is that all the other n - 1 people know the celebrity, 
but the celebrity does not know any of them.
Now you want to find out who the celebrity is or verify that there is not one. 
You are only allowed to ask questions like: 
"Hi, A. Do you know B?" to get information about whether A knows B. 
You need to find out the celebrity by asking as few questions as possible 
(in the asymptotic sense).
You are given a helper function bool knows(a, b) that tells you whether a knows b. 
Implement a function int findCelebrity(n). 
There will be exactly one celebrity if they are at the party.
Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.
*/
/* 
The knows API is defined for you.
bool knows(int a, int b); 
*/

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0, j = n - 1;

        while (i < j) {
            if (knows(i, j))
                i++;
            else
                j--;
        }

        int celebrity = i;

        for (int j = 0; j < n; j++) {
            if (celebrity == j) continue;
            if (knows(celebrity, j) || !knows(j, celebrity)) return -1;
        }

        return celebrity;
    }
};
