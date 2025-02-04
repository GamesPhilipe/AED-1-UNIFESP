#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000
#define TAMANHO_MAXIMO 101010

int visitado[TAMANHO_MAXIMO];
int distancia[TAMANHO_MAXIMO];

typedef struct _no{

    int u, peso;
    struct _no *proximo;

} no_t;

typedef struct _grafo{

    no_t *adjacente;    

} grafo_t;

grafo_t * criar_grafo(int);
no_t * criar_no(int, int);
void dijkstra(grafo_t *, int, int);
void adicionar_aresta(grafo_t *, int, int, int);

int main(int argc, char **argv)
{    
    int i;
    int n, m, c, k, a, b, w;

    while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k))
    {    
        grafo_t *grafo = criar_grafo(n + 1);
        for (i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &w);
            if (a >= c && b >= c || ((a < c) && (b < c) && (abs(a - b) == 1))){
                adicionar_aresta(grafo, a, b, w), adicionar_aresta(grafo, b, a, w);
            }
            if (a >= c && b < c){
                adicionar_aresta(grafo, b, a, w);
            }
            if (b >= c && a < c){
                adicionar_aresta(grafo, a, b, w);
            }
        }

        dijkstra(grafo, k, n);
        printf("%d\n", distancia[c - 1]);
    }
    return 0;

}

void dijkstra(grafo_t *g, int origem, int __tamanho)
{
    no_t *k;
    int i, j, v;
    for (i = 0; i < __tamanho; ++i){
        distancia[i] = INF;
    }
    memset(visitado, false, sizeof(visitado));
    distancia[origem] = 0;
    for (i = 0; i < __tamanho; ++i)
    {
        v = -1;
        for (j = 0; j < __tamanho; ++j){
            if (!visitado[j] && (v == -1 || distancia[j] < distancia[v])){
                v = j;
            }
        }

        if (distancia[v] == INF)
            break;

        visitado[v] = true;

        for (k = g->adjacente[v].proximo; k != NULL; k = k->proximo)
        {
            int destino = k->u;
            int comprimento = k->peso;
            if (distancia[v] + comprimento < distancia[destino])
                distancia[destino] = distancia[v] + comprimento;
        }
    }
}

grafo_t * criar_grafo(int __tamanho)
{
    int i;
    grafo_t *g = (grafo_t *) malloc(sizeof(grafo_t));
    g->adjacente = (no_t *) malloc(sizeof(no_t) * (__tamanho + 1));

    for (i = 0; i < __tamanho; ++i)
        g->adjacente[i].proximo = NULL;

    return g;
}

no_t * criar_no(int u, int peso)
{
    no_t *novo_no = (no_t *) malloc(sizeof(no_t));
    novo_no->u = u;
    novo_no->peso = peso;
    novo_no->proximo = NULL;
    return novo_no;
}

void adicionar_aresta(grafo_t *g, int u, int v, int peso)
{
    no_t *novo_no = criar_no(u, peso);
    novo_no->proximo = g->adjacente[v].proximo;
    g->adjacente[v].proximo = novo_no;
}
