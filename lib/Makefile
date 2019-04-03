all: simplemod simple.o header

header: ../module/simple-mod.c ../module/simple-mod.h simple.c simple.h
	cat ../module/simple-mod.h simple.h simple.c | sed 's/#include ".*"//g' > simplelib.h

simplemod: ../module/simple-mod.c
	(cd ../module && make)

simple.o: simple.c simple.h
	gcc -Wall -Wextra -I../module simple.c -c

clean:
	(cd ../module && make clean)
	rm -f simplelib.h *.o
