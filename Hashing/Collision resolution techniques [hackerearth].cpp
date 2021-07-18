// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/


/*
Separate chaining (open hashing)
*/

#include <bits/stdc++.h>
using namespace std;

const int BUCKET = 20;
vector <string> hashTable[BUCKET];

int hashFunc(string s) {
    // hashFunc(abcd) = (97 * 1 + 98 * 2 + 99 * 3 + 100 * 4) % BUCKET
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash += s[i] * (i + 1);
        hash %= BUCKET;
    }
    return hash;
}

void insert(string s) {
    // Compute the index using Hash Function
    int index = hashFunc(s);
    // Insert the element in the linked list at the particular index
    hashTable[index].push_back(s);
}

void search(string s) {
    // Compute the index by using the hash function
    int index = hashFunc(s);
    // Search the linked list at that specific index
    for (int i = 0; i < hashTable[index].size(); i++) {
        if (hashTable[index][i] == s) {
            cout << s << " is found!" << endl;
            return;
        }
    }
    cout << s << " is not found!" << endl;
}


int main() {
    string s = "ashwani";
    search(s);
    insert(s);
    search(s);
}





















/*
Linear probing (open addressing or closed hashing)
*/

#include <bits/stdc++.h>
using namespace std;

const int BUCKET = 21;
string hashTable[BUCKET];

int hashFunc(string s) {
    // hashFunc(abcd) = (97 * 1 + 98 * 2 + 99 * 3 + 100 * 4) % BUCKET
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash += s[i] * (i + 1);
        hash %= BUCKET;
    }
    return hash;
}

void insert(string s) {
    // Compute the index using the hash function
    int index = hashFunc(s);
    // Search for an unused slot and if the index will exceed the BUCKET then roll back
    while (hashTable[index] != "") {
        index = (index + 1) % BUCKET;
    }
    hashTable[index] = s;
}

void search(string s) {
    // Compute the index using the hash function
    int index = hashFunc(s);
    // Search for an unused slot and if the index will exceed the BUCKET then roll back
    while (hashTable[index] != s and hashTable[index] != "") {
        index = (index + 1) % BUCKET;
    }
    // Check if the element is present in the hash table
    if (hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;
}


int main() {
    string s = "ashwani";
    search(s);
    insert(s);
    search(s);
}


























/*
Quadratic Probing
*/

#include <bits/stdc++.h>
using namespace std;


const int BUCKET = 20;
vector <string> hashTable[BUCKET];

int hashFunc(string s) {
    // hashFunc(abcd) = (97 * 1 + 98 * 2 + 99 * 3 + 100 * 4) % BUCKET
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash += s[i] * (i + 1);
        hash %= BUCKET;
    }
    return hash;
}

void insert(string s) {
    // Compute the index using the hash function
    int index = hashFunc(s);
    // Search for an unused slot and if the index will exceed the BUCKET roll back
    int h = 1;
    while (hashTable[index] != "") {
        index = (index + h * h) % BUCKET;
        h++;
    }
    hashTable[index] = s;
}

void search(string s) {
    // Compute the index using the Hash Function
    int index = hashFunc(s);
    // Search for an unused slot and if the index will exceed the BUCKET roll back
    int h = 1;
    while (hashTable[index] != s and hashTable[index] != "") {
        index = (index + h * h) % BUCKET;
        h++;
    }
    // Is the element present in the hash table
    if (hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;
}

int main() {
    string s = "ashwani";
    search(s);
    insert(s);
    search(s);
}





























/*
Double hashing
*/

#include <bits/stdc++.h>
using namespace std;

const int BUCKET = 21;
string hashTable[BUCKET];

int hashFunc1(string s) {
    // hashFunc(abcd) = (97 * 1 + 98 * 2 + 99 * 3 + 100 * 4) % BUCKET
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash += s[i] * (i + 1);
        hash %= BUCKET;
    }
    return hash;
}

int hashFunc2(string s) {
    // hashFunc(abcd) = (97 * 4 + 98 * 3 + 99 * 2 + 100 * 1) % BUCKET
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash += s[i] * (s.size() - i);
        hash %= BUCKET;
    }
    return hash;
}

void insert(string s) {
    // Compute the index using the hash function1
    int index = hashFunc1(s);
    int indexH = hashFunc2(s);
    // Search for an unused slot and if the index exceeds the BUCKET roll back
    while (hashTable[index] != "") {
        index = (index + indexH) % BUCKET;
    }
    hashTable[index] = s;
}

void search(string s) {
    //Compute the index using the hash function
    int index = hashFunc1(s);
    int indexH = hashFunc2(s);
    //Search for an unused slot and if the index exceeds the BUCKET roll back
    while (hashTable[index] != s and hashTable[index] != "") {
        index = (index + indexH) % BUCKET;
    }
    //Is the element present in the hash table
    if (hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;
}

int main() {
    string s = "ashwani";
    search(s);
    insert(s);
    search(s);
}
