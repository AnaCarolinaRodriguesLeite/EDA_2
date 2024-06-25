#include <stdio.h>

int main() {
  int N, i, acimaMedia = 0;
  long long int soma = 0, media;
  int numeros[10000];

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%d", &numeros[i]);
    soma += numeros[i];
  }
  media = soma / N;

  for (i = 0; i < N; i++) {
    if (numeros[i] > media) {
      printf("%d ", numeros[i]);
      acimaMedia = 1;
    }
  }
  if (!acimaMedia) {
    printf("0");
  }
  printf("\n");
  return 0;
}
