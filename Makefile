#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#
# Aluno : Victor Franklin Matias Silva
# Matricula : 20241045050170
# Avaliação 04 : Trabalho Final
# 04.505.23 − 2024.2 − Prof. Daniel Ferreira
# Compilador : gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#

#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#
# Aluno : Caroline de Albuquerque Arrais
# Matricula : 20241045050260
# Avaliação 04 : Trabalho Final
# 04.505.23 − 2024.2 − Prof. Daniel Ferreira
# Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#

#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#
# Aluno : Lanai Giani Lima Oliveira
# Matricula : 20231045050351
# Avaliação 04 : Trabalho Final
# 04.505.23 − 2024.2 − Prof. Daniel Ferreira
# Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#

#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#
# Aluno : Kalebe Ribeiro Sousa
# Matricula : 20241045050421
# Avaliação 04 : Trabalho Final
# 04.505.23 − 2024.2 − Prof. Daniel Ferreira
# Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
#∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗#

ifeq ($(OS),Windows_NT)
    RM = cmd /C del /Q
else
    RM = rm -f
endif

all: prog.exe

prog.exe: k-means/k-means.o pgm/pgm.o main.o
	gcc -o $@ $^

k-means/k-means.o: k-means/k-means.c
	gcc -c $< -o $@

pgm/pgm.o: pgm/pgm.c
	gcc -c $< -o $@

main.o: main.c
	gcc -c $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	-$(RM) prog.exe
	-$(RM) main.o
	-$(RM) k-means\k-means.o
	-$(RM) pgm\pgm.o
else
	-$(RM) prog.exe
	-$(RM) main.o
	-$(RM) k-means/k-means.o
	-$(RM) pgm/pgm.o
endif
