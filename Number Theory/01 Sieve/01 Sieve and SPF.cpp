// https://youtu.be/7zYMjXqdchc?si=QrrlV_9kA_9OkbZO

// Time = O(n * log(log(n)))
struct Sieve {
    vector<bool> isprime;
    vector<int> spf;

    Sieve(int n) {
        isprime.resize(n+1, true);
        spf.resize(n+1);

        for(int i = 0; i <= n; i++) {
            isprime[i] = true;
            spf[i] = i;
        }
        
        isprime[0] = isprime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isprime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isprime[j] = false;
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
