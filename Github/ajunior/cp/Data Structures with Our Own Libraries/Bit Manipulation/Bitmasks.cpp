#include <bits/stdc++.h>

using namespace std;

int set_bit(int num, int j){
    return num |= (1 << j);
}

bool check_bit(int num, int j){
    return (num &= (1 << j));
}

int clear_bit(int num, int j){
    return num &= ~(1 << j);
}

int toggle_bit(int num, int j){
    return num ^= (1 << j);
}

int last_one(int num){
    return num & (-num);
}

int on_all(int n){
    return (1 << n) - 1;
}

int main(){
    return 0;
}
