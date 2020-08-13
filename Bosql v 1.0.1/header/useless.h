
#include "externvar.h"
#include "data.h"
#ifndef USELESS
#define USELESS
	char ** matrixAloc();
	char * aloString(int n);
	char** splitWords(char* a_str, const char a_delim,int *number);
	unsigned long findDataType(char * dataType);
	void checIfNotNull(void * pointer);
	void freeMatrix(char **a, int m);
	unsigned int file_length(FILE *f);
	char * upperString(char * str);
	char * lowerString(char * str);
#endif
