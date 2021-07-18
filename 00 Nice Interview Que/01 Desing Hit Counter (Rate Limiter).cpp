// https://leetcode.com/discuss/interview-question/178662/Design-a-Hit-Counter/
// https://www.geeksforgeeks.org/design-a-hit-counter/

/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

It should support the following two operations:
1) hit(timestamp) – Shows a hit at the given timestamp.
2) getHits(timestamp) – Returns the number of hits received in the past 5 minutes (300 seconds) (from currentTimestamp). 
Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (i.e. the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1. Examples:

“Design hit counter” problem has recently been asked by many companies including Dropbox and 
the question is harder than it seems to be. 
It includes a couple of topics like basic data structures design, various optimization, 
concurrency and distributed counter. 

=======================================================
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301);
=======================================================
*/




/*
Method 1: Simple Solution (Brute-force)
We can use a vector to store all the hits.
*/

vector<int> v;

// Record a hit.
// @param timestamp - The current timestamp (in seconds granularity).
void hit(int timestamp) {
	v.push_back(timestamp);
}

// Return the number of hits in the past 5 minutes.
// @param timestamp - The current timestamp (inseconds granularity). 
int getHits(int timestamp) {
	int i;
	for (i = 0; i < v.size(); ++i) {
        // {v[i] <= (timestamp - 300)} are ignored 
		if (v[i] > timestamp - 300) {
			break;
		}
	}
	return v.size() - i;
}






/*
Method 2: Space Optimized Solution 
We can use a queue to store the hits and delete the entries in queue which are of no use. 
*/

queue<int> q;

void hit(int timestamp) {
	q.push(timestamp);
}

int getHits(int timestamp) {
	while (!q.empty() && timestamp - q.front() >= 300) {
		q.pop();
	}
	return q.size();
}






/*
Method 3: Most optimized solution (data comes in unordered and several hits can carry same timestamp)

* What if the data comes in unordered and several hits carry the same timestamp (i.e. concurrent hits). 
* Since the queue approach wouldn’t work without ordered data, this time we go with arrays to store hit count in each unit of time. 
* If we are tracking hits in the past 5 mins in seconds granularity (300 seconds), create 2 arrays of size 300:
    int hits[300] 
    int times[300] 

Intuition
=========
* given that you are required to count the hits in the past 5 minutes(300 seconds)
* so we allocate array of size (300) 
* this array will hold only the last 300 seconds hits
* idx = (timestamp % 300) = location of the passed timestamp in the last 300 seconds
*/

vector<int> times, hits;
times.resize(300);
hits.resize(300);

void hit(int timestamp) {
	int idx = timestamp % 300;

	// concurrent hit came at the same timestamp
	if (times[idx] == timestamp) {
		hits[idx]++;
	}
    else if (times[idx] < timestamp) {
		// times[idx] contains old timestamp and shall be discarded since it is outside of current 300s window
		times[idx] = timestamp;
		hits[idx] = 1;
	} 
	else if (times[idx] > timestamp) {
		// ignore it: since query timestamp is older than times[idx]
	}
}

int getHits(int timestamp) {
	int res = 0;
	for (int i = 0; i < 300; ++i) {
		if (timestamp - times[i] < 300) {
			res += hits[i];
		}
	}
	return res;
}






/*
How to handle concurrent requests?
===================================
When two requests update the list simultaneously, there can be race conditions. 
It’s possible that the request that updated the list first may not be included eventually.
The most common solution is to use a lock to protect the list. 
Whenever someone wants to update the list (by either adding new elements or removing the tail), 
a lock will be placed on the container. 
After the operation finishes, the list will be unlocked.

This works pretty well when you don’t have a large volume of requests or performance is not a concern. 
Placing a lock can be costly at some times and when there are too many concurrent requests, 
the lock may potentially block the system and becomes the performance bottleneck.


Distribute the counter
======================
When a single machine gets too many traffic and performance becomes an issue, 
it’s the perfect time to think of distributed solution. 
Distributed system significantly reduces burden of a single machine by scaling system to multiple nodes, 
but at the same time adding complexity.
Let’s say we distribute visit requests to multiple machines equally. 
In our case, we can get a hash of users email and distribute by the hash.
To count the number, each machine works independently to count its own users from the past minute. 
When we request the global number, we just need to add all counters together.
*/