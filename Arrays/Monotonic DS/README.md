### Resources
* https://youtu.be/K0NgGYEAkA4?si=JyILxt_SN3P-7ILs

### When to use monotonic DS
* When solving problems where we need to maintain or track the max and min for subarrays, the simplest method is to maintain a min & max deque while using a sliding window.
* Min Deque → Tracks the indices in a monotonic increasing order to find the minimum element in the window.
* Max Deque → Tracks the indices in a monotonic decreasing order to find the maximum element in the window.
