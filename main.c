#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tools.h"

void printTable (char *** table, int lastRowIndex);

int main(int argc, const char * argv[]) {

    char *** table = (char ***) malloc(4194304 * sizeof(char **));
    char line[4096];
    int row = 0;
    while(!feof(stdin)) {
        
        fgets(line, 4096, stdin);
        table[row] = tokenizeRow(line);
        row += 1;
    }
    
    if(realloc(table, (row + 1) * sizeof(char **))) {
        return 1;
    }
    
    printf("ass nigga\n");
    
    printf("%s\n", table[0][0]);
    
    printTable(table, row);
    
    return 0;
}

void printTable (char *** table, int lastRowIndex) {
    
    for(int i = 0; i <= lastRowIndex; i++) {
        printf("%s\n", table[i][1]);
    }
}
