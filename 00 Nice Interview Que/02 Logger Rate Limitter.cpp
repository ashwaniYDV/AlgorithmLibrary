// https://leetcode.com/problems/logger-rate-limiter/

/*
Design a logger system that receives a stream of messages along with their timestamps. 
Each unique message should only be printed at most every 10 seconds 
(i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).
All messages will come in chronological order. 
Several messages may arrive at the same timestamp.

Implement the Logger class:
Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
*/


/*
https://leetcode.com/problems/logger-rate-limiter/solutions/391558/review-of-four-different-solutions-hashmap-two-sets-queue-with-set-radix-buckets-java-centric/

I really liked this problem because even though it is simple 
there are various solutions each with different trade-offs.
*/



// Method 1: using HashMap
/*
Time complexity: O(1)
Space complexity: O(n)

Disadvantage = memory usage never stops growing
*/
class Logger {
public:
    unordered_map<string, int> mp;
    
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(!mp.count(message) || timestamp >= mp[message]) {
            mp[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};





// Method 2: using HashSet + Queue
/*
Time complexity: O(1)
Space complexity: O(10)

Method2 is better than Method1
*/
class Logger {
public:
    unordered_set<string> st;
    queue<pair<string, int>> q;

    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        // remove all older messages from both unordered_map and itself
        while(!q.empty() && q.front().second <= timestamp - 10) {
            st.erase(q.front().first);
            q.pop();
        }

        if(!st.count(message)) {
            st.insert(message);
            q.push({message, timestamp});
            return true;
        }

        // msg is already there in the queue with time < (timestamp - 10)
        return false;
    }
};



// Method 3: Same as Design Hit Counter
class Logger {
public:
    static const int M = 10;
    int times[M];
    unordered_set<string> hits[M];

    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        int idx = timestamp % 10;
        if (times[idx] != timestamp) {
            hits[idx].clear();
            times[idx] = timestamp;
        }

        for (int i = 0; i < M; ++i) {
            if (timestamp - times[i] < 10) {
                if (hits[i].count(message)) {
                    return false;
                }
            }
        }

        hits[idx].insert(message);
        return true;
    }
};








/*
Concurency / Thread safety
==========================

https://leetcode.com/problems/logger-rate-limiter/discuss/83298/Thread-Safe-Solution

It's possible that the Logger is called with the same message at the same time from multiple sources. 
In that case the HashMap might not have been updated fast enough when the second duplicate message arrives.

For example:
1) New message m1 arrives at time 1
2) Same message m1 arrives again at time 1
3) Logger is called with (m1, 1)
4) Logger is called with (m1, 1)
5) The second call will possibly print the message if the first call (#3) hasn't had a chance to create the HashMap entry for m1 yet.
One possible solution is to use a lock
*/
public boolean shouldPrintMessage(int timestamp, String message) {
    Integer ts = msgMap.get(message);
    if (ts == null || timestamp - ts >= 10) {
        synchronized (lock) {
            Integer ts2 = msgMap.get(message);
            if (ts == null || timestamp - ts2 >= 10) {
                msgMap.put(message, timestamp);
                return true;
            }
        }
    } 
    return false;
}