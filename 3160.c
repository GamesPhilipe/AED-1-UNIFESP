#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 20

void adicionar_amigo(char ***lista, int *total, const char *nome) {
    *lista = realloc(*lista, (*total + 1) * sizeof(char *));
    (*lista)[*total] = malloc((strlen(nome) + 1) * sizeof(char)); 
    strcpy((*lista)[*total], nome);
    (*total)++;
}


void liberar_lista(char **lista, int total) {
    for (int i = 0; i < total; i++) {
        free(lista[i]); 
    }
    free(lista); 
}

int main() {
    char **lista_atual = NULL; 
    char **nova_lista = NULL; 
    char nome_indicacao[TAM_NOME];
    int total_atual = 0, total_nova = 0;

    char linha[200];
    fgets(linha, sizeof(linha), stdin);
    char *token = strtok(linha, " \n");
    while (token != NULL) {
        adicionar_amigo(&lista_atual, &total_atual, token);
        token = strtok(NULL, " \n");
    }


    fgets(linha, sizeof(linha), stdin);
    token = strtok(linha, " \n");
    while (token != NULL) {
        adicionar_amigo(&nova_lista, &total_nova, token);
        token = strtok(NULL, " \n");
    }

    fgets(nome_indicacao, sizeof(nome_indicacao), stdin);
    nome_indicacao[strcspn(nome_indicacao, "\n")] = 0; 


    if (strcmp(nome_indicacao, "nao") == 0) {
        for (int i = 0; i < total_nova; i++) {
            adicionar_amigo(&lista_atual, &total_atual, nova_lista[i]);
        }
    } else {

        int posicao_indicacao = -1;
        for (int i = 0; i < total_atual; i++) {
            if (strcmp(lista_atual[i], nome_indicacao) == 0) {
                posicao_indicacao = i;
                break;
            }
        }


        if (posicao_indicacao != -1) {
  
            lista_atual = realloc(lista_atual, (total_atual + total_nova) * sizeof(char *));
            

            for (int i = total_atual - 1; i >= posicao_indicacao; i--) {
                lista_atual[i + total_nova] = lista_atual[i];
            }


            for (int i = 0; i < total_nova; i++) {
                lista_atual[posicao_indicacao + i] = malloc((strlen(nova_lista[i]) + 1) * sizeof(char));
                strcpy(lista_atual[posicao_indicacao + i], nova_lista[i]);
            }
            total_atual += total_nova;
        } else {

            for (int i = 0; i < total_nova; i++) {
                adicionar_amigo(&lista_atual, &total_atual, nova_lista[i]);
            }
        }
    }


    for (int i = 0; i < total_atual; i++) {
        printf("%s", lista_atual[i]);
        if (i < total_atual - 1) printf(" ");
    }
    printf("\n");

    liberar_lista(lista_atual, total_atual);
    liberar_lista(nova_lista, total_nova);

    return 0;
}
