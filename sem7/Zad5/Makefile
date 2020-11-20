main:main.c dziekanat.c studenci.c dziekanat.h studenci.h
	cc zmain.c dziekanat.c studenci.c -o zad5 -Wall --pedantic

DEPS=main.o main.o dziekanat.o studenci.o

main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o
