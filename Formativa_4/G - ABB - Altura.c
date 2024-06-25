#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(no *r) {
    if (r == NULL)
        return 0;

    int altura_esq = altura(r->esq);
    int altura_dir = altura(r->dir);

    return 1 + max(altura_esq, altura_dir);
}
