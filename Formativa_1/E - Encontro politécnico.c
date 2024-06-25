#include <stdio.h>

int main(){
    int N, M, xa, xb, ya, yb, da, db, mov,i;
    
    scanf("%d %d", &N, &M);
    scanf("%d", &mov);

    xa=1;
    ya=1;
    xb=N;
    yb=M;

    for(i=0; i < mov; i++){
        scanf("%d %d", &da, &db);

        if(da == 1)ya++;
        else if(da == 2)ya--;
        else if(da == 3)xa++;
        else xa--;

        if(db == 1)yb++;
        else if(db == 2)yb--;
        else if(db == 3)xb++;
        else xb--;

        if(xa == xb && ya == yb){
            printf("Encontraram-se na posicao (%d, %d) no passo %d\n", xa, ya, i+1);
            break;
        } else if(xa > N || xa < 1 || ya > M || ya < 1){
            printf("PA saiu na posicao (%d, %d) no passo %d\n", xa, ya, i+1);
            break;
        } else if(xb > N || xb < 1 || yb > M || yb < 1){
            printf("PB saiu na posicao (%d, %d) no passo %d\n", xb, yb, i+1);
            break;
        }
    }
    if(i == mov)
        printf("Nao se encontraram\n");
    
    return 0;
}