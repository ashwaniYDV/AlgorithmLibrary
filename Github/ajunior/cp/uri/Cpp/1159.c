#include <stdio.h>

 int main() {
    int x, par, soma = 0;

    while (1) {

        scanf("%d", &x);
        if (x == 0) break;

        par = 0;

        while (par <= 4) {
            if (x % 2 == 0) {
                par++;
                soma += x;
                x += 2;
            }
            else x += 1;
        }

        printf("%d", soma);

        soma = 0;
    }

    return 0;
}


