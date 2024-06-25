#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 2000

struct Node
{
  int value;
  struct Node *next;
};

typedef struct Node *Link;

struct Grafo
{
  int qtd_vertices;
  int qtd_edges;
  Link *adj;
};

typedef struct Grafo *Grafo;

typedef struct
{
  int vertice_origem;
  int vertice_destino;
} Edge;

typedef Edge Item;

Edge EDGE(int v, int w)
{
  Edge e = {v, w};
  return e;
}

Link novo_grafo(int value, Link next)
{
  Link x = malloc(sizeof(Link));

  x->value = value;
  x->next = next;

  return x;
}

Grafo iniciar_grafo(int V)
{
  int v;
  Grafo G = malloc(sizeof(Grafo));

  G->qtd_vertices = V;
  G->qtd_edges = 0;
  G->adj = malloc(sizeof(Link) * V);

  for (v = 0; v < G->qtd_vertices; v++)
  {
    G->adj[v] = NULL;
  }

  return G;
}

void Grafo_Insert_Edge(Grafo G, Edge edge)
{
  int V = edge.vertice_origem;
  int W = edge.vertice_destino;

  G->adj[V] = novo_grafo(W, G->adj[V]);
  G->qtd_edges++;
}

int main()
{
  int N, M, J, i;
  int estarei[MAX];
  scanf("%d %d %d", &N, &M, &J);
  Grafo grafo = iniciar_grafo(N);

  for (i = 0; i < N; i++)
  {
    estarei[i] = 0;
    int A;
    scanf("%d", &A);

    while (A--)
    {
      int e;
      scanf("%d", &e);
      Grafo_Insert_Edge(grafo, EDGE(i, e));
    }
  }

  for (i = 0; i < M; i++)
  {
    int estou;
    scanf("%d", &estou);
    estarei[estou] = 1;

    Link a;

    for (a = grafo->adj[estou]; a != NULL; a = a->next)
    {
      estarei[a->value] = 1;
    }
  }

  for (i = 0; i < J; i++)
  {
    int num;
    scanf("%d", &num);

    if (estarei[num])
    {
      printf("Eu vou estar la\n");
    }
    else
    {
      printf("Nao vou estar la\n");
    }
  }

  return 0;
}