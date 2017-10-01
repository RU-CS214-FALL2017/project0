sorter: main.c tools.c tools.h sorter.c sorter.h
	gcc main.c tools.c sorter.c -o sorter -Wall -std=gnu11