#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../hdr/lerGrafo.h"
#include "./../hdr/dijkstra.h"
#include "./../hdr/closeness.h"


int main()
{
    system("clear");
    int escolha;
    Grafo *grafo = NULL;
    char nomeArquivo[100];
    char caminho[18] = "./exe/grafos/";
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    strcat(caminho, nomeArquivo);
    FILE *file = fopen(caminho, "r");
    strcpy(caminho, "./exe/grafos/");

    while (!file)
    {
        printf("Arquivo não encontrado. Digite o nome do arquivo novamente (com a extensão do tipo): ");
        scanf("%s", nomeArquivo);
        strcat(caminho, nomeArquivo);
        file = fopen(caminho, "r");
        strcpy(caminho, "./exe/grafos/");
    }
    grafo = lerGrafo(file);
    system("clear");
    do
    {

        printf("Escolha uma opção:\n");
        printf("0 - Sair\n");
        printf("1 - Ler outro grafo\n");
        printf("2 - Calcular closeness\n");
        printf("3 - Calcular caminho mínimo\n");
        printf("4 - Imprimir grafo\n");
        printf("5 - Calcular o closeness de todos os vértices\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            system("clear");
            printf("Digite o nome do arquivo: ");
            scanf("%s", nomeArquivo);
            strcat(caminho, nomeArquivo);
            FILE *file = fopen(caminho, "r");
            strcpy(caminho, "./exe/grafos/");
            while (!file)
            {
                printf("Arquivo não encontrado. Digite o nome do arquivo novamente (com a extensão do tipo): ");
                scanf("%s", nomeArquivo);
                strcat(caminho, nomeArquivo);
                file = fopen(caminho, "r");
                strcpy(caminho, "./exe/grafos/");
            }
            grafo = lerGrafo(file);
            break;
        case 2:
            system("clear");
            int verticeCloseness = 0;
            printGrafo(grafo);
            printf("\nEscolha o vértice: ");
            scanf("%d", &verticeCloseness);
            float c = closeness(grafo, verticeCloseness);
            printf("Closeness do vértice %d: %f\n", verticeCloseness, c);
            break;
        case 3:
            system("clear");
            int vertice = 0;
            printGrafo(grafo);
            printf("\nEscolha o vértice: ");
            scanf("%d", &vertice);
            int *d = dijkstra(grafo, vertice);
            for (int i = 0; i < grafo->tamanho; i++)
            {
                printf("Distância de %d para %d: %d\n", vertice, i, d[i]);
            }
            break;
        case 4:
            system("clear");
            system("python3 py/draw_graphs.py");
            printf("\n");
            break;
        case 5:
            system("clear");
            char path[20] = "./exe/output/";
            char *temp = strcat(path, nomeArquivo);
            printf("Salvando closeness em %s\n", temp);
            FILE *output = fopen(temp, "w");
            strcpy(path, "./exe/output/");
            for (int i = 0; i < grafo->tamanho; i++)
            {
                float c = closeness(grafo, i);
                fprintf(output, "%f\n", c);
            }
            fclose(output);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}