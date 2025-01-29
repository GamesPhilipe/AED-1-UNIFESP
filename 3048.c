#include <stdio.h>

int main(){
    int N, i, j, atual, cons = 0;

    scanf("%d", &N);
    int seq[N];

    for(i = 0; i < N; i++)
        scanf("%d", &seq[i]);

    atual = seq[0];
    i = 1;
    while(i < N){
        if(atual == 1){
            for(j = i; j < N; j++){
                if(seq[j] == 2)
                    break;
            }
            i = j;
            atual = 2;
        }else{
            for(j = i; j < N; j++){
                if(seq[j] == 1)
                    break;
            }
            i = j;
            atual = 1;
        }
        cons++;
    }
    printf("%d\n", cons);

    return 0;
}
