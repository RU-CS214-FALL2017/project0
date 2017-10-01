#ifndef tools_h
#define tools_h

#include <stdio.h>

// <row> is the address to a char **.
// Creates a array of strings A, where each comma seperated value
// from <line> is an element of A, and <row>'s refrence is set to point to A.
// Returns the number elements in A (columns).
unsigned int tokenizeRow(const char * line, char * ** row);

// Removes leading and trailing whitespaces from <str>.
void trim (char * str);

// Removes the characters from <str> between indexes <startIndex> (inclusive)
// and <endIndex> (exclusive).
void removeChars (char * str, unsigned long startIndex, unsigned long endIndex);

// <table> is an address to a char ***.
// <rows> is an address to an unsigned int.
// <columns> is an address to an unsigned int.
// Creates a "table" from <csvFile> as a 2D string array, where A[n][m] will return a string
// representation of the data stored in the (n+1)th row and (m+1)th column of the "table".
// <table>'s refrence is set to point to the created "table".
// <rows>' refrence is set to the numbers of rows in "table".
// <columns>' refrence is set to the number of columns in "table".
void fillTable(FILE * csvFile, char * *** table, unsigned int * rows, unsigned int * columns);

// Prints <table> with <rows> rows and <columns> columns in a
// csv (comma seperated values) format.
void printTable (char *** table, unsigned int rows, unsigned int columns);

// Returns 1 if <str> is a valid number, else returns 0.
int isNumber(const char * str);
int isXBeforeY (const char * x, const char * y, int areNumbers);
int isNumericColumn(char *** table, int rows, int columnIndex);

#endif /* tools_h */
