//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Victor Franklin Matias Silva
// Matricula : vou ver
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Caroline de Albuquerque Arrais
// Matricula : vejam ai
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : vejam ai
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Lanai Giani Lima Oliveira
// Matricula : 20231045050351
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Kalebe Ribeiro Sousa
// Matricula : vejam ai
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : vejam ai
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pgm/pgm.h"

 
int main(int argc, char *argv[]){

    struct pgm img;

    if ((argc<2)){
        printf("Formato: \nPara ler imagens isoladas:\n\t %s <1> <imagemEntrada.pgm> <imagemSaida.pgm> \nPara ler um diretório:\n\t %s <2> <nomeDiretorio>\n",argv[0],argv[0]);
		exit(1);
    }

    int operacao = atoi(argv[1]);

	if ((operacao==1) && (argc!=4)){
		printf("Formato: \n\t %s <1> <imagemEntrada.pgm> <imagemSaida.pgm>\n",argv[0]);
		exit(1);
	}

    if ((operacao==2) && (argc!=3)){
		printf("Formato: \n\t %s <2> <nomeDiretorio>\n",argv[0]);
		exit(1);
	}

    // Inicio da medição do tempo
    DIR *d;
    struct dirent *dir;
    d = opendir("./images");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            

            printf("%s\n", dir->d_name);

						// Leitura da Imagem -PGM

						
						
						// Saída.

             
        }
        closedir(d);
    }
    // Fim da medição do tempo           
    return(0);
}
