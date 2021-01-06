#include <stdio.h>
#include <iostream>
#include <string.h>
 
using namespace std;
 
int main(){
    int a, b;
 
    cin >> a >> b;
    if(b <= 2){
        cout << "nova" << endl;
    }else if(b >= 97){
   		cout << "cheia" <<endl;
    }else {
        if(a < b){
            cout << "crescente" << endl;
        }else{
            cout << "minguante" << endl;
        }
    }
}