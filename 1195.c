#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void prefixo(No* raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->valor);
        prefixo(raiz->esq);
        prefixo(raiz->dir);
    }
}

void infixo(No* raiz) {
    if (raiz != NULL) {
        infixo(raiz->esq);
        printf(" %d", raiz->valor);
        infixo(raiz->dir);
    }
}

void posfixo(No* raiz) {
    if (raiz != NULL) {
        posfixo(raiz->esq);
        posfixo(raiz->dir);
        printf(" %d", raiz->valor);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int numCasos, numElementos, i, j, elemento;

    scanf("%d", &numCasos);

    for (i = 1; i <= numCasos; i++) {
        No* raiz = NULL;

        scanf("%d", &numElementos);

        for (j = 0; j < numElementos; j++) {
            scanf("%d", &elemento);
            raiz = inserir(raiz, elemento);
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        prefixo(raiz);
        printf("\n");
        printf("In..:");
        infixo(raiz);
        printf("\n");
        printf("Post:");
        posfixo(raiz);
        printf("\n\n");

        liberarArvore(raiz);
    }

    return 0;
}
