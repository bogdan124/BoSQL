#include "commandExecute.h"


void executeUSE(char * dbname,char * semicolon){
    char *dabasename;
    dabasename=aloString(100);
    dabasename[0]=toupper(dbname[0]);
	if(semicolon[0]!=';'){
			printf("ERROR in your bosql syntax!\n");
	}else{
            for(int i=1;i<strlen(dbname);i++){
                dabasename[i]=dbname[i];
            }
			setDBpath(dbname);
	}
	free(dabasename);
}

void executeINSERT(char * tableName,char * dataToInsert){

    char * setPath;
    char * pathFiles;
    char * storeNameFile;

    int number;
    int getColumnNum;

    char **tokens;

    FILE *f;

    tokens=matrixAloc();
    pathFiles=aloString(100);
    setPath=aloString(100);
    storeNameFile=aloString(100);

    strcpy(setPath,SET_PATH);
    strcat(setPath,"TABLES/");
    strcat(setPath,tableName);
    strcat(setPath,"/");
    strcpy(pathFiles,setPath);
    strcat(setPath,tableName);
    strcat(setPath,".bohd");

    tokens=splitWords(dataToInsert,',',&number);

    f=fopen(setPath,"rt");
    fscanf(f,"%d",&getColumnNum);
    for(int i=0;i<getColumnNum;i++){
        fscanf(f,"%s",storeNameFile);
        strcat(storeNameFile,".bo");
     //   printf("\n:%s:",storeNameFile);
        insertDataFile(storeNameFile,tokens[0],pathFiles,tokens[i]);
    }
    fclose(f);
  //  printf("%s",setPath);



    //unsigned float t=time(0);
   // printf("inserted");
    //unsigned int float=time(0)-t;
    //printf("\n%f",result);
    //free(number);
    free(pathFiles);
    free(setPath);
    free(storeNameFile);
}

void insertDataFile(char * file,char * index,char *pathFile,char *data){
    FILE * f;
    char * storeData;
    char * storePathFile;
    char * charNumberOfBytes;

    int getfile;


    storePathFile=aloString(100);
    storeData=aloString(100);
    charNumberOfBytes=aloString(100);
    strcpy(storePathFile,pathFile);
   // printf("%s ",storePathFile);

    strcat(storePathFile,file);

 /*   strcpy(storeData,2);
    strcat(storeData,",");
    strcat(storeData,"100");
    strcat(storeData,",");*/

    /*first to verify size of file if is long then 4gb*/

    f=fopen(storePathFile,"at");
    getfile=file_length(f);
    sprintf(charNumberOfBytes,"%d", getfile);

    strcpy(storeData,charNumberOfBytes);
    strcat(storeData,",");
    strcat(storeData,index);
    strcat(storeData,",");
    strcat(storeData,data);
    fprintf(f,"%s\n",storeData);

    fclose(f);

    free(storePathFile);
    free(storeData);
    free(charNumberOfBytes);
}

void executeSelect(char *getTable,char * columns){

    char *fileToRead;
    char *readPage;
    fileToRead=aloString(100);
    readPage=aloString(4096);
    strcpy(fileToRead,SET_PATH);
    strcat(fileToRead,"/TABLES/");
    strcat(fileToRead,getTable);
    strcat(fileToRead,"/name.bo");
  //  for(int i=0;i<12;i++){
        readPage=readFileMapped(fileToRead,0);
        printf("%s ",readPage);
    //}
    printf("%s %s %s",SET_PATH,getTable,columns);


    free(fileToRead);

}

void showTables(char * getDatabase){

    char *saveFile;
    char *showData;

    showData=aloString(100);
    saveFile=aloString(100);


    FILE * f;


    strcpy(saveFile,getDatabase);
    strcat(saveFile,"Database.bodb");
    f=fopen(saveFile,"rt");
    checIfNotNull(f);
    printf("+-------------------------------------------+\n");
    printf("|                  Tables                   |\n");
    printf("+-------------------------------------------+\n");

    while(!feof(f)){
        fscanf(f,"%s",showData);
        if(feof(f)){
            break;
        }
        printf("* %s\n",showData);

    }
    fclose(f);
    free(showData);
    free(saveFile);
}

void writeToFileTable(char * path,char *nameFile){

    FILE *f;
    char *savePath;

    savePath=aloString(100);
    strcpy(savePath,path);
    strcat(savePath,"Database.bodb");
    f=fopen(savePath,"at");

    fprintf(f,"%s\n",nameFile);

    fclose(f);
    free(savePath);
}

void executeExit(){

	printf("\nDatabase exiting");
    printf("[|]");
    fflush(stdout);
    sleep(1);
    // do something
    printf("\b\b\b[/]");
    fflush(stdout);
    // do some more
    sleep(1);
    printf("\b\b\b[-]");
    fflush(stdout);
    sleep(1);
     printf("\b\b\b[/]");
    fflush(stdout);
    // do some more
    sleep(1);
    printf("\b\b\b[-]");
    fflush(stdout);
    sleep(1);

	exit(1);
}




