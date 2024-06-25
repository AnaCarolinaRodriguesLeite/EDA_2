#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *minimo(no *r) {
    if (r == NULL)
        return NULL;

    while (r->esq != NULL)
        r = r->esq;

    return r;
}
