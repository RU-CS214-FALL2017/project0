#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tools.h"

int main(int argc, const char * argv[]) {

    char *** table = (char ***) malloc(4194304 * sizeof(char **));
    char line[4098];
    int row = 0;
    
    while(gets(line) != NULL) {
        
        table[row] = tokenizeRow(line);
        row += 1;
    }
    
    if(realloc(table, (row + 1) * sizeof(char **))) {
        return 1;
    }
    
    return 0;
}

