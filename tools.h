#ifndef tools_h
#define tools_h

unsigned int tokenizeRow(const char * line, char *** row);
void trim (char * str);
void removeChars (char * str, unsigned long startIndex, unsigned long endIndex);

#endif /* tools_h */
