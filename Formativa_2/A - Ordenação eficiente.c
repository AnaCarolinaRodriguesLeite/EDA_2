#include <stdio.h>

void merge(int *numeros, int *esquerda, int *direita, int n_esquerda, int n_direita) {
  int i = 0, j = 0, k = 0;

  while (i < n_esquerda && j < n_direita) {
    if (esquerda[i] < direita[j]) {
      numeros[k++] = esquerda[i++];
    } else {
      numeros[k++] = direita[j++];
    }
  }

  while (i < n_esquerda) {
    numeros[k++] = esquerda[i++];
  }

  while (j < n_direita) {
    numeros[k++] = direita[j++];
  }
}

void merge_sort(int *numeros, int n) {
  if (n <= 1) {
    return;
  }

  int meio = n / 2;
  int esquerda[meio];
  int direita[n - meio];

  for (int i = 0; i < meio; i++) {
    esquerda[i] = numeros[i];
  }

  for (int i = meio; i < n; i++) {
    direita[i - meio] = numeros[i];
  }

  merge_sort(esquerda, meio);
  merge_sort(direita, n - meio);

  merge(numeros, esquerda, direita, meio, n - meio);
}

int main() {
  int n;
  scanf("%d", &n);

  int numeros[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &numeros[i]);
  }

  merge_sort(numeros, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", numeros[i]);
  }

  printf("\n");

  return 0;
}
