// https://leetcode.com/problems/spiral-matrix/
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// https://youtu.be/1ZGJzvkcLsA

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        // top, bottom, left, right
        int T = 0;
        int B = A.size() - 1;
        int L = 0;
        int R = A[0].size() - 1;

        vector <int> ans;

        while (T <= B && L <= R) {
            // left to right
            if (T <= B && L <= R) {
                for (int i = L; i <= R; i++) {
                    ans.push_back(A[T][i]);
                }
                T++;
            }
            // top to bottom
            if (T <= B && L <= R) {
                for (int i = T; i <= B; i++) {
                    ans.push_back(A[i][R]);
                }
                R--;
            }
            // right to left
            if (T <= B && L <= R) {
                for (int i = R; i >= L; i--) {
                    ans.push_back(A[B][i]);
                }
                B--;
            } 
            // bottom to top
            if (T <= B && L <= R) {
                for (int i = B; i >= T; i--) {
                    ans.push_back(A[i][L]);
                }
                L++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        // top, bottom, left, right
        int T = 0;
        int B = A.size() - 1;
        int L = 0;
        int R = A[0].size() - 1;

        int dir = 0;

        vector <int> ans;

        while (T <= B && L <= R) {
            if (dir == 0) {
                for (int i = L; i <= R; i++) {
                    ans.push_back(A[T][i]);
                }
                T++;
            } else if (dir == 1) {
                for (int i = T; i <= B; i++) {
                    ans.push_back(A[i][R]);
                }
                R--;
            } else if (dir == 2) {
                for (int i = R; i >= L; i--) {
                    ans.push_back(A[B][i]);
                }
                B--;
            } else if (dir == 3) {
                for (int i = B; i >= T; i--) {
                    ans.push_back(A[i][L]);
                }
                L++;
            }

            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
