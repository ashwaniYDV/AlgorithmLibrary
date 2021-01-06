#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
 

int absolut(int t, int s){
	int ret = t - s;
	if(ret < 0){
		ret = ret * (-1);
	}
	return ret;
}

int main(){
	int n, t, l, s, a = 0, b = 0, chave = 0;
	cin >> n >> t >> l;
	for(int i = 0; i < n-1; i++){
		cin >> s;
		if(chave == 0){
			if(absolut(t , s) <= l){
				a+= absolut(t , s);
				t = s;
			}
			chave = 1;
		}else{
			if(absolut(t , s) <= l){
				b+= absolut(t , s);
				t = s;
			}
			chave = 0;
		}

	}
	cout << a << " " << b << endl;


	return 0;
}