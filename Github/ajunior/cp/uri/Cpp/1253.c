#include <stdio.h>
#include <string.h>

int main() {
    int deslocamento; // Variável que vai receber o número de deslocamento
    int casos; // variável; que vai receber o número de casos de teste
    int i; // contador do primeiro FOR
    int j; // contador do segundo FOR
    int tamanho; // variável que vai receber o tamanho da string
    char cifra[50]; // Variável que vai receber a mensagem criptografada

    scanf("%d", &casos); // Lendo a primeira linha da Entrada

    // FOR dos casos de testes
    for(i = 1; i <= casos; i++) {
        scanf("%s", cifra); // lendo a mensagem criptografada
        scanf("%d", &deslocamento); // lendo o número do deslocamento

        tamanho = strlen(cifra); // tamanho da string

        // FOR para percorrer a string
        for (j = 0; j < tamanho; j++) {
            if (cifra[j] - deslocamento < 'A')
                cifra[j] = cifra[j] - deslocamento + 26;
            else
                cifra[j] = cifra[j] - deslocamento;
        }
        printf("%s\n", cifra); // Imprimindo a mensagem descriptografada
    }
    return 0;
}

/*
char cifra[1000];
int deslocamento;

scanf("%s",cifra);
scanf("%d",&deslocamento);
tamanho = strlen(cifra);

for(i = 0; i < tamaho; i++) {
    if(cifra[i] + deslocamento > 'Z')
        cifra[i] = deslocamento + cifra[i] - 26;
    else
        cifra[i] = cifra[i] + d;
}

printf{"%s\n",cifra);
};*/