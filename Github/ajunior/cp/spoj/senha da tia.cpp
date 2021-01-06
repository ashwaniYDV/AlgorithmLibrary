#include <iostream>
#include <string>

using namespace std;
int main(){
	int n , b , c, d;
	string teste;
	
	cin >> n >> b >> c >> d;
	cin >> teste;

	for(int i = 0; i < teste.length();i++)	{
		for(int t = 48; t < 58; t++){
			if(teste[i]== (char) t){
				d--;
				n--;
			}
		}
		for(int t = 65; t < 91; t++){
			if(teste[i]==(char)t){
				c--;
				n--;
			}
		}
		
		for(int t = 97; t < 123; t++){
			if(teste[i]==(char)t){
				b--;
				n--;
			}
			
		}
	
	}
	
		if(n <= 0 && b <=0 && c <=0 && d <=0){
			cout <<"Ok =/"<<endl;
		}else{
			cout <<"Ufa :)"<<endl;
		}
	
	return 0;
}