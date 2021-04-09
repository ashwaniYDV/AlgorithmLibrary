// Using Travelling Salesman Problem concept

#include<bits/stdc++.h>
using namespace std;

// no of vertices of fully connected graph
int N = 4;

// all cities have been visited (1111)
int VISITED_ALL = (1 << N) - 1;

void hamiltonianPathUsingTSP(int mask, int curCity, vector<int> res) {
    // base case
    if (mask == VISITED_ALL) {
        for(int i: res) {
            cout << i << " ";
        }
        cout << 0 << endl;
        return;
    }

    // try to go to unvisited cities
    for(int city = 0; city < N; city++) {
        if((mask & (1 << city)) == 0) {
            res.push_back(city);
            hamiltonianPathUsingTSP(mask | (1 << city), city, res);
            res.pop_back();
        }
    }
}

int main() {
    vector<int> res;
    res.push_back(0);
    hamiltonianPathUsingTSP(1, 0, res);
    return 0;
}
