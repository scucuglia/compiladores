clean:
	-rm *.o

fb:
	-flex cminus.l
	-bison -d cminus.y

cb:
	-gcc -c *.c
	-gcc -o cminus *.o -lfl -ly

all: fb cb