// https://www.scaler.com/problems/gym-trainer/

/*
You are the trainer of a gym and there are A people who come to your gym.
Some of them are friends because they walk together, and some of them are friends because they talk together.
But people become possessive about each other, so a person cannot walk with one friend and talk with another. 
Although he can walk with two or more people or talk with two or more people.
You being the trainer, decided to suggest each one of the 2 possible diets. 
But friends, being friends will always have the same diet as all the other friends are having.
Find and return the number of ways you can suggest each of them a diet.
As the number of ways can be huge, return the answer modulo 109+7.
NOTE: If there is any person who walks with one person and talks with the another person, then you may return 0.
*/

/*
Our task is to find the number of groups of friends formed. 
Since all persons in a groups will have same diet. 
There is only 2 possibility for each group.
So the number of ways will be 2^(Number of groups of friends).
We can efficiently find the number of groups by using disjoint set and union.
Iterate over the walk friends and talk friends one by one.
If the friends are not in same component, do union.
After this count the number of component that will be our number of groups of friend.
Return power(2,cnt).
*/

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n+1, -1);
    }
    int findParent(int a) {
        if(par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size (int x) { 
        return -par[findParent(x)]; 
    }
};

int MOD = 1e9+7;

int Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {
    DSU dsu(A);
    set<int> st;
    for (int i = 0; i < B.size(); i++) {
        int u = B[i][0], v = B[i][1];
        st.insert(u);
        st.insert(v);
        dsu.unionSet(u, v);
    }

    for (int i = 0; i < C.size(); i++) {
        int u = C[i][0], v = C[i][1];
        if (st.find(u) != st.end()) {
            return 0;
        }
        if (st.find(v) != st.end()) {
            return 0;
        }
        dsu.unionSet(u, v);
    }

    int cnt = 0;
    for (int i = 1; i <= A; i++) {
        cnt += (dsu.findParent(i) == i);
    }
    
    int res = 1;
    for (int i = 0; i < cnt; i++) {
        res = (res * 2) % MOD;
    }
    return res;
}
