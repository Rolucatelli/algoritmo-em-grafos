#ifndef CLOSENESS_H
#define CLOSENESS_H

#include "lerGrafo.h"

/**
 * @brief Função que calcula o closeness de um vértice.
 * @param grafo Grafo a ser analisado.
 * @param vertice Vértice a ser analisado.
 * @return float.
 */
float closeness(Grafo *grafo, int vertice);

#endif // CLOSENESS_H