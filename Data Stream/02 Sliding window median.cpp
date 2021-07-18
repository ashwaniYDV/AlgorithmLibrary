// https://leetcode.com/problems/sliding-window-median/

// Method 1
/*
I will always keep left.size() either equal or greater than right.size() 
*/
class Solution {
public:
    using ld = long double;
    multiset<int, greater<int>> left;
    multiset<int> right;
    vector<double> res;
    
    void addEle(int x) {
        if(left.size() == right.size()) {
            right.insert(x);
            left.insert(*right.begin());
            right.erase(right.begin());
        } 
        // left.size() > right.size()
        else {
            left.insert(x);
            right.insert(*left.begin());
            left.erase(left.begin());
        }
    }

    void removeEle(int x) {
        if(left.find(x) != left.end()) {
            left.erase(left.find(x));
        } else {
            right.erase(right.find(x));
        }
        
        // check if left.size() has become less than right.size()
        if(left.size() < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    void setAnswer() {
        if(left.size() == right.size()) {
            ld median = ((ld)(*left.begin()) + (ld)(*right.begin())) / 2.0;
            res.push_back(median);
        } else if(left.size() < right.size()) {
            res.push_back(*right.begin());
        } else {
            res.push_back(*left.begin());
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        res.clear();
        left.clear(), right.clear();
        
        for(int i = 0; i < k; i++) {
            addEle(nums[i]);
        }
        setAnswer();
        
        for(int i = k; i < nums.size(); i++) {
            removeEle(nums[i - k]);            
            addEle(nums[i]);
            setAnswer();
        }
        
        return res;
    }
};



// Method 2
class Solution {
public:
    using ld = long double;
    multiset<int, greater<int>> left;
    multiset<int> right;
    vector<double> res;
    
    void addEle(int x) {
        if(left.empty() || (*left.begin()) > x) {
            left.insert(x);
        } else {
            right.insert(x);
        }
        reshuffle();
    }

    void removeEle(int x) {
        if(left.find(x) != left.end()) {
            left.erase(left.find(x));
        } else {
            right.erase(right.find(x));
        }
        reshuffle();
    }
    
    void reshuffle() {
        if(left.size() > right.size() + 1) {
            right.insert(*left.begin());
            left.erase(left.begin());
        }
        if(right.size() > left.size() + 1) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    void setAnswer() {
        if(left.size() == right.size()) {
            ld median = ((ld)(*left.begin()) + (ld)(*right.begin())) / 2.0;
            res.push_back(median);
        } else if(left.size() < right.size()) {
            res.push_back(*right.begin());
        } else {
            res.push_back(*left.begin());
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        res.clear();
        left.clear(), right.clear();
        
        for(int i = 0; i < k; i++) {
            addEle(nums[i]);
        }
        setAnswer();
        
        for(int i = k; i < nums.size(); i++) {
            removeEle(nums[i - k]);            
            addEle(nums[i]);
            setAnswer();
        }
        
        return res;
    }
};