#include <stdio.h>
#include <stdlib.h>
#include "./../hdr/lerGrafo.h"

void inicializa(Grafo *grafo, int s, int *d, int *pi)
{

    for (int i = 0; i < grafo->tamanho; i++)
    {
        d[i] = 999999;
        pi[i] = -1;
    }

    d[s] = 0;
}

void relaxa(int u, int v, int w, int *d, int *pi)
{

    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
    }
}

int vazio(int *q, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (q[i] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int extrairMinimo(int tam, int *q, int *d)
{
    int menor = 999999;
    int posMenor = -1;
    
    for (int i = 0; i < tam; i++)
    {
        if (d[i] < menor && q[i] == 1)
        {
            menor = d[i];
            posMenor = i;
        }
        
    }
    q[posMenor] = 0;
    return posMenor;
}

int* dijkstra(Grafo *grafo, int vInicial)
{
    int *d = (int *)malloc(grafo->tamanho * sizeof(int));
    int *pi = (int *)malloc(grafo->tamanho * sizeof(int));
    int *s = (int *)malloc(grafo->tamanho * sizeof(int));
    int *q = (int *)malloc(grafo->tamanho * sizeof(int));

    int u, v, w;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    inicializa(grafo, vInicial, d, pi);

    for (int i = 0; i < grafo->tamanho; i++)
    {
        s[i] = 0; // S <- {}
        q[i] = 1; // Q <- V
    }

    while (!vazio(q, grafo->tamanho)) // Enquanto |Q| != 0
    {
        u = extrairMinimo(grafo->tamanho,q,d);  // u <- extrair Minimo(Q)
        s[u] = 1;   // S <- S U {u}
        


        int nAdj = numeroAdjacentes(grafo, u);
        int *adj = adjacentes(grafo, u);
        for (int i = 0; i < nAdj; i++)  // para cada v pertencente à Adj[u]
        {
            v = adj[i];
            relaxa(u,v,grafo->matriz[u][v],d,pi);   // relaxa(u,v,w)
        }
        
    }

    free(pi);
    free(s);
    free(q);
    return d;
}