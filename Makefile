all: lib example

simplelib: lib/simple.c
	(cd lib && make)

example: simplelib example.c
	gcc -Wall -Wextra example.c -o example

clean:
	(cd module && make clean)
	(cd lib && make clean)
	rm -f example *.o
