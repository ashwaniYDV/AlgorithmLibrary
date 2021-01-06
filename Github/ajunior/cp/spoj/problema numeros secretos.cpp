#include <iostream>
using namespace std;
void quickSort(int *valor, int esquerda, int direita){
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
 
    while(i <= j)    {
        while(valor[i] < x && i < direita)        {
            i++;
        }
        while(valor[j] > x && j > esquerda){
            j--;
        }
        if(i <= j)        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
	if(j > esquerda){
        quickSort(valor, esquerda, j);
    }if(i < direita){
        quickSort(valor,  i, direita);
    }
}



int busca(int *vet, int num, int c){
	int m, i = 1, f = num;
	while (i<=f){
		m=(i+f)/2;
		if (vet[m]==c){
			return 1;	
		}else if (vet[m]<c){
			i = m + 1;
		}else{
			f = m - 1;	
		}
	}
   	return -1;	
}




int main (){

	int num;
	int temp;
	cin >> num;
	int res[num];
	
	for (int i = 0; i < num; i ++){
		cin >>res[i];
	}

	quickSort(res, 0, num-1);

	while(cin>>temp){
		if(busca(res, num+1, temp) == 1){
			cout << "sim" << endl;
		}else{
			cout << "nao" << endl;
		}
	}
	return 0;
}