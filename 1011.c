#include <stdio.h>

int main(){
	double pi = 3.14159, r, vol;
	
	scanf("%lf", &r);
	
	vol = (4/3.0) * pi * (r*r*r);
	
	printf("VOLUME = %.3lf\n", vol);
}
