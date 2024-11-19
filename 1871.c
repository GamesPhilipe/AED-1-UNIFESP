#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int p = 0;
    int A = 0, B = 0, N = 0, j = 0, h = 0;
    char text[100];
    char aux[100];
    while(p == 0){
        scanf("%d%d", &A,&B);
        if((A == 0) && (B == 0)){
            return 0;
        }
        if((A >= 1) && (B >= 1)){
            N = A+B;
            sprintf(text, "%d", N);
            for(int i = 0; i < 10; i++){
                if((text[i] > 48) && (text[i] < 58)){
                    aux[j] = text[i];
                    j++;
                }
            }
        }
        h = atoi(aux);
        printf("%d\n", h);
        A = 0;
        B = 0;
        N = 0;
        j = 0;
        h = 0;
        for(int k = 0; k <= 100; k++){
            text[k] = 0;
            aux[k] = 0;
        }
    }
}
