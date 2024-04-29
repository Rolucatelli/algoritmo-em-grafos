#include <stdio.h>
#include <stdlib.h>

#include "./../hdr/lerGrafo.h"
#include "./../hdr/dijkstra.h"

float closeness(Grafo *grafo, int vertice)
{
    float soma = 0;
    int* d = dijkstra(grafo, vertice);
    for (int i = 0; i < grafo->tamanho-1; i++)
    {
        soma += (float)d[i];
    }
    soma = soma / (grafo->tamanho - 1);
    return soma;
}