// https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

/*
Design a stack that supports increment operations on its elements.
Implement the CustomStack class:
    CustomStack(int maxSize) 
        Initializes the object with maxSize which is the maximum number of elements in the stack.
    void push(int x)
        Adds x to the top of the stack if the stack has not reached the maxSize.
    int pop()
        Pops and returns the top of the stack or -1 if the stack is empty.
    void inc(int k, int val) 
        Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.


Constraints:
1 <= maxSize, x, k <= 1000
0 <= val <= 100
At most 1000 calls will be made to each method of increment, push and pop each separately.
*/


// O(k): Eager increment
class CustomStack {
    vector<int> stack;
    int n;
public:
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(stack.size() == n) return;
        stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty()) return -1;
        int res = stack.back();
        stack.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int)stack.size()); i++) stack[i] += val;
    }
};


// O(1): Lazy increment
/*
Use an additional array to record the increment value.
inc[i] means for all elements stack[0] ~ stack[i],
we should plus inc[i] when popped from the stack.

Then inc[i-1] += inc[i],
so that we can accumulate the increment inc[i] for the bottom elements and the following pops.
*/
class CustomStack {
    vector<int> stack, inc;
    int n;
public:
    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if (stack.size() == n) return;
        stack.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        if (stack.empty()) return -1;
        
        int i = stack.size() - 1;
        if (i - 1 >= 0) inc[i - 1] += inc[i];

        int res = stack[i] + inc[i];
        
        stack.pop_back();
        inc.pop_back();
        
        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)stack.size()) - 1;
        if (i >= 0) inc[i] += val;
    }
};
