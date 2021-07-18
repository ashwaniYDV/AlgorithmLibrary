// https://leetcode.com/problems/implement-stack-using-queues/
// https://www.geeksforgeeks.org/implement-stack-using-queue/


// Method 1: Making push operation costly
class MyStack {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
};







// Method 2: Making pop operation costly
class MyStack {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        int x = q.front();
        q.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
};
