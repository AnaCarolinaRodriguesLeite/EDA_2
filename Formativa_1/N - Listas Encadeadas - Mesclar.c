#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *reverse(celula *l){
  celula *revHead;
  if(l == NULL || l -> prox == NULL){
    return l;
  }

  revHead = reverse(l -> prox);
  l -> prox -> prox = l;
  l -> prox = NULL;

  return revHead;
}

void mescla_listas(celula *l1, celula *l2, celula *l3){
    l1 = l1 -> prox;
    l2 = l2 -> prox;
    while(l1 != NULL || l2 != NULL){
        if(l1 == NULL){
            celula *elem = l2 -> prox;
            l2 -> prox = l3 -> prox;
            l3 -> prox = l2;
            l2 = elem;
        }
        else if(l2 == NULL){
            celula *elem = l1 -> prox;
            l1 -> prox = l3 -> prox;
            l3 -> prox = l1;
            l1 = elem;
        }
        else{
            if(l1 -> dado > l2 -> dado){
                celula *elem = l2 -> prox;
                l2 -> prox = l3 -> prox;
                l3 -> prox = l2;
                l2 = elem;
            }
            else{
                celula *elem = l1 -> prox;
                l1 -> prox = l3 -> prox;
                l3 -> prox = l1;
                l1 = elem;
            }
        }
    }
    l3 -> prox = reverse(l3 -> prox);
}
