/*
**    Função: Números de Armstrong
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 27/03/2024
**    Observações:...
*/

#include <stdio.h>

int mdc(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int sao_coprimos(int a, int b) {
    return mdc(a, b) == 1;
}

// Função para verificar se um número é um número de Carmichael
int eh_numero_carmichael(int n) {
    if (n % 2 == 0 || n == 1) {
        return 0;
    }
  
    for (int a = 2; a < n; ++a) {
        if (sao_coprimos(a, n) && ((long long)pow(a, n - 1) % n) != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numero;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);
    if (eh_numero_carmichael(numero)) {
        printf("%d é um número de Carmichael.\n", numero);
    } else {
        printf("%d não é um número de Carmichael.\n", numero);
    }
    return 0;
}