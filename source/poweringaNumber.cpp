#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float power(float num, float powerr){
	if( (fmodf(powerr,2)) == 0){
		if(powerr == 0){		
			return 1;
		}
		else if(powerr == 2){
			return num * num;
		}
		else{
			return power(num,powerr/2) * power(num,powerr/2);	
		}
	}
	else{
		if(powerr == 1){
			printf("masuk satu\n");
			return num;
		}
		else{
			return power(num,(powerr-1)/2) * power(num,(powerr-1)/2) * num;
		}
	}
}

int main(int argc, char * argv[])
{
	float angka, pangkat;
	scanf("%f %f", &angka, &pangkat);
	float hasil = power(angka,pangkat);
	printf("%f", hasil);
	return 0;
}
