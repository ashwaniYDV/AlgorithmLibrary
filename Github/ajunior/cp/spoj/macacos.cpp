#include <iostream>

using namespace std;


int main(){
	
	int n,cont = 0, x1,x2,y1,y2;
	while(cin >> n, n){
		int X1 = -10001, Y1 = 10001, X2 = 10001, Y2 = -10001;
		for(int i = 0; i < n; i++){
			cin >> x1 >> y1 >> x2 >> y2;
					 			
			if(x1>X1){
				X1=x1;
			}
			if(y1<Y1){
				Y1=y1;
			}
			if(x2<X2){
				X2=x2;
			}
			if(y2>Y2){
				Y2=y2;
			}
		}
		cont++;	
		cout << "Teste " << cont << endl;
		if(X1>X2||Y2>Y1){
			cout << "nenhum" << endl << endl;
		}else{
			cout<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<< endl << endl;
		}		
	}
	
	
	
	
	return 0;
}