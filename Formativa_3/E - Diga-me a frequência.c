#include <stdio.h>
#include <stdlib.h>

typedef struct hashing
{
  char value;
  unsigned occurs;
} Hashing;
typedef Hashing Item;

#define HASH_MAX_SIZE 1000
#define HASH_INIT ' '
#define key(A) (A.occurs)
#define lesseq(A, B) (key(A)<=key(B))

void HashAdd(Hashing *hash_table, char value)
{
  unsigned hash_key = value;
  hash_table[hash_key].value = value;
  hash_table[hash_key].occurs++;
  return;
}
void HashClear(Hashing *vetor)
{
  for(unsigned i = 0; i <= HASH_MAX_SIZE; i++)
  {
    vetor[i].value = HASH_INIT;
    vetor[i].occurs = 0;
  }
  return;
}
void Merge(Item *V, int l, int m, int r) {
  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l, j=m+1, k=0;
  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
    R[k++]=V[i++];
  while(j<=r)
    R[k++]=V[j++];

  for(i=l,k=0; i<=r; i++,k++)
    V[i]=R[k];

  free(R);
}
void MergeSort(Item *V, int l, int r) {
  if (l>= r)
    return;
  int m=(l+r)/2;
  MergeSort(V,l,m);
  MergeSort(V,m+1,r);
  Merge(V,l,m,r);
}
void OcorrenciaCaracter(Hashing *hash_table, char *string)
{
  unsigned i, j;

  for(i = 0; string[i] != '\x0'; i++)
    HashAdd(hash_table, string[i]);
  MergeSort(hash_table, 0, HASH_MAX_SIZE);
  for(j = HASH_MAX_SIZE - i; j <= HASH_MAX_SIZE; j++)
    if(hash_table[j].value != HASH_INIT)
      printf("%d %d\n", hash_table[j].value, hash_table[j].occurs);
}
int main()
{
  char string[HASH_MAX_SIZE];
  Hashing hash_table[] = {[0 ... HASH_MAX_SIZE] = { HASH_INIT, 0 }};
  while (scanf(" %s", string) != -1)
  {
    OcorrenciaCaracter(hash_table, string);
    printf("\n");
    HashClear(hash_table);
  }
  return 0;
}
