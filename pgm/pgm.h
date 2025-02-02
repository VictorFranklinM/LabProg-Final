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