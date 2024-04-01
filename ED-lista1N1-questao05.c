/*
**    Função: Números de Armstrong
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 28/03/2024
**    Observações:...
*/

#include <stdio.h>

// Função para calcular o fatorial de um número
unsigned long long fatorial(int n) {
    unsigned long long fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

// Função para calcular a soma dos fatoriais inversos até o termo n
double soma_fatoriais_inversos(int n) {
    double soma = 0.0;
    for (int i = 1; i <= n; i++) {
        soma += 1.0 / fatorial(i);
    }
    return soma;
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    double resultado = soma_fatoriais_inversos(n);
    printf("A soma dos fatoriais inversos até o termo %d é: %lf\n", n, resultado);

    return 0;
}