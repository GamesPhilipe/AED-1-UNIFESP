#include <stdio.h>
#include <string.h>

int verifica_parenteses(const char *expressao) {
    int contador = 0;
    
    for (int i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') {
            contador++;
        } else if (expressao[i] == ')') {
            if (contador == 0) {
                return 0;
            }
            contador--;
        }
    }
    

    return contador == 0;
}

int main() {
    int N = 100;
    char expressoes[N][1001];
    
    for (int i = 0; i < N; i++) {
        printf("Digite a expressao %d: ", i + 1);
        scanf("%999s", expressoes[i]); 
        if (verifica_parenteses(expressoes[i])) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
