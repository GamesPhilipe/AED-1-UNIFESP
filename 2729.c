#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 1000
#define MAX_COMP 21

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char line[10001];
        fgets(line, sizeof(line), stdin);

        char *itens[MAX_ITENS];
        int item_count = 0;

        char *token = strtok(line, " \n");
        while (token != NULL) {
            itens[item_count++] = token;
            token = strtok(NULL, " \n");
        }

        qsort(itens, item_count, sizeof(char *), compare);

        printf("%s", itens[0]);
        for (int j = 1; j < item_count; j++) {
            if (strcmp(itens[j], itens[j - 1]) != 0) {
                printf(" %s", itens[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
