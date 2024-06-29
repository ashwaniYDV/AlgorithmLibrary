// https://leetcode.com/problems/reconstruct-itinerary/

/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.
All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*/



/*
Just Eulerian path. Greedy DFS, building the route backwards when retreating.
*/


// Recursive version
class Solution {    
public:
    vector<string> res;
    unordered_map<string, multiset<string>> g;
    
    void dfs(string u) {
        while (g[u].size()) {
            string v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v);
        }
        res.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        g.clear();
        
        // Make graph
        for(auto it: tickets) {
           g[it[0]].insert(it[1]);
        }
        
        dfs("JFK");
        
        reverse(res.begin(), res.end());
        return res;
    }
};









// Iterative version
class Solution {    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> g;
        vector<string> res;
        
        // Make graph
        for(auto it: tickets) {
           g[it[0]].insert(it[1]);
        }
        
        stack<string> st;
        // JFK is our fixed starting point
        st.push("JFK");
        
        while(!st.empty()) {
            string src = st.top();
            // No further travel possible 
            if(g[src].size() == 0) {
                res.push_back(src);
                st.pop();
            } else {
                auto dst = g[src].begin();
                st.push(*dst);
                g[src].erase(dst);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
