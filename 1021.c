
#include <stdio.h>

int main(){
	float N;
	int n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, m1=0, m050=0, m025=0, m010=0, m005=0, m001=0;
	
	scanf("%f", &N);
	N += 0.001;
	
	printf("NOTAS:\n");
	if(N >= 100){
		n100 = N / 100;
		N -= n100 * 100;
	}
	printf("%d nota(s) de R$ 100.00\n", n100);
	if(N >= 50){
		n50 = N / 50;
		N -= n50 * 50;
	}
	printf("%d nota(s) de R$ 50.00\n", n50);
	if(N >= 20){
		n20 = N / 20;
		N -= n20 * 20;
	}
	printf("%d nota(s) de R$ 20.00\n", n20);
	if(N >= 10){
		n10 = N / 10;
		N -= n10 * 10;
	}
	printf("%d nota(s) de R$ 10.00\n", n10);
	if(N >= 5){
		n5 = N / 5;
		N -= n5 * 5;
	}
	printf("%d nota(s) de R$ 5.00\n", n5);
	if(N >= 2){
		n2 = N / 2;
		N -= n2 * 2;
	}
	printf("%d nota(s) de R$ 2.00\n", n2);
	
	printf("MOEDAS:\n");
	if(N >= 1){
		m1 = N / 1;
		N -= m1;
	}
	printf("%d moeda(s) de R$ 1.00\n", m1);
	if(N >= 0.50){
		m050 = N / 0.50;
		N -= m050 * 0.50;
	}
	printf("%d moeda(s) de R$ 0.50\n", m050);
	if(N >= 0.25){
		m025 = N / 0.25;
		N -= m025 * 0.25;
	}
	printf("%d moeda(s) de R$ 0.25\n", m025);
	if(N >= 0.10){
		m010 = N / 0.10;
		N -= m010 * 0.10;
	}
	printf("%d moeda(s) de R$ 0.10\n", m010);
	if(N >= 0.05){
		m005 = N / 0.05;
		N -= m005 * 0.05;
	}
	printf("%d moeda(s) de R$ 0.05\n", m005);
	m001 = N / 0.01;
	printf("%d moeda(s) de R$ 0.01\n", m001);
}
