compile: main.c tools.c tools.h sorter.c sorter.h analyser.c analyser.h
	gcc main.c tools.c sorter.c analyser.c -o sorter -Wall -std=gnu11