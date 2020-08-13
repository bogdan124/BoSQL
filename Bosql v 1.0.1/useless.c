
#include "useless.h"

char** splitWords(char* a_str, const char a_delim,int *number)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    *number=count;
    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


int checkIfDBExist(char * nameExist){

	if(nameExist!=NULL){
		return 1;
	}else{
		printf("\nERROR:The path is not set to a Database or the Database doesn't exist\n");
		return 0;
	}
}

void checIfNotNull(void * pointer){
    if(pointer==NULL){
        exit(1);
    }
}




char ** matrixAloc(){
	char ** matrixSplit;

	matrixSplit=(char**)malloc(WORD_MATRIX_COLS * sizeof(char*));
	for(int k=0;k<WORD_MATRIX_ROWS;k++){
		matrixSplit[k]=aloString(WORD_MATRIX_ROWS);
	}

	return matrixSplit;
}

unsigned int file_length(FILE *f)
{
    unsigned int pos;
    unsigned int end;

    pos = ftell (f);
    fseek (f, 0, SEEK_END);
    end = ftell (f);
    fseek (f, pos, SEEK_SET);

    return end;
}


char * aloString(int n){
    char * data;

    data=(char *)malloc(n * sizeof(char));
    if(data==NULL)
    {
        printf("ERROR 1: reading/mem alocation Database");
    }

    return data;
}



unsigned long findDataType(char * dataType){
    unsigned long memoryValue=0;
    if(strcmp(dataType,"MEDIUM-INT")==0){
        memoryValue=MEDIUMINT;
    }else if(strcmp(dataType,"TINY-TEXT")==0){
        memoryValue=TINYTEXT;
    }else if(strcmp(dataType,"MEDIUM-TEXT")==0){
        memoryValue=MEDIUMTEXT;
    }else if(strcmp(dataType,"BIG-TEXT")==0){
        memoryValue=BIGTEXT;
    }else if(strcmp(dataType,"TINY-INT")==0){
        memoryValue=TINYINT;
    }else if(strcmp(dataType,"BIG-INT")==0){
        memoryValue=BIGINT;
    }

    return memoryValue;
}


void freeMatrix(char **a, int m) {
    int i;
    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
}


char * lowerString(char * str){

    for(int i=0;str[i]!='\0';i++)
    {
        str[i]=tolower(str[i]);
    }

    return str;
}


char * upperString(char * str){

    for(int i=0;str[i]!='\0';i++)
    {
        str[i]=toupper(str[i]);
    }

    return str;
}
