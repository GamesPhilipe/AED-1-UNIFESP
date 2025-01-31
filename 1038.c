#include <stdio.h>

int main(){
	int cod, qtd;
	float total;
	
	scanf("%d %d", &cod, &qtd);
	
	if(cod == 1){
		total = 4 * qtd;
	}
	else if(cod == 2){
		total = 4.5 * qtd;
	}
	else if(cod == 3){
		total = 5 * qtd;
	}
	else if(cod == 4){
		total = 2 * qtd;
	}
	else if(cod == 5){
		total = 1.5 * qtd;
	}
	
	printf("Total: R$ %.2f\n", total);
}
