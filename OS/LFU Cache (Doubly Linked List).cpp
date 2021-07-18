// https://leetcode.com/problems/lfu-cache/
// https://youtu.be/0PSB9y8ehbk
// https://leetcode.com/problems/lfu-cache/discuss/937737/C%2B%2B%3A-O(1)-time-complexity-with-algorithm


/*
Page Replacement Algorithm
*/


// Method 1: Using STL List
class LFUCache {
private:
    struct Node {
        int value;
        list<int>::iterator itr;
    };

    // <key, Node>
    unordered_map<int, Node> cache;
    // <key, freq>
    unordered_map<int, int> freq;
    // <freq, list<key>>
    unordered_map<int, list<int>> m_countKeyMap;
    int minFrequency;
    int cap;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFrequency = 0;
    }

    int get(int key) {
        if (!cache.count(key) || cap <= 0) return -1;

        // update frequency and return value
        put(key, cache[key].value);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        // If key is not present and capacity has exceeded,
        // then remove the key entry with least frequency
        // else just make the new key entry
        if (cache.find(key) == cache.end()) {
            if (cache.size() == cap) {
                int keyToDelete = m_countKeyMap[minFrequency].back();
                m_countKeyMap[minFrequency].pop_back();
                if (m_countKeyMap[minFrequency].empty()) {
                    m_countKeyMap.erase(minFrequency);
                }
                cache.erase(keyToDelete);
                freq.erase(keyToDelete);
            }
            freq[key] = 0;
            minFrequency = 0;
            m_countKeyMap[freq[key]].push_front(key);
            cache[key] = {value, m_countKeyMap[freq[key]].begin()};
        }
        // Just update value and frequency
        else {
            m_countKeyMap[freq[key]].erase(cache[key].itr);
            if (m_countKeyMap[freq[key]].empty()) {
                if (minFrequency == freq[key]) {
                    minFrequency++;
                }
                m_countKeyMap.erase(freq[key]);
            }

            freq[key]++;
            m_countKeyMap[freq[key]].push_front(key);
            cache[key] = {value, m_countKeyMap[freq[key]].begin()};
        }
    }
};





















// Method 2: Implementing our own doubly linked list

struct Listnode {
    int data;
    Listnode *prev, *next;
    Listnode(int d) {
        data = d;
        prev = next = NULL;
    }
};

class List {
    Listnode *head, *tail;
    int count;
public:
    List() {
        head = new Listnode(-1);
        tail = new Listnode(-1);
        head->next = tail;
        tail->prev = head;
        count = 0;
    }
    int empty() {
        return count == 0;
    }
    int front() {
        if (count == 0) return -1;
        return head->next->data;
    }
    int back() {
        if (count == 0) return -1;
        return tail->prev->data;
    }
    Listnode* begin() {
        if (count == 0) return NULL;
        return head->next;
    }
    void push_front(int d) {
        Listnode *node = new Listnode(d);
        Listnode *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        count++;
    }
    void push_back(int d) {
        Listnode *node = new Listnode(d);
        Listnode *temp = tail->prev;
        tail->prev = node;
        node->next = tail;
        node->prev = temp;
        temp->next = node;
        count++;
    }
    void pop_front() {
        if (count == 0) return;
        if (count == 1) {
            Listnode *node = head->next;
            head->next = tail;
            tail->prev = head;
            delete node;
            count--;
            return;
        }

        Listnode *node = head->next;
        Listnode *temp = head->next->next;
        head->next = temp;
        temp->prev = head;
        delete node;
        count--;
    }
    void pop_back() {
        if (count == 0) return;
        if (count == 1) {
            Listnode *node = head->next;
            head->next = tail;
            tail->prev = head;
            delete node;
            count--;
            return;
        }

        Listnode *node = tail->prev;
        Listnode *temp = tail->prev->prev;
        tail->prev = temp;
        temp->next = tail;
        delete node;
        count--;
    }
    void erase(Listnode *node) {
        if (!node) return;
        Listnode *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
        count--;
    }
    void print() {
        Listnode *temp = head->next;
        while (temp != tail) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class LFUCache {
private:
    struct Node {
        int value;
        Listnode *itr;
    };

    // <key, Node>
    unordered_map<int, Node> cache;
    // <key, freq>
    unordered_map<int, int> freq;
    // <freq, list<key>>
    unordered_map<int, List> m_countKeyMap;
    int minFrequency;
    int cap;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFrequency = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end() || cap <= 0) return -1;

        // update frequency and return value
        put(key, cache[key].value);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        // If key is not present and capacity has exceeded,
        // then remove the key entry with least frequency
        // else just make the new key entry
        if (cache.find(key) == cache.end()) {
            if (cache.size() == cap) {
                int keyToDelete = m_countKeyMap[minFrequency].back();
                m_countKeyMap[minFrequency].pop_back();
                if (m_countKeyMap[minFrequency].empty()) {
                    m_countKeyMap.erase(minFrequency);
                }
                cache.erase(keyToDelete);
                freq.erase(keyToDelete);
            }
            freq[key] = 0;
            minFrequency = 0;
            m_countKeyMap[freq[key]].push_front(key);
            cache[key] = {value, m_countKeyMap[freq[key]].begin()};
        }
        // Just update value and frequency
        else {
            m_countKeyMap[freq[key]].erase(cache[key].itr);
            if (m_countKeyMap[freq[key]].empty()) {
                if (minFrequency == freq[key]) {
                    minFrequency++;
                }
                m_countKeyMap.erase(freq[key]);
            }

            freq[key]++;
            m_countKeyMap[freq[key]].push_front(key);
            cache[key] = {value, m_countKeyMap[freq[key]].begin()};
        }
    }
};








// https://youtu.be/0PSB9y8ehbk

class LFUCache {
private:
    struct Node {
        int key, value, cnt;
        Node *prev;
        Node *next; 
        Node(int _key, int _value) {
            key = _key;
            value = _value; 
            cnt = 1; 
        }
    }; 
    struct List {
        int size; 
        Node *head; 
        Node *tail; 
        List() {
            head = new Node(0, 0); 
            tail = new Node(0, 0); 
            head->next = tail;
            tail->prev = head; 
            size = 0;
        }

        void addFront(Node *node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++; 
        }

        void removeNode(Node* delnode) {
            Node* delprev = delnode->prev;
            Node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--; 
        }
    };
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize;
    
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); 
        freqListMap[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
