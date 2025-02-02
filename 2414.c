#include <stdio.h>

int main(){

    int n, maior;

    scanf("%d", &n);

    maior = n;

    while (n != 0){
        scanf("%d", &n);
        if (n > maior){
            maior = n;
        }
    }

    printf("%d\n", maior);

    return 0;
}
