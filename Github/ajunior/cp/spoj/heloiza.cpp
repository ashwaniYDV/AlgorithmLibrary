#include <iostream>
#include<cmath>//biblioteca utilizada para tirar a raiz e/ou para arredondar os numeros reais para inteiros
using namespace std;

float conv(float vk) {
	return vk/3.6;
}

float tempo(float x, float y, float s1, float s2, float a, float b){

	float delta,t1,t2;
	x = conv(x);
	y = conv(y);

	delta = (x-y)*(x-y) - 2*(a-b)*(s1-s2);
	if(delta < 0){
		return -1;
    }else{
	    t1=(y-x)+sqrt(delta)/(a-b);  //tirar a raiz de delta usa "sqrt"
	    t2=(y-x)-sqrt(delta)/(a-b);
	    if(t1 > 0){
			return t1;
		}
		else if(t2 > 0){
			return t2;
		}
		else{
			return -1;
		}
	}
}

int main()
{
    float r,x,y,s1,s2,a,b;
    int N;

    cin >> N;

    for(int i=0;i < N;i++){
		cin >> x >> y >> s1 >> s2 >> a >> b;
		r = tempo(x,y,s1,s2,a,b);
		cout << round(r) << endl;
	}


    return 0;
}
