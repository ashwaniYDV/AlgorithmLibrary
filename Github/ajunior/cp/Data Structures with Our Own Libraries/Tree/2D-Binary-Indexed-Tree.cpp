/*BIT 2D - Query rectangle

Para realizar uma consulta em um retângulo interno à um BIT, realizamos o seguintes passos:

1 - Selecionar o retângulo que possui coordenada (0, 0) e (x2, y2), no entando note que essa ainda não é a nossa resposta.
    Note que precisamos subtrair dois retângulos que não pertecem à consulta.

2 - Fazemos outra consulta que consistirá no retângulo horizontal inferior (0, 0) e (x1 - 1, y2) e então a subtraímos da primeira consulta.

3 - Precisamos eliminar também os valores do retângulo vertical esquerdo (0, 0) e (x2, y1 - 1) e então subtraímos da primeira consulta;

4 - Note que os dois retângulos (horizontal inferior e vertical esquerdo) compartilham um retângulo (0, 0) e (x1 -1, y1 - 1)
que foi subtraído duas vezes. Para que não haja perda de informação, basta realizar outra consulta referente a esse retângulo e adicioná-la à resposta;

x1  y1   x2  y2
(3, 3) | (4, 4)

query(x2, y2);
query(4, 4);

4[0][0][1][1]
3[0][0][1][1]
2[0][0][0][0]
1[0][0][0][0]
  1  2  3  4

query(x1 - 1, y2);
query(2, 4);

2[0][0][0][0]
1[0][0][0][0]
  1  2  3  4

query(x2, y1 - 1);
query(4, 2);

4[0][0]
3[0][0]
2[0][0]
1[0][0]
  1  2

query(x1 - 1, y1 - 1);
query(2, 2);

2[0][0]
1[0][0]
  1  2

Resposta = 4[0][0][1][1]  	   	           4[0][0]	           4      [1][1]
	       3[0][0][1][1] 		           3[0][0]		       3      [1][1]
	       2[0][0][0][0] - 2[0][0][0][0] - 2[0][0] + 2[0][0] =
	       1[0][0][0][0]   1[0][0][0][0]   1[0][0]   1[0][0]
	         1  2  3  4	    1  2  3  4	     1  2      1  2	           3  4*/


#include <bits/stdc++.h>

#define MAX 10011

using namespace std;

int tree[MAX][MAX];

void update(int x, int y, int val){
    for(int i = x; i < MAX; i += i & (-i)){
        for(int j = y; j < MAX; j += j & (-j)){
            tree[i][j] += val;
        }
    }
}

int query(int x, int y){
    int ret = 0;
    for(int i = x; i > 0; i -= i & (-i)){
        for(int j = y; j > 0; j -= j & (-j)){
            ret += tree[i][j];
        }
    }
    return ret;
}

int main(){
    return 0;
}
