#ifndef LERGRAFO_H
#define LERGRAFO_H

typedef struct grafo_
{
    int tamanho;
    int **matriz;
} Grafo;

/**
 * @brief Função que lê o grafo de um arquivo.
 * @param file Arquivo a ser lido.
 * @return Grafo*.
 */
Grafo *lerGrafo(FILE *file);

/**
 * @brief Função que imprime o grafo.
 * @param grafo Grafo a ser impresso.
 * @return void.
 */
void printGrafo(Grafo *grafo);

/**
 * @brief Função que retorna o número de vértices adjacentes a um vértice.
 * @param grafo Grafo a ser analisado.
 * @param v Vértice a ser analisado.
 * @return int.
 */
int numeroAdjacentes(Grafo *grafo, int v);

/**
 * @brief Função que retorna os vértices adjacentes a um vértice.
 * @param grafo Grafo a ser analisado.
 * @param v Vértice a ser analisado.
 * @return int*.
 */
int *adjacentes(Grafo *grafo, int v);

#endif // LERGRAFO_H