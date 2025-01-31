#include <stdio.h>

int main(){
	int valor, n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, n1=0;
	
	scanf("%d", &valor);
	printf("%d\n", valor);
	
	if(valor >= 100){
		n100 = valor / 100;
		valor -= n100 * 100;
	}
	printf("%d nota(s) de R$ 100,00\n", n100);
	if(valor >= 50){
		n50 = valor / 50;
		valor -= n50 * 50;
	}
	printf("%d nota(s) de R$ 50,00\n", n50);
	if(valor >= 20){
		n20 = valor / 20;
		valor -= n20 * 20;
	}
	printf("%d nota(s) de R$ 20,00\n", n20);
	if(valor >= 10){
		n10 = valor / 10;
		valor -= n10 * 10;
	}
	printf("%d nota(s) de R$ 10,00\n", n10);
	if(valor >= 5){
		n5 = valor / 5;
		valor -= n5 * 5;
	}
	printf("%d nota(s) de R$ 5,00\n", n5);
	if(valor >= 2){
		n2 = valor / 2;
		valor -= n2 * 2;
	}
	printf("%d nota(s) de R$ 2,00\n", n2);
	n1 = valor;
	printf("%d nota(s) de R$ 1,00\n", n1);
}
