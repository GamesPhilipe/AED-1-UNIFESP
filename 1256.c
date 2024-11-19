#include <stdio.h>
#include <stdlib.h>

struct No {
    int chave;
    struct No* proximo;
};

struct No* criarNo(int chave) {
    struct No* novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->chave = chave;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirChave(struct No** tabela, int tamanhoTabela, int chave) {
    int indice = chave % tamanhoTabela;
    struct No* novoNo = criarNo(chave);

    if (tabela[indice] == NULL) {
        tabela[indice] = novoNo;
    } else {
        struct No* atual = tabela[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void imprimirTabelaHash(struct No** tabela, int tamanhoTabela) {
    for (int i = 0; i < tamanhoTabela; i++) {
        printf("%d -> ", i);
        struct No* atual = tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("\\\n");
    }
}

int main() {
    int numCasosTeste;
    scanf("%d", &numCasosTeste);

    while (numCasosTeste--) {
        int tamanhoTabela, numChaves;
        scanf("%d %d", &tamanhoTabela, &numChaves);

        struct No** tabela = (struct No**) malloc(tamanhoTabela * sizeof(struct No*));
        for (int i = 0; i < tamanhoTabela; i++) {
            tabela[i] = NULL;
        }

        for (int i = 0; i < numChaves; i++) {
            int chave;
            scanf("%d", &chave);
            inserirChave(tabela, tamanhoTabela, chave);
        }

        imprimirTabelaHash(tabela, tamanhoTabela);
        if(numCasosTeste != 0){
            printf("\n");
        }

        // Liberar memória
        for (int i = 0; i < tamanhoTabela; i++) {
            struct No* atual = tabela[i];
            while (atual != NULL) {
                struct No* temp = atual;
                atual = atual->proximo;
                free(temp);
            }
        }
        free(tabela);
    }

    return 0;
}
