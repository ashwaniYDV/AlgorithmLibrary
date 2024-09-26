// https://leetcode.com/problems/lru-cache/
// https://youtu.be/xDEuM5qa0zg -> Take U Forward
// Page Replacement Algorithm

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:

LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
int get(int key): Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
                              If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/


class LRUCache {
public:
    struct Node {
        int val;
        list<int>::iterator itr;
    };
    unordered_map<int, Node> cache;
    // old values move to back, new ones enter at front
    list<int> dll;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        put(key, cache[key].val);
        return cache[key].val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            dll.erase(cache[key].itr);
            cache.erase(key);
        }
        if (cache.size() == cap) {
            cache.erase(dll.back());
            dll.pop_back();
        }

        dll.push_front(key);
        cache[key] = {value, dll.begin()};
    }
};



class LRUCache {
    int cap;
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key -> {val, dll_pointer}
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        put(key, cache[key].first);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            dll.erase(cache[key].second);
            cache.erase(key);
        }
        if(cache.size() == cap) {
            cache.erase(dll.back());
            dll.pop_back();
        }

        dll.push_front(key);
        cache[key] = {value, dll.begin()};
    }
};












// https://leetcode.com/problems/lfu-cache/description/
// https://youtu.be/0PSB9y8ehbk?si=u8ysixYbYPC9cpJ6
// Page Replacement Algorithm

/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:
    a) LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    b) int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    c) void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. 
       When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. 
       For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

class LFUCache {
    struct Node {
        int value;
        list<int>::iterator itr;
    };

    int cap;
    unordered_map<int, Node> cache; // key -> Node
    unordered_map<int, int> freq; // key -> freq
    unordered_map<int, list<int>> freqToLruDllMap; // freq -> list<key>
    int minFrequency;
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFrequency = 0;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        put(key, cache[key].value);
        return cache[key].value;
    }
    
    void put(int key, int value) {
        // If key is present just update value and frequency
        if(cache.count(key)) {
            freqToLruDllMap[freq[key]].erase(cache[key].itr);
            if (freqToLruDllMap[freq[key]].empty()) {
                freqToLruDllMap.erase(freq[key]);
                if (minFrequency == freq[key]) {
                    minFrequency++;
                }
            }
            
            freq[key]++;
            freqToLruDllMap[freq[key]].push_front(key);
            cache[key] = {value, freqToLruDllMap[freq[key]].begin()};
        } 
        // If key is not present and capacity has exceeded,
        // then remove the key entry with least frequency
        // else just make the new key entry
        else {
            if (cache.size() == cap) {
                int keyToDelete = freqToLruDllMap[minFrequency].back();
                freqToLruDllMap[minFrequency].pop_back();
                if (freqToLruDllMap[minFrequency].empty()) {
                    freqToLruDllMap.erase(minFrequency);
                }
                cache.erase(keyToDelete);
                freq.erase(keyToDelete);
            }
            freq[key] = 1;
            minFrequency = 1;
            freqToLruDllMap[freq[key]].push_front(key);
            cache[key] = {value, freqToLruDllMap[freq[key]].begin()};
        }
        
    }
};
