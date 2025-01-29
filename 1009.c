#include <stdio.h>

int main(){
	char nome[20];
	double fixo, vendas, total;
	
	scanf("%s", nome);
	scanf("%lf", &fixo);
	scanf("%lf", &vendas);
	
	total = 0.15*vendas + fixo;
	
	printf("TOTAL = R$ %.2lf\n", total);
}
