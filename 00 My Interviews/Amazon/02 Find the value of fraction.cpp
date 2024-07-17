/*
If a text file has inputs like
a/b=3
d/c=6
.
.
.
.
.
n fractions 

Find whether solution for any (random variable)/(random variable) is possible or not and if possible the result for the fraction
Eg. x/y =?

------------------

Example: We need to find x/y, and text file has these fractions

x / a = 4
a / b = 7
b / c = 3
c / d = 9
d / y = 2

Then we can see that:
x / y = (x / a) * (a / b) * (b / c) * (c / d) * (d / y)

Also if, a / b = 2
then clearly 
b / a = 1 / 2
*/


class Solution {
    int getRandomFraction(char x, char y, unordered_map<pair<char, char>, int> fractions) {
        unordered_map<char, vector<pair<char, double>>> graph; // { node, child_nodes(child, weightOfEdge)
        unordered_map<char, int> visited;
    
        for(auto [edge, weight]: fractions) {
            char from = edge.first, to = edge.second;
            graph[from].push_back({to, weight});
            graph[to].push_back({from, 1.0 / weight});
        }
        
        queue<pair<char, double>> q; // node, ansSoFar
        q.push({x, 1.0});
        visited[x]++;
        
        while(!q.empty()) {
            auto [from, ansSoFar] = q.front(); // {b, 3}
            q.pop();
            
            // return from here if found answer
            if(from == y) {
                return ansSoFar;
            }
            
            for(auto [to, weight]: graph[from]) {
                if(visited[to] != 0) {
                    visited[to]++;
                    q.push({to, ansSoFar * weight}); 
                }
            }
        }
        
        return -1;
    }
};
