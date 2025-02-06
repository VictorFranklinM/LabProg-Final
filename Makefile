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
	rm -f prog.exe k-means/k-means.o pgm/pgm.o main.o