#ifndef tools_h
#define tools_h

char ** tokenizeRow (const char * line);
void trim (char * str);
void removeChars (char * str, unsigned long startIndex, unsigned long endIndex);

#endif /* tools_h */
