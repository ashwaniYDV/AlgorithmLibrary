// https://leetcode.com/problems/reconstruct-itinerary/
// https://youtu.be/WYqsg5dziaQ?si=0nGZeavWS67-52K7

/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.
All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*/



/*
Some observations:
------------------
a) Tickets are only one way (directed)
b) Return route with smallest lexicographical order
c) All tickets must form a valid eulerian tour, thus graph should be one connected component
d) One must use all tickets exactly once, thus we can travel an edge exactly once
e) We can travek a node multiple times

Note:
----
* We may not always get a valid eulerian circuit/tour by just following the lexicographical order traversal.
* Since the node encountered during lexicographical order can be a dead end.

Eg: [[J, K], [J, N], [N, J]]
So, adj list = 
    J -> [K, N]
    K -> []
    N -> [J]
If we travel: J -> K -> then we cannot go further.
so we should follow this: J -> N -> J -> K

So to handle these cases, we can either use stack (in iterative soln) 
or
we can add the node u to res after processing all child node v (in recursive soln).
*/


// Recursive version
class Solution {
public:
    void dfs(string u, unordered_map<string, multiset<string>>& g, vector<string>& res) {
        while(!g[u].empty()) {
            string v = *g[u].begin();
            // marking this edge as visited by removing it
            g[u].erase(g[u].begin());
            dfs(v, g, res);
        }

        res.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> g;

        for(auto& it: tickets) {
            g[it[0]].insert(it[1]);
        }

        vector<string> res;
        dfs("JFK", g, res);

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
        st.push("JFK");
        
        while(!st.empty()) {
            string src = st.top();
            // No further travel possible, so add it to res
            if(g[src].empty()) {
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
