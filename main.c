#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include "pgm/pgm.h"
#include "k-means/k-means.h"

int main(int argc, char *argv[]){
    DIR *d;
    int qtdimg = 0;
    struct dirent *dir;
    struct pgm img;

    if (argc != 4) {
        printf("Formato: \n\t %s <Valor de K (2 a 255)> <imagemEntrada.pgm> <imagemSaida.pgm>\nExemplo:\n\t %s 3 entrada.pmg saida.pgm\n", argv[0],argv[0]);
        exit(1);
    }

    unsigned char k = atoi(argv[1]);

    if (k<=1){
        puts("Digite um valor de K dentro da faixa 2-255.");
        exit(2);
    }

    readPGMImage(&img,argv[2]);
    Kmeans(&img,k);
    writePGMImage(&img,argv[3]);

    return 0;
}