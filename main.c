#include <string.h>
#include <stdlib.h>

#include "tools.h"
#include "sorter.h"

int main(int argc, const char * argv[]) {

    for (int i = 0; i < argc; i++) {

        if(!strcmp("-c", argv[i])) {

            if ((i + 1) == argc) {

                perror("Column header not specified");
                exit(EXIT_FAILURE);

            } else {

                char *** table;
                unsigned int rows;
                unsigned int columns;
                const char * columnHeader = argv[i + 1];
                
                fillTable(stdin, &table, &rows, &columns);
                
                if (sortTableByColumn(columnHeader, &table, rows, columns)) {
                    printTable(table, rows, columns);
                    
                } else {
                    
                    perror("Specified Column header not found");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    exit(EXIT_SUCCESS);
}


