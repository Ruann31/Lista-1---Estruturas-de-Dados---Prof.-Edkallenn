/*
**    Função: Números de Armstrong
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 28/03/2024
**    Observações:...
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool eh_numero_armstrong(int n) {
    int original = n;
    int soma = 0;
    int num_digitos = floor(log10(n)) + 1;

    while (n > 0) {
        int digito = n % 10;
        soma += pow(digito, num_digitos);
        n /= 10;
    }

    return soma == original;
}

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    if (eh_numero_armstrong(numero)) {
        printf("Verdadeiro, %d é um número de Armstrong\n", numero);
    } else {
        printf("Falso, %d não é um número de Armstrong\n", numero);
    }

    return 0;
}