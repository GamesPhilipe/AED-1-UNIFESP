#include <stdio.h>
#include <math.h>
int main(){
    int N, i;
    scanf("%d", &N);
    char stringP[50];
    
    while(N > 0){
        scanf("%s", stringP);
        scanf("%d", &i );
        for(int j = 0; j < 50; j++){
            if(stringP[j] != 0){
                for(int h = 0; h < i; h++){
                    if(stringP[j] - 1 < 65){
                        stringP[j] = 91;
                    }
                    stringP[j] = stringP[j] - 1;
                }
            }
        }
        printf("%s\n", stringP);
        N--;
    }
    
}
