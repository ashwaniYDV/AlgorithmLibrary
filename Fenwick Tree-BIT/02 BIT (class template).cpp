class fenwick {
    vector < int > bit;
    int N;
public:
    fenwick(int n) {
        N = n + 5;
        bit.resize(N);
    }
    void add(int i, int val) {
        while (i < N) {
            bit[i] += val;
            i += (i & -i);
        }
    }
    int query(int i) {
        int ans(0);
        while (i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
    // array must be of non-negative integers
    int lower_bound(int val) {
        static
        const int LOG = log2(N);
        int sum = 0, pos = 0;
        for (int i = LOG; i >= 0; --i) {
            int calc = pos + (1 << i);
            if (calc < N && sum + bit[calc] < val) {
                sum += bit[calc];
                pos = calc;
            }
        }
        if (pos > N - 5) pos = N - 5;
        return pos + 1;
    }
};
