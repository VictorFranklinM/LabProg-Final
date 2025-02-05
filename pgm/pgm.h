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

#ifndef PGM_H
#define PGM_H

struct pgm{
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
};
void readPGMImage(struct pgm *, char *);
void viewPGMImage(struct pgm *);
void writePGMImage(struct pgm *, char *);

#endif