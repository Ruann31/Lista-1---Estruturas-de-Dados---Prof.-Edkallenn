/*
**    Função: Potências Fatoriais
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 28/03/2024
**    Observações:
*/

#include <stdio.h>

int eh_numero_perfeito(int n) {
    int soma_divisores = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            soma_divisores += i;
        }
    }

    if (soma_divisores == n) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    printf("Números perfeitos entre %d e 100000:\n", numero);

    for (int i = numero; i <= 100000; i++) {
        if (eh_numero_perfeito(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}