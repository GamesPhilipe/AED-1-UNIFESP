#include <stdio.h>

int main(){
	int tempo, velocidade_m;
	float distancia, litros;
	
	scanf("%d", &tempo);
	scanf("%d", &velocidade_m);
	
	distancia = tempo * velocidade_m;
	litros = distancia / 12;
	
	printf("%.3f\n", litros);
}
