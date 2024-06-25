#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
	int dado;
	struct celula *prox;
}celula;

celula *busca(celula *le, int x){
	celula *pontle;
	for(pontle = le; pontle!=NULL && pontle->dado != x; pontle = pontle->prox);
	return pontle;
}

celula *busca_rec(celula *le, int x){
	celula *pontle = le;
	pontle = le->prox;
	if(pontle == NULL || pontle->dado == x)
		return pontle;
	else 
		return busca_rec(pontle, x);
}