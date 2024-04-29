#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "lerGrafo.h"
/**
 * @brief Função que inicializa o vetor de distâncias e o vetor de visitados.
 * @param grafo Grafo a ser inicializado.
 * @param s Vértice de origem.
 * @param d Vetor de distâncias.
 * @param pi Vetor de visitados.
 * @return void.
*/
void inicializa(Grafo* grafo, int s, int* d, int* pi);
/**
 * @brief Função que relaxa as arestas do grafo.
 * @param u Vértice de origem.
 * @param v Vértice de destino.
 * @param w Peso da aresta.
 * @param d Vetor de distâncias.
 * @param pi Vetor de visitados.
 * @return void.
 */
void relaxa(int u, int v, int w, int* d, int* pi);

int vazio(int *q, int tam);

int extrairMinimo(int tam, int *q, int *d);
/**
 * @brief Função que executa o algoritmo de Dijkstra.
 * @param grafo Grafo a ser analisado.
 * @return void.
 */
int* dijkstra(Grafo* grafo, int vInicial);


#endif // DIJKSTRA_H