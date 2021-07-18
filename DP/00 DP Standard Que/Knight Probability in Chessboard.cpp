// https://leetcode.com/problems/knight-probability-in-chessboard/
// https://youtu.be/54nJhM2AZv4

/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. 
The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
The knight continues moving until it has made exactly k moves or has moved off the chessboard.
Return the probability that the knight remains on the board after it has stopped moving.
*/

class Solution {
public:
    int n;
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = { -1, 1, 1, -1, 2, -2, 2, -2};

    bool isSafe(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }

    double knightProbability(int n, int k, int row, int col) {
        this->n = n;
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        dp[row][col][0] = 1;
        for (int cnt = 1; cnt <= k; cnt++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j][cnt - 1]) {
                        for (int z = 0; z < 8; z++) {
                            int ni = i + dx[z], nj = j + dy[z];
                            if (isSafe(ni, nj)) {
                                dp[ni][nj][cnt] += (dp[i][j][cnt - 1]  / 8.0);
                            }
                        }
                    }
                }
            }
        }

        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[i][j][k];
            }
        }
        return res;
    }
};










class Solution {
public:
    int n;
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = { -1, 1, 1, -1, 2, -2, 2, -2};

    bool isSafe(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        return true;
    }

    double knightProbability(int n, int k, int row, int col) {
        this->n = n;
        vector<vector<double>> dp(n, vector<double>(n, 0));
        vector<vector<double>> temp(n, vector<double>(n, 0));
        dp[row][col] = 1;

        for (int cnt = 1; cnt <= k; cnt++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] > 0) {
                        for (int z = 0; z < 8; z++) {
                            int ni = i + dx[z], nj = j + dy[z];
                            if (isSafe(ni, nj)) {
                                temp[ni][nj] += (dp[i][j] / 8.0);
                            }
                        }
                    }
                }
            }
            dp = temp;
            temp = vector<vector<double>>(n, vector<double>(n, 0));
        }

        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += dp[i][j];
            }
        }
        return res;
    }
};
