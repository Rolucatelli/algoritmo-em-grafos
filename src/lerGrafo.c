#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo_
{
    int tamanho;
    int **matriz;
} Grafo;

Grafo *lerGrafo(FILE *file)
{
    int tamanho;
    fscanf(file, "%d", &tamanho);
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->tamanho = tamanho;
    grafo->matriz = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++)
    {
        grafo->matriz[i] = (int *)malloc(tamanho * sizeof(int));
        for (int j = 0; j < tamanho; j++)
        {
            fscanf(file, "%d", &grafo->matriz[i][j]);
        }
    }

    fclose(file);
    return grafo;
}

void printGrafo(Grafo *grafo)
{
    for (int i = 0; i < grafo->tamanho; i++)
    {
        for (int j = 0; j < grafo->tamanho; j++)
        {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
}

int numeroAdjacentes(Grafo *grafo, int v)
{
    int retorno = 0;
    for (int i = 0; i < grafo->tamanho; i++)
    {
        if (grafo->matriz[v][i])
        {
            retorno++;
        }
    }
    return retorno;
}

int *adjacentes(Grafo *grafo, int v)
{
    int *retorno = (int *)malloc(numeroAdjacentes(grafo, v) * sizeof(int));
    int j = 0;
    for (int i = 0; i < grafo->tamanho; i++)
    {
        if (grafo->matriz[v][i])
        {
            retorno[j] = i;
            j++;
        }
    }
    return retorno;
}