// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/


// Method 1: List
#include<bits/stdc++.h>
using namespace std;

class Hash {
    // No. of buckets
    int BUCKET;

    // Pointer to an array containing buckets
    list<pair<int, string>> *table;
public:
    Hash(int V) {
        this->BUCKET = V;
        table = new list<pair<int, string>>[BUCKET];
    }

    // inserts a key into hash table
    void insertItem(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void findItem(int key) {
        // get the hash index of key
        int index = hashFunction(key);

        // find the key in (index)th list
        for (list <pair<int, string>> :: iterator i = table[index].begin(); i != table[index].end(); i++) {
            if ((*i).first == key) {
                cout << (*i).second << endl;
                return;
            }
        }
    }
};


// Driver program
int main() {
    int n, key, q;
    string value;
    cin >> n;

    Hash h(100);

    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        h.insertItem(key, value);
    }

    cin >> q;

    while (q--) {
        cin >> key;
        h.findItem(key);
    }

    return 0;
}

















// Method 2: Vector
#include<bits/stdc++.h>
using namespace std;

class Hash {
    // No. of buckets
    int BUCKET;

    // Pointer to an array containing buckets
    vector<pair<int, string>> *table;
public:
    Hash(int V) {
        this->BUCKET = V;
        table = new vector<pair<int, string>>[BUCKET];
    }

    // inserts a key into hash table
    void insertItem(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void findItem(int key) {
        // get the hash index of key
        int index = hashFunction(key);

        // find the key in (index)th list
        for (auto it : table[index]) {
            if (it.first == key) {
                cout << it.second << endl;
                return;
            }
        }
    }
};


// Driver program
int main() {
    int n, key, q;
    string value;
    cin >> n;

    Hash h(100);

    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        h.insertItem(key, value);
    }

    cin >> q;

    while (q--) {
        cin >> key;
        h.findItem(key);
    }

    return 0;
}
