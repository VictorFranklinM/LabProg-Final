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

struct histogram {
	int data[256];  // Vetor que conta a frequência de cada tom de cinza (0 a 255).
	int max_freq;  // Armazena a frequência máxima encontrada para normalização da altura das colunas da imagem gerada.
};

void generateHistogram(unsigned char *data, int linhas, int colunas, const char *basePath) {
	// Aloca memória para a estrutura do histograma e inicializa com zeros.
	struct histogram *hist = (struct histogram *)calloc(1, sizeof(struct histogram));
	
	// Verifica se a alocação foi bem-sucedida.
	if (!hist) {
		puts("Erro ao alocar memória para o histograma.");
		exit(1);
	}

	/* Conta a frequência de cada tom de cinza e guarda. A max_freq armazena a frequência máxima encontrada. Varre todos os pixels da imagem 
 		incrementando a contagem do tom de cinza que corresponde ao do pixel atual e gravando em max_freq caso seja maior que o valor já gravado.*/
    	for (int i = 0; i < linhas * colunas; i++) {
			hist->data[data[i]]++;
			if (hist->data[data[i]] > hist->max_freq) {
				hist->max_freq = hist->data[data[i]];
		}
	}

	// Aloca memória para armazenar os nomes dos arquivos CSV e PGM.
	char *outputCSV = (char *)malloc(60 * sizeof(char));
	char *outputPGM = (char *)malloc(60 * sizeof(char));
	
	// Verifica se a alocação foi bem-sucedida.
	if (!(outputCSV && outputPGM)) {
		puts("Erro ao alocar memória para os nomes dos arquivos.");
		exit(1);
	}
	
	// Formata os nomes dos arquivos, concatenando a basePath com as extensões.
	snprintf(outputCSV, 60, "%s.csv", basePath);
	snprintf(outputPGM, 60, "%s.pgm", basePath);

	FILE *fp = fopen(outputCSV, "w");  // Abre um arquivo CSV para escrita.
	
	// Verifica se o arquivo foi aberto corretamente.
	if (!fp) {
		puts("Erro ao abrir o arquivo CSV.");
		exit(2);
	}

	fprintf(fp, "Tom de Cinza, Frequência\n");  // Escreve o cabeçalho do CSV com os nomes das colunas.
	for (int i = 0; i < 256; i++) {
		fprintf(fp, "%d, %d\n", i, hist->data[i]);  // Percorre todos os 256 níveis de cinza (0 a 255) e salva a frequência no arquivo CSV.
	}
	fclose(fp);

	/* Cria a imagem PGM do histograma, aloca memória e inicializa ela com zeros para um fundo preto. A imagem tem 256 pixels de largura (0-255,
 		para cada tom de cinza) e a altura representa a frequência de cada tom de cinza.*/
	int altura = 256;
	int largura = 256;
	unsigned char *histImg = (unsigned char *)calloc(largura * altura, sizeof(unsigned char));

	// Verifica se a alocação de memória foi bem-sucedida.
	if (!histImg) {
		puts("Erro ao alocar memória para a imagem do histograma.");
		exit(1);
	}

	// Preenche a imagem com o histograma, de baixo para cima.
	for (int i = 0; i < 256; i++) {
		int h = (hist->data[i] * altura) / hist->max_freq; // Faz escala da altura; divide pela frequência máxima, assim o valor de cinza com frequência máxima recebe altura máxima, e o resto recebe proporcional a ele.
		for (int j = 0; j < h; j++) {
			histImg[(altura - 1 - j) * largura + i] = 255; // Branco para os pixels das "colunas" do histograma.
		}
	}

	fp = fopen(outputPGM, "wb"); // Abre um arquivo PGM para escrita.
	
	// Verifica se o arquivo foi aberto corretamente.
	if (!fp) {
		puts("Erro ao abrir o arquivo PGM.");
		exit(2);
	}
	fprintf(fp, "P5\n%d %d\n255\n", largura, altura); // Escreve o cabeçalho do arquivo PGM no formato P5.
	fwrite(histImg, sizeof(unsigned char), largura * altura, fp); // Escreve os dados da imagem no arquivo, armazenando os pixels na sequência correta.
	fclose(fp);

	// Libera a memória alocada.
	free(hist);
	free(outputCSV);
	free(outputPGM);
	free(histImg);
}