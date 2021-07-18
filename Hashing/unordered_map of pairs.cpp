// https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/



// CPP program to demonstrate implementation of unordered_map for a pair.
#include <bits/stdc++.h>
using namespace std;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1> {}(p.first);
        auto hash2 = hash<T2> {}(p.second);
        return hash1 ^ hash2;
    }
};

// struct hash_pair {
//     size_t operator()(const pair<int, int>& p) const {
//         auto hash1 = hash<int>{}(p.first);
//         auto hash2 = hash<int>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };

// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         auto hash1 = (p.first);
//         auto hash2 = (p.second);
//         return hash1 ^ hash2;
//     }
// };

int main() {
    // Sending the hash function as a third argument
    unordered_map<pair<int, int>, char, hash_pair> um;

    // Creating some pairs to be used as keys
    pair<int, int> p1(10, 20);
    pair<int, int> p2(20, 30);
    pair<int, int> p3(25, 35);

    // Inserting values in the unordered_map.
    um[p1] = 'x';
    um[p2] = 'a';
    um[p3] = 'x';

    for (auto it : um) {
        cout << "[" << (it.first).first << ", " << (it.first).second << "] => " << it.second << "\n";
    }

    return 0;
}
