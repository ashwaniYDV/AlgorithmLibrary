#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string book;
    vector<string>books;

    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> book;
            books.push_back(book);
        }
        sort(books.begin(), books.end());
        int size = (int)books.size();
        for (int i = 0; i < size; i++) cout << books[i] << endl;
        books.clear();
    }

    return 0;
}