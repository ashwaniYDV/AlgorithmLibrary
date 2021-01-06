#include <iostream>
using namespace std;

int main(){
	
	int n, a, b, c, d, res = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
	   	cin >> a >> b >> c >> d;
		if(a < c){
			c = c-a;
			res += c*c;
		}else{
			a = a-c;
			res += a*a;
		}
	
		if(b > d){
			b = b-d;
			res+= b*b;
		}else{
			d=d-b;
			res+= d*d;
		}
	
	}	
	cout << res << endl;
	
	
	return 0;
}