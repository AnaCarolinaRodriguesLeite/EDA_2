#include <stdlib.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no *raiz){
  if(raiz == NULL) return;

  struct no *pilha[1000];
  int topo = -1;
  pilha[++topo] = raiz;

  while(topo >= 0){
    no *atual = pilha[topo--];
    printf("%d ", atual -> dado);
    if(atual -> dir != NULL) pilha[++topo] = atual -> dir;
    if(atual -> esq != NULL) pilha[++topo] = atual -> esq;
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