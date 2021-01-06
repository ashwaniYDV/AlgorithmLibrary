/*Só recapitulando,
** Adição Modular: (a + b) mod c = (a mod c + b mod c) mod c, pois -> (Teorema da Resto Quociente)a = c * q1 + r1, 
** de maneira análoga, b = c * q2 + r2. Podemos substituir ambos na equação (a + b) mod c, e teremos algo como
** (c * q1 + r1 + c * q2 + r2) mod c. Sabemos que qualquer número vezes um número inteiro irá resultar em um múltiplo 
** do próprio número, dessa forma podemos eliminar os multiplos de c que resultarão em uma divisão com resto 0, ficará assim
** (/(c * q1)/ + r1 + /(c * q2)/ + r2) -> (r1 + r2) mod c, ou seja, a soma dos módulos de a e b mod c é congruente a soma dos valores
** de a e b mod c, pois a mod c = r1 e b mod c = r2. A prova para a Subtração modular é semelhante */

/*Na multiplicação modular temos,
** (a * b) mod c = (a mod c * b mod c) mod c, a mod c = r1 e b mod c = r2, a = c * q1 + r1 e b = c * q2 + r2, substituíndo ambos na
** primeira equação temos -> (c * q1 + r1 * c * q2 + r2) mod c, organizando os termos temos: 
** (c * (c * q1 * q2 + c * q2 * r2 + c * q2 * r1) + r1 * r2) mod c, eliminando os múltiplos de c, temos (r1 * r2) mod c, e como vimos
** anteriormente, a mod c = r1 e b mod c = r2, logo (a * b) mod c é congruente a (a mod c * b mod c) mod c */

/*Exponenciação modular é equivalente, a^p mod c = (a mod c ^ p) mod c, uma prova disso é: caso p seja par -> 
** (a ^ p = a ^ (p / 2) * a ^ (p / 2)) mod c = ((a mod c) ^ (p / 2) * (a mod c)^ (p / 2)) mod c, 
** e esse cálculo é mais simples de se efetuar, **multiplicação de potências de mesma base: repete a base e soma-se os expoentes***
** daí voltamos para onde partimos, a ^ p mod c* é equivalente a ((a mod c) ^ p) mod c. Se p é ímpar, o|o raciocínio é o mesmo,
** só haverá mais uma multiplicação */

/*Um fato importante é que na aritmética modular não existe divisão, pois dividir um número que passou por operação modulares é 
** equivalente a multiplicá-lo pelo inverso modular do divisor mod p. Sendo o inverso modular/multiplicativo de um número: 
** a * inv = 1 mod p. Vejamos uma demonstração, o inverso de 4 = 1 / 4, ou seja, 4^-1, pois (4 * 1 / 4) mod c = 1, é confuso mesmo,
** mas depois que se resolve uma questão fica mais simples, recomendo essa bem introdutória: 
** "https://www.urionlinejudge.com.br/judge/pt/problems/view/1580". Existem diversos métodos de cálcular o inverso modular de um número
** mod c. Uma observação importante é que para um número ter inverso modular mod c, c obrigatoriamente deverá ser primo, caso contrário
** a equação a * inv = 1 mod c não terá valores para inv. Isso é fácil de entender pois um número primo só tem dois fatores, o 1 e ele 
** mesmo.*/

#include <bits/stdc++.h>

using namespace std;

/*Método linear, é ineficiente pacas, mas é um método natural e simples de entender... :v*/

int inv_lin(int div, int mod){
	for(int i = 1; i <= mod; i++){
		if((div * i) % mod == 1){
			return i;
		}
	}
	return -1; //botei essa flag só pra o Genay compilar :v
}

/*Há uma relação simétrica entre a e seu inverso, pois perceba, se x é o inverso de a mod c, então a * x = 1 mod c,
** analogamente a é o inverso de x mod c, pois x * a = 1 mod c*/

int inv[100010];

int inv_lin_plus(int div, int mod){
	if(inv[div] != 0) return inv[div];
	
	for(int i = 1; i <= mod; i++){
		if((div * i) % mod == 1){
			inv[div] = i;
			inv[i] = div;
		}
	}
	return inv[div];
}

/*Pequeno teorema de Fermat: a ^ p - 1 = 1 mod p, logo a * a ^ p - 2 = 1 mod p, dessa forma o inverso modular de a é a ^ p - 2*/
/*https://www.youtube.com/watch?v=aXAMQ8ASEhI*/
int inv_fermat(int div, int mod){
	long long x = 0;
	
	for(int i = 1; i <= mod - 2; i++){
		x = (x * div) % mod; //Exponenciação
	}
	return x;
}

/*Fermat foi genial com essa sacada, mas o modo como estamos exponenciado acima é lento, O(mod - 2). Dá pra ser mais rápido? Dá!*/

int inv_exp(int base, int pow, int mod){ //Lembrando que pow = mod - 2 inicialmente

	if(pow == 0) return 1; //Caso base: Qualquer número elevado a zero resulta em 1
	if(pow == 1) return base; //Inverso
	
	if(pow % 2 == 0){ //Utilizamos da seguinte observação: base^pow = base^(pow/2) * base^(pow/2) e isso é mais simples de calcular
		int x = inv_exp(base, pow / 2, mod) % mod;
		return (x * x) % mod;
	}else{
		//No entanto nem sempre o expoente será divisível por 2, e dessa forma dividí-lo diretamente seria trabalhoso. Simples, 
		//basta reduzí-lo a um número par e multiplicar pela base.
		return (base % mod * inv_exp(base, pow - 1, mod)) % mod;
	}
}

/*Falta Euclides, falta estudar melhor o método de Euclides Estendido*/
/*https://www.youtube.com/watch?v=oRwuQrm3gqE*/

int main(){
	
	
}
