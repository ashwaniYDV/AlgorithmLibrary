// https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/
// https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/

// https://youtu.be/wLfGkk1x-lc?si=MhT8vke6OvYluBfE

/*
There is an m x n cake that needs to be cut into 1 x 1 pieces.
You are given integers m, n, and two arrays:
  horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
  verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.

In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:
  Cut along a horizontal line i at a cost of horizontalCut[i].
  Cut along a vertical line j at a cost of verticalCut[j].
After the cut, the piece of cake is divided into two distinct pieces.

The cost of a cut depends only on the initial cost of the line and does not change.

Return the minimum total cost to cut the entire cake into 1 x 1 pieces.
*/


/*
Diff bw question i and ii is constraints:
--------------------------------
Constraints:
1 <= m, n <= 20

Constraints:
1 <= m, n <= 10^5
*/


// Greedy solution 
/*
Intuition:
----------
* Make the most expensive cut as early as possible, which leads to a greedy solution.
* Order of horizontalCut and verticalCut doesn't matter, so we can sort them.
*/

class Solution {
public:
    long long minimumCost(int n, int m, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // sort in descending order
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        /*
        initially, no of vertical and horizontal sections is 1 
        which will increase in successive cuttings
        */
        int noOfHorSections = 1, noOfVerSections = 1;
        long long res = 0;

        int i = 0, j = 0;
        n--, m--;
        
        while(i < n && j < m) {
            // greedily take the max cut first which will contribute less in answer since noOfHorSections or noOfVerSections will be lesser
            if(horizontalCut[i] > verticalCut[j]) {
                res += horizontalCut[i] * noOfVerSections;
                noOfHorSections++;
                i++;
            } else {
                res += verticalCut[j] * noOfHorSections;
                noOfVerSections++;
                j++;
            }
        }

        while(i < n) {
            res += horizontalCut[i] * noOfVerSections;
            noOfHorSections++;
            i++;
        }

        while(j < m) {
            res += verticalCut[j] * noOfHorSections;
            noOfVerSections++;
            j++;
        }

        return res;
    }
};




// DP solution (Time = O(n ^ 4))
class Solution {
public:
    int m, n;
    int dp[21][21][21][21];

    int f(int xs, int xe, int ys, int ye, vector<int>& horCut, vector<int>& verCut) {
        // its a 1 * 1 piece
        if(xs == xe && ys == ye) return 0;

        if(dp[xs][xe][ys][ye] != -1) return dp[xs][xe][ys][ye];

        int res = INT_MAX;
        for(int x = xs; x < xe; x++) {
            int cost = horCut[x - 1] + f(xs, x, ys, ye, horCut, verCut) + f(x+1, xe, ys, ye, horCut, verCut);

            res = min(res, cost);
        }

        for(int y = ys; y < ye; y++) {
            int cost = verCut[y - 1] + f(xs, xe, ys, y, horCut, verCut) + f(xs, xe, y+1, ye, horCut, verCut);

            res = min(res, cost);
        }

        return dp[xs][xe][ys][ye] = res;
    }

    int minimumCost(int n, int m, vector<int>& horCut, vector<int>& verCut) {
        this->n = n, this->m = m;
        memset(dp, -1, sizeof(dp));

        return f(1, n, 1, m, horCut, verCut);
    }
};
