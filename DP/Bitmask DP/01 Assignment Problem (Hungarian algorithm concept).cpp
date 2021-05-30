// Assignment Problem (classic problem taugh in colleges)
// https://youtu.be/685x-rzOIlY

// Hungarian_algorithm
// https://en.wikipedia.org/wiki/Hungarian_algorithm

/*
Problem Statement:
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. 
It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way 
that the total cost of the assignment is minimized.

Input Format:
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input:
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

Sample Output:
13

Constraints:
N <= 20
*/



// Method 1: (Less memory efficient)

const int N = 20;
int n, m;

int dp[20][1 << 20];
vector<vector<int>> cost;

int go(int job, int mask) {
    if(job == n) return 0;

    if (dp[job][mask] != -1) { 
        return dp[job][mask];
    }

    int ans = INF;
    for (int person = 0; person < n; ++person) {
        if (!(mask & (1 << person))) {
            ans = min(ans, cost[person][job] + go(job+1, mask | (1 << person)));
        }
    }

    return dp[job][mask] = ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    f(i, n) {
        f(j, n) {
            cin >> cost[i][j];
        }
    }   
    cout << go(0, 0);
}



















// Method 2: (More memory efficient)

const int N = 20;
int n, m;

int dp[1 << 20];
vector<vector<int>> cost;

int go(int mask) {
    int job = __builtin_popcount(mask);

    if(job == n) return 0;

    if (dp[mask] != -1) { 
        return dp[mask];
    }

    int ans = INF;
    for (int person = 0; person < n; ++person) {
        if (!(mask & (1 << person))) {
            ans = min(ans, cost[person][job] + go(mask | (1 << person)));
        }
    }
    return dp[mask] = ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    f(i, n) {
        f(j, n) {
            cin >> cost[i][j];
        }
    }   
    cout << go(0);
}
