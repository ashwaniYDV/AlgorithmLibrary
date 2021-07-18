// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#


// Time = O(n), Space = O(n)
vector<ll> printFirstNegativeInteger(ll a[], ll n, ll k) {
    deque<ll> dq;
    vector<ll> res;

    for (int i = 0; i < k; i++) {
        if (a[i] < 0) dq.push_back(i);
    }

    if (dq.empty()) {
        res.push_back(0);
    } else {
        res.push_back(a[dq.front()]);
    }

    for (int i = k; i < n; i++) {
        while (!dq.empty() && dq.front() <= (i - k)) {
            dq.pop_front();
        }
        if (a[i] < 0) dq.push_back(i);

        if (dq.empty()) {
            res.push_back(0);
        } else {
            res.push_back(a[dq.front()]);
        }
    }

    return res;
}












// Time = O(n), Space = O(1)
vector<ll> printFirstNegativeInteger(ll a[], ll n, ll k) {
    vector<ll> res;

    ll firstNegIdx = 0;


    for (int i = 0; i <= n - k; i++) {

        // skip out of window
        while (firstNegIdx < i) {
            firstNegIdx++;
        }
        // skip out positive elements in cur window
        while (firstNegIdx < i + k - 1 && a[firstNegIdx] > 0) {
            firstNegIdx++;
        }

        // check if a negative element is found, otherwise use 0
        if (a[firstNegIdx] < 0) {
            res.push_back(a[firstNegIdx]);
        } else {
            res.push_back(0);
        }
    }

    return res;
}
