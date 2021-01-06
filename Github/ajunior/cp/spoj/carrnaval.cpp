#include <iostream>

using namespace std;

int main(){
	

        double max = 5, min = 10, res = 0, temp;
        double vet[5];


        for (int i = 0; i < 5; i++) {
            cin >> vet[i];
            if (max < vet[i]) {
                max = vet[i];
            }
            if (min > vet[i]) {
                min = vet[i];
            }
        }

        for (int i = 0; i < 5; i++) {
            if (vet[i] == max) {
                max = 0;
            } else if (vet[i] == min) {
                min = 0;
            } else {
                res += vet[i];
            }
        }
   
           cout << res;
        

    
	return 0;
}