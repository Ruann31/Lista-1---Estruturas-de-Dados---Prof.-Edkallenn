/*
**    Função: Números de Armstrong
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 27/03/2024
**    Observações:...
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eh_numero_automorfico(int n) {
    long long quadrado = (long long)n * n;
    while (n > 0) {
        if (n % 10 != quadrado % 10)
            return 0; 
        n /= 10;
        quadrado /= 10;
    }
    return 1;
}

int *numeros_automorficos(int n, int *qtd_automorficos) {
    int *automorficos = NULL;
    *qtd_automorficos = 0;

    for (int i = 2; i <= n; i++) {
        if (eh_numero_automorfico(i)) {
            (*qtd_automorficos)++;
            automorficos = (int *)realloc(automorficos, (*qtd_automorficos) * sizeof(int));
            if (automorficos == NULL) {
                printf("Erro ao alocar memória.\n");
                exit(EXIT_FAILURE);
            }
            automorficos[(*qtd_automorficos) - 1] = i;
        }
    }

    return automorficos;
}

int main() {
    int n;
    printf("Digite um número para encontrar todos os números automórficos até ele: ");
    scanf("%d", &n);

    int qtd_automorficos;
    int *automorficos = numeros_automorficos(n, &qtd_automorficos);

    printf("Números automórficos entre 2 e %d:\n", n);
    for (int i = 0; i < qtd_automorficos; i++) {
        printf("%d ", automorficos[i]);
    }
    printf("\n");

    free(automorficos);

return 0;
}