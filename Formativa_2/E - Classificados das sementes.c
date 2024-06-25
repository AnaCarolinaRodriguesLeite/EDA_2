#include <stdio.h>
#include <stdlib.h>
#define Key(A) (A.nota)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define KeyS(A) (A.semente)
#define lessS(A, B) (KeyS(A) < KeyS(B))
#define lesseqS(A, B) (KeyS(A) <= KeyS(B))
#define exch(A, B) \
  {                \
    Item t = A;    \
    A = B;         \
    B = t;         \
  }
#define cmpexch(A, B) \
  {                   \
    if (less(B, A))   \
      exch(A, B);     \
  }
#define cmpexchS(A, B) \
  {                    \
    if (lessS(B, A))   \
      exch(A, B);      \
  }

typedef struct
{
  long int semente;
  long int nota;
} Item;

int compara(Item A, Item B);
int separa(Item *V, int l, int r);
void QuickSelect(Item *v, int l, int r, int p);
void merge(Item *v, int l, int r1, int r2);
void MergeSort(Item *v, int l, int r);

int total = 0;

int main()
{
  long int k, s, n, aux;

  scanf("%ld", &k);
  Item *sementes = malloc(sizeof(Item) * 4);

  aux = k;

  while (scanf("%ld %ld", &s, &n) == 2)
  {
    sementes[total].nota = n;
    sementes[total++].semente = s;
    if (total >= total % 4)
    {
      sementes = realloc(sementes, sizeof(Item) * (total + 4));
    }
  }
  QuickSelect(sementes, 0, total - 1, k);
  MergeSort(sementes, 0, k - 1);

  for (int i = 0; i < aux; i++)
  {
    printf("%ld %ld\n", sementes[i].semente, sementes[i].nota);
  }
  return 0;
}

int compara(Item a, Item b)
{ // compara nota
  if (a.nota == b.nota)
  {
    return a.semente < b.semente;
  }
  else
  {
    return a.nota < b.nota;
  }
}

int separa(Item *V, int l, int r)
{ // separa por nota
  if (lesseq(V[r], V[(r + l) / 2]))
  {
    if (V[(r + l) / 2].nota == V[r].nota)
    {
      cmpexchS(V[(r + l) / 2], V[r]);
    }
    else
    {
      exch(V[(r + l) / 2], V[r]);
    }
  }
  if (lesseq(V[(r + l) / 2], V[l]))
  {
    if (V[(r + l) / 2].nota == V[l].nota)
    {
      cmpexchS(V[l], V[(r + l) / 2]);
    }
    else
    {
      exch(V[(r + l) / 2], V[l]);
    }
  }
  if (lesseq(V[(r + l) / 2], V[r]))
  {
    if (V[(r + l) / 2].nota == V[r].nota)
    {
      cmpexchS(V[r], V[(r + l) / 2]);
    }
    else
    {
      exch(V[(r + l) / 2], V[r]);
    }
  }
  Item c = V[r];
  int j = l;
  for (int k = l; k < r; k++)
  {
    if (compara(V[k], c))
    {
      exch(V[k], V[j]);
      j++;
    }
  }
  exch(V[j], V[r]);
  return j;
}

void QuickSelect(Item *v, int l, int r, int p)
{
  if (r <= l)
    return;

  int i = separa(v, l, r);

  if (i > p)
  {
    QuickSelect(v, l, i - 1, p);
  }
  if (i < p)
  {
    QuickSelect(v, i + 1, r, p);
  }
}

void merge(Item *v, int l, int r1, int r2)
{
  Item *v2 = malloc(sizeof(Item) * (r2 - l + 1));
  int k = 0, i = l, j = r1 + 1;
  while (i <= r1 && j <= r2)
  {
    if (lesseqS(v[i], v[j]))
      v2[k++] = v[i++];
    else
      v2[k++] = v[j++];
  }
  while (i <= r1)
    v2[k++] = v[i++];
  while (j <= r2)
    v2[k++] = v[j++];

  k = 0;
  for (i = l; i <= r2; i++)
  {
    v[i] = v2[k++];
  }
  free(v2);
}

void MergeSort(Item *v, int l, int r)
{
  if (l >= r)
    return;

  int meio = (r + l) / 2;

  MergeSort(v, l, meio);
  MergeSort(v, meio + 1, r);
  merge(v, l, meio, r);
}