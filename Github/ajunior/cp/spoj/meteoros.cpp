#include <iostream>
using namespace std;

int main(){
	int x1, y1, x2, y2, n, teste = 0,cont = 0;
	while(cin >> x1 >> y1 >> x2 >> y2){
		if(x1 ==0 && x2==0 && y1==0 && y2==0){
			break;
		}
		if(x1>x2){
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		
		if(y1>y2){
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}

		
		teste++;
		cin >> n;
		int a, b;
		for(int i = 0; i < n; i++)	{
			cin >> a >> b;
			
			if(a >= x1 && a <= x2 && b >= y1 && b <= y2){
				cont++;
			} 
		}
		cout << "Teste " << teste << endl;
		cout << cont << endl << endl;
		cont = 0;
		
		
	}
	
	
	
	
	
	return 0;
}