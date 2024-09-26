// https://leetcode.com/problems/implement-queue-using-stacks/
// https://youtu.be/3Et9MrMc02A
// https://takeuforward.org/data-structure/implement-queue-using-stack/

// Method 1: Push is costly
class MyQueue {
public:
    stack<int> st, helperSt;
    
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        // push all elements to helper stack
        while (!st.empty()) {
            helperSt.push(st.top());
            st.pop();
        }

        st.push(x);
        
        // get back all previous elements from helper stack
        while (!helperSt.empty()) {
            st.push(helperSt.top());
            helperSt.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        return st.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};





// Method 2: Pop and peek are costly
/*
I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. 
I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. 
When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.
*/
class MyQueue {
public:
    stack<int> input, output;
    
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // shift input to output
        if (output.empty()) {
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        // shift input to output
        if (output.empty()) {
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};
