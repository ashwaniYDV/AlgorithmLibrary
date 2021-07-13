// Method 1: With extra space
struct MinStack {
    // normal stack
    stack<int> s;
    // supporting stack
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
