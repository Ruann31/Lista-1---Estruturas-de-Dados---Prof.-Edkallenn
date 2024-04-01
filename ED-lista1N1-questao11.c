/*
**    Função: Potências Fatoriais
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 29/03/2024
**    Observações:
*/

#include <stdio.h>
#include <stdlib.h>

int permutacao_circular(int *array1, int *array2, int tamanho) {
    int i, j;

    int iguais = 1;
    for (i = 0; i < tamanho; i++) {
        if (array1[i] != array2[i]) {
            iguais = 0;
            break;
        }
    }

    if (iguais) return 0;

    for (i = 0; i < tamanho; i++) {
        int igualdade = 1;
        for (j = 0; j < tamanho; j++) {
            if (array1[j] != array2[(i + j) % tamanho]) {
                igualdade = 0;
                break;
            }
        }
        if (igualdade) return 1;
    }

    return 0;
}

int main() {
    int tamanho;
    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int *array1 = (int *)malloc(tamanho * sizeof(int));
    int *array2 = (int *)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array2[i]);
    }

    if (permutacao_circular(array1, array2, tamanho)) {
        printf("É uma permutação circular.\n");
    } else {
        printf("Não é uma permutação circular.\n");
    }

    free(array1);
    free(array2);
    return 0;
}