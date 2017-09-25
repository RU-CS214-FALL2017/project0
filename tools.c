#include <string.h>
#include <stdlib.h>

#include "tools.h"

char ** tokenizeRow(const char * line) {
    
    char ** ret = (char **) malloc(strlen(line) * sizeof(char *));
    
    char tempChar = '\0';
    char tempCell[4096];
    int i = 0;
    int j = 0;
    int inQuote = 0;
    int outQuote = 0;
    
    for(int l = 0; l <= strlen(line); l ++) {
        
        tempChar = line[l];
        
        if ((tempChar == ',' || tempChar == '\0') && !inQuote){
            
            tempCell[j] = '\0';
            trim(tempCell);
            ret[i] = (char *) malloc(strlen(tempCell) * sizeof(char) + 1);
            strcpy(ret[i], tempCell);
            
            j = 0;
            i += 1;
            
            outQuote = 0;
            
        } else if (tempChar == '"' && inQuote) {
            inQuote = 0;
            
        } else if (tempChar == '"' && !outQuote && !inQuote) {
            inQuote = 1;
            
        } else {
            
            tempCell[j] = tempChar;
            j += 1;
            if(tempChar != ' '){
                outQuote = 1;
            }
        }
    }
    
    if(realloc(ret, i * sizeof(char *)) == NULL) {
        return NULL;
    }
    
    return ret;
}

void trim (char * str) {
    
    int i = 0;
    
    while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
        i += 1;
    }
    
    removeChars(str, 0, i);
    
    unsigned long terminatingIndex = strlen(str);
    unsigned long j = terminatingIndex - 1;
    
    while(str[j] == ' ' || str[j] == '\n' || str[j] == '\t') {
        j -= 1;
    }
    
    removeChars(str, j + 1, terminatingIndex);
}

void removeChars (char * str, unsigned long startIndex, unsigned long endIndex) {
    
    unsigned long terminatingIndex = strlen(str);
    
    for(int i = 0; i <= (terminatingIndex - endIndex); i++) {
        
        str[startIndex + i] = str[endIndex + i];
    }
}
