#include <string.h>
#include <stdlib.h>

#include "tools.h"

void mergeSort(char * *** table, const unsigned int columnIndex, const int areNumbers,
               const unsigned int start, const unsigned int end);

void merge(char * *** table, const unsigned int columnIndex, const int areNumbers,
           const unsigned int start, const unsigned int mid,  const unsigned int end);

int sortTableByColumn(const char * columnHeader, char * *** table,
                      const unsigned int rows, const unsigned int columns) {
    
    unsigned int columnIndex = 0;
    int found = 0;
    
    for (int i = 0; i < columns; i++) {
        
        if (!strcmp((*table)[0][i], columnHeader)) {
            
            columnIndex = i;
            found = 1;
            break;
        }
    }
    
    if (found) {
        
        mergeSort(table, columnIndex, isNumericColumn(*table, rows, columnIndex), 1, rows);
        return found;
        
    } else {
        return found;
    }
}

//start inclusive
//end exclusive
void mergeSort(char * *** table, const unsigned int columnIndex, const int areNumbers,
               const unsigned int start, const unsigned int end) {
    
    if ((end - start) > 1 ) {
        
        unsigned int mid = ((end - start) / 2) + start;
        
        mergeSort(table, columnIndex, areNumbers, start, mid);
        mergeSort(table, columnIndex, areNumbers, mid, end);
        
        merge(table, columnIndex, areNumbers, start, mid, end);
    }
}

void merge(char * *** table, const unsigned int columnIndex, const int areNumbers,
           const unsigned int start, const unsigned int mid,  const unsigned int end) {
    
    char ** temp[end - start];
    unsigned int s = start;
    unsigned int m = mid;
    unsigned int i = 0;

    while(s < mid && m < end) {
        
        if(isXBeforeY((*table)[s][columnIndex], (*table)[m][columnIndex], areNumbers)) {
            
            temp[i] = (*table)[s];
            s++;
            
        } else {
            
            temp[i] = (*table)[m];
            m++;
        }
        
        i++;
    }
    
    while (s < mid) {
        
        temp[i] = (*table)[s];
        s++;
        i++;
    }
    
    while (m < end) {
        
        temp[i] = (*table)[m];
        m++;
        i++;
    }
    
    s = start;
    
    for (int j = 0; j < i; j++) {
        
        (*table)[s] = temp[j];
        s++;
    }
}
