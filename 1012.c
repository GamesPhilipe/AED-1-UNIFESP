#include <stdio.h>

int main(){
	double A, B, C, triangulo, circulo, trapezio, quadrado, retangulo, pi = 3.14159;
	
	scanf("%lf %lf %lf", &A, &B, &C);
	
	triangulo = (A * C) / 2;
	circulo = pi * (C * C);
	trapezio = ((A + B) * C) / 2;
	quadrado = B * B;
	retangulo = A * B;
	
	printf("TRIANGULO: %.3lf\n", triangulo);
	printf("CIRCULO: %.3lf\n", circulo);
	printf("TRAPEZIO: %.3lf\n", trapezio);
	printf("QUADRADO: %.3lf\n", quadrado);
	printf("RETANGULO: %.3lf\n", retangulo);
}
