#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *criar_no(int x) {
    no *novo_no = (no*)malloc(sizeof(no));
    if (novo_no != NULL) {
        novo_no->chave = x;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
    }
    return novo_no;
}

no *inserir(no *r, int x) {
    if (r == NULL)
        return criar_no(x);
    
    if (x < r->chave)
        r->esq = inserir(r->esq, x);
    else if (x > r->chave)
        r->dir = inserir(r->dir, x);

    return r;
}
