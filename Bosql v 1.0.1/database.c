

#include "database.h"
char DATABASES_FOLDER[50]="Database/";
char SET_PATH[100];
void createDatabase(char * DB_name){

	char * path=aloString(100);
	char * touchCommand=aloString(100);

	strcpy(path,"mkdir ");
	strcat(path,DATABASES_FOLDER);
	strcat(path,DB_name);
	system(path);
	strcat(path,"/TABLES");
	system(path);
	strcpy(touchCommand,"touch ");
	strcat(touchCommand,DATABASES_FOLDER);
	strcat(touchCommand,DB_name);
	strcat(touchCommand,"/");
	strcat(touchCommand,"Database");
	strcat(touchCommand,".bodb");
	system(touchCommand);
	free(touchCommand);
	free(path);
}

void setDBpath(char * dbname){

	char *path=aloString(100);
	strcpy(path,DATABASES_FOLDER);
	strcat(path,dbname);
	strcat(path,"/");
	strcpy(SET_PATH,path);
	free(path);
}

void createDBstoreFiles(char * databaseFolder){
    char * path;
    FILE * f;
    path=aloString(100);
    checIfNotNull(path);
    strcpy(path,databaseFolder);
    strcat(path,"/");
    strcat(path,"databases.boin");
    f=fopen(path,"rt");
    if(f==NULL){
        FILE * g;
        g=fopen(path,"wt");
        fclose(g);
    }
    fclose(f);
    free(path);
}

void verifyPathDB(const char *path,int listNume,int listPath,int listConfig){

    FILE *f;
    int numbers=0;
    char *numeDB;
    char *pathTables;
    char *pathFileDB;

    numeDB=aloString(100);
    pathTables=aloString(100);
    pathFileDB=aloString(100);
    f=fopen("Database/databases.boin","rt");
    checIfNotNull(f);
    fscanf(f,"%d",&numbers);
    printf("+-----------+\n");
    printf("| Databases |\n");
    printf("+-----------+\n");
    while(!feof(f)){
        fscanf(f,"%s",numeDB);
        if(listNume==1){
            printf("|%s|\n",numeDB);
        }
        fscanf(f,"%s",pathTables);
        if(listPath==1){
            printf("|%s|\n",pathTables);
        }
        fscanf(f,"%s",pathFileDB);
        if(listConfig==1){
            printf("|%s|\n",pathFileDB);
        }

    }
    printf("+-------+\n");

    fclose(f);
    free(numeDB);
    free(pathTables);
    free(pathFileDB);
}


