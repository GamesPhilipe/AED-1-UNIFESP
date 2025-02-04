#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        int pilha_ativa = 1, fila_ativa = 1, fila_prioridade_ativa = 1;
        int pilha_elementos[1000], fila_elementos[1000], fila_prio_elementos[1000];
        int topo_pilha_ativo = -1, frente_fila_ativa = 0, tras_fila_ativa = 0, tamanho_fila_prio = 0;

        for (int i = 0; i < t; i++) {
            int operacao;
            scanf("%d", &operacao);
            if (operacao == 1) {
                int valor;
                scanf("%d", &valor);
                if (pilha_ativa) pilha_elementos[++topo_pilha_ativo] = valor;
                if (fila_ativa) fila_elementos[tras_fila_ativa++] = valor;
                if (fila_prioridade_ativa) fila_prio_elementos[tamanho_fila_prio++] = valor;
            } else {
                int valor;
                scanf("%d", &valor);

                if (pilha_ativa) {
                    if (topo_pilha_ativo == -1 || pilha_elementos[topo_pilha_ativo] != valor) pilha_ativa = 0;
                    else topo_pilha_ativo--;
                }
                if (fila_ativa) {
                    if (frente_fila_ativa == tras_fila_ativa || fila_elementos[frente_fila_ativa] != valor) fila_ativa = 0;
                    else frente_fila_ativa++;
                }
                if (fila_prioridade_ativa) {
                    int max_valor = -1, indice_max_valor = -1;
                    for (int j = 0; j < tamanho_fila_prio; j++) {
                        if (fila_prio_elementos[j] > max_valor) {
                            max_valor = fila_prio_elementos[j];
                            indice_max_valor = j;
                        }
                    }
                    if (max_valor == -1 || max_valor != valor) fila_prioridade_ativa = 0;
                    else {
                        fila_prio_elementos[indice_max_valor] = fila_prio_elementos[--tamanho_fila_prio];
                    }
                }
            }
        }

        if (pilha_ativa + fila_ativa + fila_prioridade_ativa == 0) {
            printf("impossible\n");
        } else if (pilha_ativa + fila_ativa + fila_prioridade_ativa > 1) {
            printf("not sure\n");
        } else if (pilha_ativa) {
            printf("stack\n");
        } else if (fila_ativa) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }

    return 0;
}
