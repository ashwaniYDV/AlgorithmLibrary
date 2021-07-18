// Time = O(n * log(log(n)))
struct SPF {
    vector<int> spf;

    SPF(int n) {
        spf.resize(n+1);

        for(int i = 0; i <= n; i++) {
            spf[i] = i;
        }
        
        for(int i = 2; i * i <= n; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j <= n; j += i) {
                    spf[j] = min(spf[j], i);
                }
            }
        }
    }

    vector<int> getFactors(int x) {
        vector<int> v;
        while(x > 1) {
            v.push_back(spf[x]);
            x /= spf[x];
        }
        return v;
    }
};

int main() {
    SPF obj(1e5);

    vector<int> v = obj.getFactors(56);
    for(int i: v) cout << i << " ";
}
