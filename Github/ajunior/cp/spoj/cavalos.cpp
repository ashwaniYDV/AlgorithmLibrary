#include <iostream>

using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b;
	
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	if(a > 2){
		c = ((a*b)+1)/2;
	}else if(a==2){
		if(b%4==0){
			c = b;
		}else if(b%4==2){
			c = b+2;
		}else{
			c = b+1;
		}
	}else{
		c = b;
	}
	cout << c << endl;

	return 0;
}