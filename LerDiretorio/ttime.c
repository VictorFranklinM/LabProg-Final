#include <stdio.h>
#include <time.h>


void tempo(){
	int k;
	int qtdimg;
	clock_t begin, end;
	double time_per_img, time_total=0;
	long long int a = 999999999;

	begin = clock();

	for (k=0; k<qtdimg; k++){

		// Leitura

		
		while(a){
			a--;
		}

		

	}

	end = clock();

	time_total = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Tempo Total: %lf\n",time_total);
	return 0;

}