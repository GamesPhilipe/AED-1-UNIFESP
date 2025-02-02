#include <stdio.h>

int main(){
	float A, B, C, result;
	
	scanf("%f %f %f", &A, &B, &C);
	
	if(A<B+C && B<A+C && C<A+B){
		result = A + B + C;
		printf("Perimetro = %.1f\n", result);
	}
	else{
		result = ((A+B)*C) / 2;
		printf("Area = %.1f\n", result);
	}
}
