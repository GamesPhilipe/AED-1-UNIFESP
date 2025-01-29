#include <stdio.h>

int main(){
	double A, B, C, M;
	
	scanf("%lf", &A);
	scanf("%lf", &B);
	scanf("%lf", &C);
	
	M = (2*A + 3*B + 5*C) / 10;
	
	printf("MEDIA = %.1lf\n", M);
}
