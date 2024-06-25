#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
} no;

no *novoNo(int chave) {
  no *novo = (no *)malloc(sizeof(no));
  novo->chave = chave;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

no *buscar(no *r, int chave) {
  if (r == NULL) {
    return NULL;
  } else if (chave < r->chave) {
    return buscar(r->esq, chave);
  } else if (chave > r->chave) {
    return buscar(r->dir, chave);
  } else {
    return r;
  }
}

no *maiorEsquerda(no *r) {
  if (r == NULL) {
    return NULL;
  } else {
    no *aux = r->esq;
    while (aux != NULL && aux->dir != NULL) {
      aux = aux->dir;
    }
    return aux;
  }
}

no *remover(no *r, int chave) {
  if (r == NULL) {
    return NULL;
  } else if (chave < r->chave) {
    r->esq = remover(r->esq, chave);
  } else if (chave > r->chave) {
    r->dir = remover(r->dir, chave);
  } else {
    no *aux;

    if (r->esq == NULL && r->dir == NULL) {
      free(r);
      r = NULL;
    } else if (r->dir == NULL) {
      aux = r;
      r = r->esq;
      free(aux);
    } else {
      aux = maiorEsquerda(r->dir);
      r->chave = aux->chave;
      aux->chave = remover(r->dir, aux->chave);
    }
  }
  return r;
}