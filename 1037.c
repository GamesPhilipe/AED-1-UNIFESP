#include <stdio.h>

int main(){
	float num;
	
	scanf("%f", &num);
	
	if(0<=num && num<=25){
		printf("Intervalo [0,25]\n");
	}
	else if(25<num && num<=50){
		printf("Intervalo (25,50]\n");
	}
	else if(50<num && num<=75){
		printf("Intervalo (50,75]\n");
	}
	else if(75<num && num<=100){
		printf("Intervalo (75,100]\n");
	}
	else{
		printf("Fora de intervalo\n");
	}
}
