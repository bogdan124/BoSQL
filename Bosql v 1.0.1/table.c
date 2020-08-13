
#include "table.h"


void createTable(char * DatabasePath,char * tableName,char * columns){


	char * path=aloString(100);
	char * command=aloString(100);
	strcpy(path,DatabasePath);
	strcat(path,"TABLES");
    checkIfTableFolderExistAndCreate(path);
    strcat(path,"/");
	strcat(path,tableName);
	checkIfTableFolderExistAndCreate(path);
	createColumnsData(path,columns,tableName);
	strcat(path,"/");
	strcpy(command,"touch ");
	strcat(command,path);
	strcat(command,tableName);
	strcat(command,".bohd");
	system(command);
	free(path);
	free(command);
}

void checkIfTableFolderExistAndCreate(char * path){

    char *secondPath=aloString(100);
    char *newPath=aloString(100);
    strcpy(secondPath,path);

    DIR* dir = opendir(secondPath);
    if (dir) {
        printf("\nTable exist\n");
        /* Directory exists. */
        closedir(dir);
    } else if (ENOENT == errno) {
        /* Directory does not exist we create him. */
        strcpy(newPath,"mkdir ");
        strcat(newPath,secondPath);
        system(newPath);
        fflush(stdout);
    } else {
        printf("Table creation failed\n");
        /* opendir() failed for some other reason. */
    }

    free(newPath);
    free(secondPath);
}

void createColumnsData(char * path,char * columns,char * tablename){

    char ** tokens;
    char * storePath;
    char * command ;
    char * storeBohdPath;

    FILE *f;
    int number;

    storePath=aloString(100);
    storeBohdPath=aloString(100);

    strcpy(storePath,path);
    strcat(storePath,"/");

    strcpy(storeBohdPath,storePath);
    strcat(storeBohdPath,tablename);
    strcat(storeBohdPath,".bohd");

    tokens=matrixAloc();
    tokens=splitWords(columns,',',&number);
    f=fopen(storeBohdPath,"wt");
    fprintf(f,"%d\n",number+1);
    for(int i=0;i<number+1;i++){
        fprintf(f,"%s\n",tokens[i]);
        strcpy(command,"touch ");
        strcat(command,storePath);
        strcat(command,tokens[i]);
        strcat(command,".bo");
        system(command);
    }
    fclose(f);

    free(command);
    free(storePath);
    //freeMatrix(tokens,WORD_MATRIX_ROWS);
}


