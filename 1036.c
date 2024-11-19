#include <stdio.h>
#include <math.h>
int main(){
    double A, B, C, resu1, resu2, delta, raiz;
    scanf("%lf%lf%lf", &A, &B, &C);
    if(A > 0){
        delta= ((B*B)-(4*A*C));
        if(delta >= 0){
            raiz = sqrt(delta);
            resu1 = ((-B+raiz)/(2*A));
            resu2 = ((-B-raiz)/(2*A));
            printf("R1 = %.5lf\n", resu1);
            printf("R2 = %.5lf\n", resu2);
            return 0;
        
        }else{
            printf("Impossivel calcular\n");
            return 0;
        }
    }else{
        printf("Impossivel calcular\n");
        return 0;
    }
}
