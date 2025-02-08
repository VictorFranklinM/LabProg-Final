#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct histogram {
	int data[256];
	int max_freq;
};

void generateHistogram(unsigned char *data, int linhas, int colunas, const char *basePath) {
	struct histogram *hist = (struct histogram *)calloc(1, sizeof(struct histogram));
	if (!hist) {
		puts("Erro ao alocar memória para o histograma.");
		exit(1);
	}

	/* Conta a frequência de cada tom de cinza. A max_freq armazena a frequência máxima encontrada. Varre todos os pixels da imagem
        incrementando a contagem do tom de cinza atual e gravando em max_freq caso passe.*/
    for (int i = 0; i < linhas * colunas; i++) {
		hist->data[data[i]]++;
		if (hist->data[data[i]] > hist->max_freq) {
			hist->max_freq = hist->data[data[i]];
		}
	}

	// Cria os caminhos dos arquivos CSV e PGM.
	char *outputCSV = (char *)malloc(60 * sizeof(char));
	char *outputPGM = (char *)malloc(60 * sizeof(char));
	if (!(outputCSV && outputPGM)) {
		puts("Erro ao alocar memória para os nomes dos arquivos.");
		exit(1);
	}

	snprintf(outputCSV, 60, "%s.csv", basePath);
	snprintf(outputPGM, 60, "%s.pgm", basePath);

	// Salva o histograma em CSV
	FILE *fp = fopen(outputCSV, "w");
	if (!fp) {
		puts("Erro ao abrir o arquivo CSV.");
		exit(2);
	}
	fprintf(fp, "Tom de Cinza, Frequência\n");
	for (int i = 0; i < 256; i++) {
		fprintf(fp, "%d, %d\n", i, hist->data[i]);
	}
	fclose(fp);

	// Cria a imagem PGM do histograma
	int altura = 256;
	int largura = 256;
	unsigned char *histImg = (unsigned char *)calloc(largura * altura, sizeof(unsigned char));
	if (!histImg) {
		puts("Erro ao alocar memória para a imagem do histograma.");
		exit(1);
	}

	// Preenche a imagem com o histograma de baixo para cima para subir as colunas.
	for (int i = 0; i < 256; i++) {
		int h = (hist->data[i] * altura) / hist->max_freq; // Escala a altura utilizando o valor máximo como altura máxima.
		for (int j = 0; j < h; j++) {
			histImg[(altura - j - 1) * largura + i] = 255; // Branco para os pixels das "colunas" do histograma.
		}
	}

	// Salva a imagem PGM do histograma.
	fp = fopen(outputPGM, "wb");
	if (!fp) {
		puts("Erro ao abrir o arquivo PGM.");
		exit(2);
	}
	fprintf(fp, "P5\n%d %d\n255\n", largura, altura);
	fwrite(histImg, sizeof(unsigned char), largura * altura, fp);
	fclose(fp);

	// Libera a memória alocada.
	free(hist);
	free(outputCSV);
	free(outputPGM);
	free(histImg);

	printf("Histograma salvo em %s e %s\n", outputCSV, outputPGM);
}