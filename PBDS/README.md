### ordered_set

```
void solve() {
    int x, y;
    ordered_set st;
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    // 1
    cout << *st.find_by_order(0) << endl;
    // 1
    cout << *st.find_by_order(1) << endl;
    // 2
    cout << *st.find_by_order(3) << endl;

    // 1 1 1 2 3 4 
    for(int i: st) cout << i << " ";
    cout << endl;

    st.erase(st.find_by_order(st.order_of_key(2)));

    // 1 1 1 3 4 
    for(int i: st) cout << i << " ";
    cout << endl;

    st.erase(st.find_by_order(st.order_of_key(1)));

    // 1 1 3 4 
    for(int i: st) cout << i << " ";
    cout << endl;
}

Output:
1
1
2
1 1 1 2 3 4 
1 1 1 3 4 
1 1 3 4 
```
