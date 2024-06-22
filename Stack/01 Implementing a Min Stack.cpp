// https://leetcode.com/problems/min-stack/
// https://youtu.be/V09NfaGf2ao?si=arNP4k92XMZ6Rn8u
// https://youtu.be/Trz7JM610Uc

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

// Method 1.1: Not space optimized
class MinStack {
    stack<int> st;
    stack<int> minSt; // it is a monotonic stack
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top() >= val) {
            minSt.push(val);
        }
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if(minSt.top() == val) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};



// Method 1.2: Not space optimized
class MinStack {
    stack<pair<int, int>> st; // {val, min}
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};







// Method 2: Space optimized
class MinStack {
    stack<long long> st;
    long long minEle;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minEle = val;
        } else {
            if(val < minEle) {
                st.push(2LL * val - minEle);
                minEle = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() < minEle) {
            minEle = 2 * minEle - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < minEle) {
            return minEle;
        }
        return st.top();
    }
    
    int getMin() {
        return minEle;
    }
};
