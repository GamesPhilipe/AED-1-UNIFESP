#include <stdio.h>

int main(){
	double A, B, M;
	
	scanf("%lf", &A);
	scanf("%lf", &B);
	
	M = (3.5*A + 7.5*B) / 11;
	
	printf("MEDIA = %.5lf\n", M);
}
