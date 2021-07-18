// https://leetcode.com/problems/min-stack/
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

// Method 1: With extra space
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
















// With O(1) space
struct MinStack {
    // normal stack
    stack<int> s;
    int minElement;

    void push(int a) {
        if(s.empty()) {
            s.push(a);
            minElement = a;
        } else {
            if(a >= minElement) {
                s.push(a);
            } else {
                s.push(2*a - minElement);
                minElement = a;
            }
        }
    }

    int pop() {
        if(s.empty()) return -1;
        
        if(s.top() < minElement) {
            minElement = 2 * minElement - s.top();
        }
        s.pop();
    }

    int getMin() {
        if(s.empty()) return -1;
        return minElement;
    }

    int top() {
        if(s.empty()) return -1;
        
        if(s.top() < minElement) {
            return minElement;
        } else {
            return s.top();
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    bool isFull(int n) {
        return s.size() == n;
    }
};

void solve() {
    int x, y, z;
    MinStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
}
