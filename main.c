#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tools.h"

void printTable (char *** table, unsigned int rows, unsigned int columns);

int main(int argc, const char * argv[]) {

    char *** table = (char ***) malloc(4194304 * sizeof(char **));
    char line[4096];
    unsigned int rows = 0;
    unsigned int columns = 0;
    
    while(fgets(line, 4096, stdin) != NULL) {
        
        if (rows == 0) {
            
            columns = tokenizeRow(line, &table[rows]);
            rows++;
            
        } else if (tokenizeRow(line, &table[rows]) == columns) {
            rows++;
            
        } else {
            free(table[rows]);
        }
    }
    
    table = (char ***) realloc(table, sizeof(char **) * rows);

    printTable(table, rows, columns);

    return 0;
}

void printTable (char *** table, unsigned int rows, unsigned int columns) {
    
    for (int i = 0; i < rows; i++) {
        
        for (int j = 0; j < columns; j++) {
            printf("%s,", table[i][j]);
        }
        
        printf("\n\n");
    }
}
