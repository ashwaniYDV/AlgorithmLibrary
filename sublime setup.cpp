// https://medium.datadriveninvestor.com/how-to-setup-sublime-text-for-c-competitive-coding-665ea495aeb5

/*
Create 3 files:
===============
a.cpp
input.txt
output.txt


Run using 
=========
Cmd+B
*/


#include<iostream>
using namespace std;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int var;
  cin >> var;
  for(int i=1; i<=10; i++) {
      cout<<var * i+1<<endl;
  }
  return 0;
}
