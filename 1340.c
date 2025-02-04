#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int pilha = 1, fila = 1, fila_prioridade = 1;
        int pilha_elem[1000], fila_elem[1000], fila_prio_elem[1000];
        int topo_pilha = -1, frente_fila = 0, tras_fila = 0, tam_fila_prio = 0;

        for (int i = 0; i < n; i++) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int x;
                scanf("%d", &x);
                if (pilha) pilha_elem[++topo_pilha] = x;
                if (fila) fila_elem[tras_fila++] = x;
                if (fila_prioridade) fila_prio_elem[tam_fila_prio++] = x;
            } else {
                int x;
                scanf("%d", &x);

                if (pilha) {
                    if (topo_pilha == -1 || pilha_elem[topo_pilha] != x) pilha = 0;
                    else topo_pilha--;
                }
                if (fila) {
                    if (frente_fila == tras_fila || fila_elem[frente_fila] != x) fila = 0;
                    else frente_fila++;
                }
                if (fila_prioridade) {
                    int max = -1, idx_max = -1;
                    for (int j = 0; j < tam_fila_prio; j++) {
                        if (fila_prio_elem[j] > max) {
                            max = fila_prio_elem[j];
                            idx_max = j;
                        }
                    }
                    if (max == -1 || max != x) fila_prioridade = 0;
                    else {
                        fila_prio_elem[idx_max] = fila_prio_elem[--tam_fila_prio];
                    }
                }
            }
        }

        if (pilha + fila + fila_prioridade == 0) {
            printf("impossible\n");
        } else if (pilha + fila + fila_prioridade > 1) {
            printf("not sure\n");
        } else if (pilha) {
            printf("stack\n");
        } else if (fila) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }

    return 0;
}
