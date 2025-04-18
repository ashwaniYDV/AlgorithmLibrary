// https://codeforces.com/blog/entry/62393

#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;

int main() {
    safe_umap<int, int> mp;

    for(int i = 1; i <= 5; i++) {
        mp[i] = i*10;
    }

    for(auto [key, val]: mp) {
        cout << key << " " << val << endl;
    }
}
