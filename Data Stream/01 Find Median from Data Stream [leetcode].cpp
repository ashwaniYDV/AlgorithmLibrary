// https://leetcode.com/problems/find-median-from-data-stream/

/*
Intuition
---------
I keep two heaps:
Max-heap: Left has the smaller half of the numbers.
Min-heap: Right has the larger half of the numbers.
*/


// Method 1
/*
I will always keep left.size() either equal or greater than right.size() 
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else if(left.size() < right.size()) {
            return right.top();
        } else {
            return left.top();
        }
    }
};





// Method 2
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty() || (left.top()) > num) {
            left.push(num);
        } else {
            right.push(num);
        }
        reshuffle();
    }
    
    void reshuffle() {
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        // do not use else if
        if(right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else if(left.size() < right.size()) {
            return right.top();
        } else {
            return left.top();
        }
    }
};