#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "lerGrafo.h"
/**
 * @brief Função que inicializa o vetor de distâncias e o vetor dos pais.
 * @param grafo Grafo a ser inicializado.
 * @param s Vértice de origem.
 * @param d Vetor de distâncias.
 * @param pi Vetor dos pais.
 * @return void.
 */
void inicializa(Grafo *grafo, int s, int *d, int *pi);
/**
 * @brief Função que relaxa as arestas do grafo.
 * @param u Vértice de origem.
 * @param v Vértice de destino.
 * @param w Peso da aresta.
 * @param d Vetor de distâncias.
 * @param pi Vetor dos pais.
 * @return void.
 */
void relaxa(int u, int v, int w, int *d, int *pi);

/**
 * @brief Função que verifica se o vetor de visitados está vazio.
 * @param q Vetor de visitados.
 * @param tam Tamanho do vetor.
 * @return int.
 */
int vazio(int *q, int tam);

/**
 * @brief Função que extrai o vértice com menor distância.
 * @param tam Tamanho do vetor.
 * @param q Vetor de visitados.
 * @param d Vetor de distâncias.
 * @return int.
 */
int extrairMinimo(int tam, int *q, int *d);

/**
 * @brief Função que executa o algoritmo de Dijkstra.
 * @param grafo Grafo a ser analisado.
 * @param vInicial Vértice de origem.
 * @return int*.
 */
int *dijkstra(Grafo *grafo, int vInicial);

#endif // DIJKSTRA_H