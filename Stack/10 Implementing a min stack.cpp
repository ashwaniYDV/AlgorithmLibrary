// https://practice.geeksforgeeks.org/problems/special-stack/1
// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

/*
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() 
and an additional operation getMin() which should return minimum element from the SpecialStack. 
Your task is to complete all the functions, using stack data-Structure.
*/

// With extra space
struct MinStack {
    // normal stack
    stack<int> s;
    // supporting stack (stores min element)
    stack<int> ss;

    void push(int a) {
        s.push(a);
        if(ss.empty() || ss.top() >= a) {
            ss.push(a);
        }
    }

    int pop() {
        if(s.empty()) return -1;
        int x = s.top();
        s.pop();
        if(ss.top() == x) ss.pop();
    }

    int getMin() {
        if(ss.empty()) return -1;
        return ss.top();
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
