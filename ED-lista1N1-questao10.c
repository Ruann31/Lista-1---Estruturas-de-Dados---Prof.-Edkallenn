/*
**    Função: Fatorial Duplo
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 29/03/2023
**    Observações:...
*/

#include <stdio.h>
#include <stdlib.h>

int* fibonacci_max(int max) {
    int* fibonacci_sequence = (int*)malloc(sizeof(int));
    if (fibonacci_sequence == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    int n = 2;  // Tamanho inicial do array
    fibonacci_sequence[0] = 0;
    fibonacci_sequence[1] = 1;

    int i = 2;
    while (1) {
        fibonacci_sequence = (int*)realloc(fibonacci_sequence, (i + 1) * sizeof(int));
        if (fibonacci_sequence == NULL) {
            printf("Erro de realocação de memória.\n");
            exit(1);
        }

        fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
        if (fibonacci_sequence[i] > max) {
            fibonacci_sequence[i] = -1; // Marcador de posição especial
            break;
        }
        i++;
    }

    return fibonacci_sequence;
}

int main() {
    int max;
    printf("Digite o valor máximo para a série de Fibonacci: ");
    scanf("%d", &max);

    int* fib_array = fibonacci_max(max);

    printf("Série de Fibonacci até %d:\n", max);
    for (int i = 0; fib_array[i] != -1; i++) {
        printf("%d ", fib_array[i]);
    }
    printf("\n");

    free(fib_array); 

    return 0;
}