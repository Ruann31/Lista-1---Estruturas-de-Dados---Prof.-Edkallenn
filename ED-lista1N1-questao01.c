/*
**    Função: Potências Fatoriais
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 25/03/2024
**    Observações:
*/

#include <stdio.h>

int fatorial(int num) {
  if (num == 0 || num == 1) {
    return 1;
  } else {
    int result = 1;
    for (int i = 2; i <= num; ++i) {
      result *= i;
    }
    return result;
  }
}

double potencia_fatorial_crescente(double x, int n) {
  double resultado = 1.0;
  for (int i = 1; i <= n; ++i) {
    resultado *= x / fatorial(i);
  }
  return resultado;
}

double potencia_fatorial_decrescente(double x, int n) {
  double resultado = 1.0;
  for (int i = n; i >= 1; --i) {
    resultado *= x / fatorial(i);
  }
  return resultado;
}

int main() {
  printf("Tabela de Resultados\n\n");

  double x = 2.0;
  printf("x = %.2lf\n", x);
  printf("--------------------------------------------\n");
  printf("|   n   | Potência Fatorial Crescente | Potência Fatorial "
         "Decrescente |\n");
  printf("--------------------------------------------\n");
  for (int n = 2; n <= 10; ++n) {
    printf("|   %d   |             %.6lf            |             %.6lf        "
           "     |\n",
           n, potencia_fatorial_crescente(x, n),
           potencia_fatorial_decrescente(x, n));
  }
  printf("--------------------------------------------\n\n");

  printf("Variando x de 2 a 10:\n");
  printf("--------------------------------------------\n");
  printf("|   x   | Potência Fatorial Crescente | Potência Fatorial "
         "Decrescente |\n");
  printf("--------------------------------------------\n");
  for (int i = 2; i <= 10; ++i) {
    printf("|  %.2lf  |             %.6lf            |             %.6lf       "
           "      |\n",
           i, potencia_fatorial_crescente(i, 5),
           potencia_fatorial_decrescente(i, 5));
  }
  printf("--------------------------------------------\n");

return 0;
}