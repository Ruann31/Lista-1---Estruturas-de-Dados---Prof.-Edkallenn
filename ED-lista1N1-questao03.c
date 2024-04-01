/*
**    Função: Números de Armstrong
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 25/03/2024
**    Observações:...
*/

#include <stdio.h>

// Função para verificar se dois números são amigáveis
void verificarAmigaveis(int a, int b) {
    // Calculando os divisores próprios de 'a'
    int soma_a = 0;
    printf("Divisores próprios de %d: ", a);
    for (int i = 1; i <= a / 2; i++) {
        if (a % i == 0) {
            soma_a += i;
            printf("%d ", i);
        }
    }
    printf("\nSoma dos divisores próprios de %d: %d\n", a, soma_a);

    // Calculando os divisores próprios de 'b'
    int soma_b = 0;
    printf("Divisores próprios de %d: ", b);
    for (int i = 1; i <= b / 2; i++) {
        if (b % i == 0) {
            soma_b += i;
            printf("%d ", i);
        }
    }
    printf("\nSoma dos divisores próprios de %d: %d\n", b, soma_b);

    // Verificando se são amigáveis
    if (soma_a == b && soma_b == a)
        printf("%d e %d são um par de números amigáveis.\n", a, b);
    else
        printf("%d e %d não são um par de números amigáveis.\n", a, b);
}

// Função para encontrar todos os pares de números amigáveis até 'n'
void encontrarParesAmigaveis(int n) {
    printf("Pares de números amigáveis até %d:\n", n);
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            int soma_a = 0, soma_b = 0;
            for (int i = 1; i <= a / 2; i++) {
                if (a % i == 0)
                    soma_a += i;
            }
            for (int i = 1; i <= b / 2; i++) {
                if (b % i == 0)
                    soma_b += i;
            }
            if (soma_a == b && soma_b == a)
                printf("%d e %d\n", a, b);
        }
    }
}

int main() {
    int a, b;
    printf("Digite dois números para verificar se são amigáveis: ");
    scanf("%d %d", &a, &b);
    verificarAmigaveis(a, b);

    int n;
    printf("Digite um número para encontrar todos os pares de números amigáveis até ele: ");
    scanf("%d", &n);
    encontrarParesAmigaveis(n);

    return 0;
}