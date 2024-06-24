// https://www.geeksforgeeks.org/minimum-step-reach-one/

/*
Given a positive number N, we need to reach to 1 in minimum number of steps where a step is defined as 
converting N to (N-1) or converting N to its one of the bigger divisor. 
Formally, if we are at N, then in 1 step we can reach to (N – 1) or if N = u*v then we can reach to max(u, v) where u > 1 and v > 1. 
*/

void solve() {
    cin >> n;
    queue<pair<int, int>> q;
    q.push({n, 0});
 
    // map is used to visit numbers so that they won't be pushed in queue again
    map<int, int> vis;
 
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int val = it.first, steps = it.second;
         
        // if current value is 1, return its steps from n
        if (val == 1) {
            cout << steps << endl;
            return;
        }
 
        //  check val - 1, only if it not visited yet
        if (!vis[val - 1]) {
            q.push({val - 1, steps + 1});
            vis[val - 1] = 1;
        }

        //  loop from 2 to sqrt(value) for its divisors
        for (int i = 2; i * i <= val; i++) {
            // check divisor, only if it is not visited yet 
            // if i is divisor of val, then val / i will be its bigger divisor
            if (val % i == 0 && !vis[val / i]) {
                q.push({val / i, steps + 1});
                vis[val / i] = 1;
            }
        }
    }
}
