// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

/*
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. 
A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
Return a list of all the recipes that you can create. You may return the answer in any order.
Note that two recipes may contain each other in their ingredients.


Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
*/

// Method 1: Topo sort
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supp(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> indegree;

        for(int i = 0; i < recipes.size(); i++) {
            string v = recipes[i];
            for(string u: ingredients[i]) {
                if(supp.count(u)) continue; // we are not considering supplies in our graph
              
                g[u].push_back(v);
                indegree[v]++;
            }
        }

        queue<string> q;
        for(string s: recipes) {
            if(indegree[s] == 0) {
                q.push(s);
            }
        }

        // kahn's topo sort
        vector<string> res;
        while(!q.empty()) {
            string u = q.front();
            q.pop();

            res.push_back(u);

            for(string v: g[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return res;
    }
};






// Methid 2: DFS
class Solution {
    unordered_map<string, vector<string>> g;
    unordered_map<string, bool> dpReady;
    unordered_set<string> isProcessing; // vis set

    bool dfs(string &recipe){
        // this is a cylic dependency
        if(isProcessing.count(recipe)){
            return false;
        }

        // this is cache for quick answers to already done computations
        if(dpReady.count(recipe)) { 
            return dpReady[recipe];
        }

        // if ur here means its checking a leaf/supply which is not present in supplies
        if (!g.count(recipe)) {
            return false;
        }
        
        bool isPossibleToMake = true;
        
        isProcessing.insert(recipe);
        for (auto &ingredient: g[recipe]) {
            if (dfs(ingredient) == false) {
                isPossibleToMake = false;
                break;
            }
        }
        isProcessing.erase(recipe);
        
        return dpReady[recipe] = isPossibleToMake;

    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        g.clear(), dpReady.clear();

        for (auto &supply: supplies) {
            dpReady[supply] = true;
        }

        for (int i = 0; i < recipes.size(); i++) {
            g[recipes[i]] = ingredients[i];
        }

        vector<string> ans;
        for (auto &recipe : recipes) {
            if (dfs(recipe)) {
                ans.push_back(recipe);
            }
        }
        return ans;
    }
};
