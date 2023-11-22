// https://leetcode.com/problems/spiral-matrix/
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// https://youtu.be/1ZGJzvkcLsA

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        // top
        int T = 0;
        // botton
        int B = A.size() - 1;
        // left
        int L = 0;
        // right
        int R = A[0].size() - 1;

        vector < int > ans;

        while (T <= B && L <= R) {
            if (T <= B && L <= R) {
                for (int i = L; i <= R; i++)
                    ans.push_back(A[T][i]);
                T++;
            }
            if (T <= B && L <= R) {
                for (int i = T; i <= B; i++)
                    ans.push_back(A[i][R]);
                R--;
            }
            if (T <= B && L <= R) {
                for (int i = R; i >= L; i--)
                    ans.push_back(A[B][i]);
                B--;
            } 
            if (T <= B && L <= R) {
                for (int i = B; i >= T; i--)
                    ans.push_back(A[i][L]);
                L++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        // top
        int T = 0;
        // botton
        int B = A.size() - 1;
        // left
        int L = 0;
        // right
        int R = A[0].size() - 1;
        // direction
        int dir = 0;

        int i;
        vector < int > ans;

        while (T <= B && L <= R) {
            if (dir == 0) {
                for (i = L; i <= R; i++)
                    ans.push_back(A[T][i]);
                T++;
            } else if (dir == 1) {
                for (i = T; i <= B; i++)
                    ans.push_back(A[i][R]);
                R--;
            } else if (dir == 2) {
                for (i = R; i >= L; i--)
                    ans.push_back(A[B][i]);
                B--;
            } else if (dir == 3) {
                for (i = B; i >= T; i--)
                    ans.push_back(A[i][L]);
                L++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
