/*
**    Função: Fatorial Duplo
**    Autor: Ruann Pablo da Silva Pinheiro
**    Data: 25/03/2023
**    Observações:...
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

  int fatorial_duplo(int num) {
      if (num == 0 || num == 1) {
          return 1;
      } else {
          int result = 1;
          for (int i = num; i >= 1; i -= 2) {
              result *= i;
          }
          return result;
      }
  }

  int main() {
      FILE *arquivo;
      arquivo = fopen("resultados.txt", "w");
      if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo.");
          return 1;
      }

      fprintf(arquivo, "Tabela de Resultados\n\n");
      printf("Tabela de Resultados\n\n");

      int fatoriais_normais[19];
      int fatoriais_duplos[19];
      int diferencas[19];

      for (int i = 2; i <= 20; ++i) {
          fatoriais_normais[i - 2] = fatorial(i);
          fatoriais_duplos[i - 2] = fatorial_duplo(i);
          diferencas[i - 2] = fatoriais_normais[i - 2] - fatoriais_duplos[i - 2];
      }

      printf("--------------------------------------------\n");
      printf("|   n   | Fatorial Normal | Fatorial Duplo |\n");
      printf("--------------------------------------------\n");
      for (int i = 0; i < 19; ++i) {
          printf("|   %2d  |    %10d    |    %10d    |\n", i + 2, fatoriais_normais[i], fatoriais_duplos[i]);
      }
      printf("--------------------------------------------\n\n");

      printf("--------------------------------------------\n");
      printf("|   n   | Fatorial Normal | Fatorial Duplo |   Diferença   |\n");
      printf("--------------------------------------------\n");
      for (int i = 0; i < 19; ++i) {
          printf("|   %2d  |    %10d    |    %10d    |    %10d    |\n", i + 2, fatoriais_normais[i], fatoriais_duplos[i], diferencas[i]);
      }
      printf("--------------------------------------------\n");

      fprintf(arquivo, "Tabela de Resultados\n\n");
      fprintf(arquivo, "--------------------------------------------\n");
      fprintf(arquivo, "|   n   | Fatorial Normal | Fatorial Duplo |\n");
      fprintf(arquivo, "--------------------------------------------\n");
      for (int i = 0; i < 19; ++i) {
          fprintf(arquivo, "|   %2d  |    %10d    |    %10d    |\n", i + 2, fatoriais_normais[i], fatoriais_duplos[i]);
      }
      fprintf(arquivo, "--------------------------------------------\n\n");

      fprintf(arquivo, "--------------------------------------------\n");
      fprintf(arquivo, "|   n   | Fatorial Normal | Fatorial Duplo |   Diferença   |\n");
      fprintf(arquivo, "--------------------------------------------\n");
      for (int i = 0; i < 19; ++i) {
          fprintf(arquivo, "|   %2d  |    %10d    |    %10d    |    %10d    |\n", i + 2, fatoriais_normais[i], fatoriais_duplos[i], diferencas[i]);
      }
      fprintf(arquivo, "--------------------------------------------\n");

      fclose(arquivo);

   return 0;
}