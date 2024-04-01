/*
**    Função: Números de Armstrong
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 27/03/2024
**    Observações:...
*/

#include <stdio.h>
#include <stdbool.h>

int soma_quadrados_digitos(int n) {
    int soma = 0;
    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

bool eh_numero_feliz(int n) {
    bool visitados[1000] = {false};

    while (n != 1 && !visitados[n]) {
        visitados[n] = true;
        n = soma_quadrados_digitos(n);
    }

    return n == 1;
}

int main() {
    int n;
    printf("Digite um número para verificar se é um número feliz: ");
    scanf("%d", &n);

    if (eh_numero_feliz(n)) {
        printf("%d é um número feliz.\n", n);
    } else {
        printf("%d não é um número feliz.\n", n);
    }

    return 0;
}