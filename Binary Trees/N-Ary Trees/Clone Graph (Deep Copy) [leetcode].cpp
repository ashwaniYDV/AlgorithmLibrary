// https://leetcode.com/problems/clone-graph/

/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> vis;
    
    Node* dfs(Node* node) {
        if(node == NULL) return node;
        
        if(vis[node]) return vis[node];
        
        Node* cloned = new Node(node->val);
        vis[node] = cloned;
        
        for(auto newnode: node->neighbors){
            cloned->neighbors.push_back(dfs(newnode));
        }
        
        return cloned;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
