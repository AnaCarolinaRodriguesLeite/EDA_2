#include <stdlib.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz){
  if(raiz == NULL) return;

  struct no *pilha[1000];
  int topo = -1;
  no *atual = raiz;

  while(atual != NULL || topo != - 1){
    while (atual != NULL)
    {
      pilha[++topo] = atual;
      atual = atual -> esq;
    }
    atual = pilha[topo--];
    printf("%d ", atual -> dado);
    atual = atual -> dir;
  }
}

no* criar_no(int valor){
  no* novo_no = (no*)malloc(sizeof(no));
  novo_no -> dado = valor;
  novo_no -> esq = NULL;
  novo_no -> dir = NULL;
  return novo_no;
}

void liberar_arvore(no* raiz){
  if(raiz == NULL) return;
  liberar_arvore(raiz -> esq);
  liberar_arvore(raiz -> dir);
  free(raiz);
}