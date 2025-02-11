//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Victor Franklin Matias Silva
// Matricula : 20241045050170
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Caroline de Albuquerque Arrais
// Matricula : 20241045050260
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
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
// Matricula : 20241045050421
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include "pgm/pgm.h"
#include "k-means/k-means.h"
#include "pgm-histogram/histogram.h"

int main(int argc, char *argv[]) {
	DIR *d;
	clock_t begin, end;

	struct dirent *dir;
	struct pgm img;
	struct stat file_stat;

	int qtdimg = 0;
	double time_per_img, time_total = 0;

	if (argc != 2) {
		printf("Formato: \n\t %s <Valor de K (1 a 255)>\n", argv[0]);
		exit(1);
	}

	if ((atoi(argv[1])) < 1) {
		puts("Digite um valor de K dentro da faixa 1-255.");
		exit(2);
	}

	unsigned char k = atoi(argv[1]);

	begin = clock();

	d = opendir("./images");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			char full_path[200];
			snprintf(full_path, sizeof(full_path), "images/%s", dir->d_name);

			if ((dir->d_name[0] == '.') || (strcmp(dir->d_name, "results") == 0) || (strcmp(dir->d_name, "histogram") == 0) || (stat(full_path, &file_stat) == 0 && S_ISDIR(file_stat.st_mode))) {
                		continue;
            		} // Ignora arquivos ocultos, o diretório results, o diretório histogram e quaisquer outras pastas dentro de images.

			qtdimg++;  //Incrementa o contador.
			
			readPGMImage(&img, full_path);  // Verifica se a leitura da imagem falhou.
			if (img.pData == NULL) {
				printf("Erro ao carregar imagem: %s\n", full_path);
				continue;  // Pula para a próxima iteração do loop, ignorando esta imagem.
			}
			
			// Copia o nome do arquivo e remove a extensão '.pgm' para utilizar no nome dos arquivos gerados.
			char name_no_ext[100];
			snprintf(name_no_ext, sizeof(name_no_ext), "%s", dir->d_name);
			char *ext = strrchr(name_no_ext, '.');
			if (ext != NULL && strcmp(ext, ".pgm") == 0) {  // Verifica se é '.pgm' antes de remover a extensão;
				*ext = '\0';  // Caso for, troca o '.' da extensão por '\0' para marcar o fim da string.
			}

			// Gera histograma da imagem original.
			char basePath[100];
			snprintf(basePath, sizeof(basePath), "images/histogram/%s_original", name_no_ext);
			generateHistogram(img.pData, img.r, img.c, basePath);

			// Aplica K-means e captura a imagem antes da normalização.
			unsigned char *pre_normalized_output = (unsigned char *)malloc(img.r * img.c * sizeof(unsigned char));
			if (!pre_normalized_output) {
				puts("Erro ao alocar memória para pre_normalized_output.");
				exit(3);
			}
			K_means(k, img.r, img.c, img.pData, name_no_ext, pre_normalized_output);

			// Gera histograma da imagem processada mas antes da normalização equidistante.
			snprintf(basePath, sizeof(basePath), "images/histogram/%s_before_norm", name_no_ext);
			generateHistogram(pre_normalized_output, img.r, img.c, basePath);

			// Gera histograma da imagem normalizada.
			snprintf(basePath, sizeof(basePath), "images/histogram/%s_after", name_no_ext);
			generateHistogram(img.pData, img.r, img.c, basePath);

			// Salva a imagem segmentada final.
			char folder_result[100];
			snprintf(folder_result, sizeof(folder_result), "images/results/%s_k.pgm", name_no_ext);
			writePGMImage(&img, folder_result);

			// Libera memória alocada.
			free(pre_normalized_output);
			free(img.pData);
		}
		closedir(d);
	}

	end = clock();

	time_total = (double)(end - begin) / CLOCKS_PER_SEC;
	time_per_img = qtdimg > 0 ? time_total / qtdimg : 0; // '> 0' para evitar a possibilidade de divisão por 0.

	printf("Tempo Total: %lf\n", time_total);
	printf("Tempo por Imagem: %lf\n", time_per_img);

	return 0;
}
