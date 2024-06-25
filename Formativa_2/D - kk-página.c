// #include <stdio.h>
// #include <stdlib.h>

// typedef int Item;
// #define less(A,B) ((A) < (B))
// #define lesseq(A,B) ((A) <= (B))
// #define exch(A,B) { int t; t=A;A=B;B=t; }
// #define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
// #define separa(v,l,r) separacao(v,l,r)

// int separacao(Item *V,int l,int r)
// {
//   int i=l-1, j=r; Item v=V[r];
//   for(;;)
//   {
//     while(less(V[++i],v));
//     while(less(v,V[--j])) if(j==l) break;
//     if(i>=j) break;
//     exch(V[i],V[j]);
//   }
//   exch(V[i],V[r])
//   return i;
// }

// void quicksortM3(Item *V,int l, int r)
// {
//   if (r<=l) return;

//   cmpexch(V[(l+r)/2],V[r]);
//     cmpexch(V[l],V[(l+r)/2]);
//       cmpexch(V[r],V[(l+r)/2]);

//   int j=separa(V,l,r);
//   quicksortM3(V,l,j-1);
//   quicksortM3(V,j+1,r);
// }

// void quickselect(int *v, int l, int r, int k){
//     int i;
//     if(r <= l){
//         return;
//     }

//     i = separa(v, l, r);
//     if(i > k) quickselect(v, l, i-1, k);
//     if(i < k) quickselect(v, i+1, r, k);
// }


// int main() {
//     int N, P, X;
//     int *vetor;
//     int i = 0;
//     int c, f;

//     vetor = malloc(sizeof(int));

//     scanf("%d %d %d", &N, &P, &X);
//     while(i < N){
//         scanf("%d", &vetor[i]);
//         i++;
//         vetor = (int*) realloc(vetor, sizeof(int) * (i+1));
//     } 
    
//     c = P*X;
//     f = c+X-1;

//     quickselect(vetor, 0, N-1, c);
//     quickselect(vetor, c+1, N-1, f);
//     quicksortM3(vetor, c, f);

//     for(int j = c; j <= f; j++){
//         printf("%d\n", vetor[j]);
//     }

//     return 0;
// }

#include <stdio.h>

typedef int Item;

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define lesseq(A,B) (key(A) <= key(B))
#define exch(A,B) { Item t; t=A, A=B, B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(Item *V,int l,int r);
void quicksortM3(Item *V,int l, int r);
void quickselect(Item *V, int l, int r, int search);

int main() {
  int N, P, X;
  scanf("%d %d %d", &N, &P, &X);
  Item produtos[N];
  for(int i=0; i<N; i++)
    scanf("%d", &produtos[i]);
  N--;
  int pos_ini=(P*X);
  int pos_fin=(pos_ini+X)-1;
  if(pos_fin>N)
    pos_fin=N;
  quickselect(produtos, 0, N, pos_ini);
  quickselect(produtos, pos_ini, N, pos_fin);

  quicksortM3(produtos, pos_ini+1, pos_fin-1);
  for(int idx=pos_ini; idx<=pos_fin; idx++)
    printf("%d\n", produtos[idx]);
  return 0;
}

int separa(Item *V,int l,int r) {
  int i=l-1, j=r; Item v=V[r];
  for(;;) {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r])
  return i;
}
void quicksortM3(Item *V,int l, int r) {
  if (r<=l) return;
  int m=(l+r)/2;
  cmpexch(V[m],V[r]);
  cmpexch(V[l],V[m]);
  cmpexch(V[r],V[m]);

  int j=separa(V,l,r);
  quicksortM3(V,l,j-1);
  quicksortM3(V,j+1,r);
}
void quickselect(Item *V, int l, int r, int search) {
  int j=separa(V, l, r);
  if (j == search) return;
  else if (j<search) quickselect(V, j+1, r, search);
  else if (j>search) quickselect(V, l, j-1, search);
}