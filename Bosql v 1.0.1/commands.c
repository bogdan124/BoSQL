#include <string.h>
#include "commands.h"


void commandsDetect(char ** tokens,int number){

	int command=0;
	//setDBpath("Database2");
	//printf("%s",SET_PATH);
	for(int i=0;i<number+1;i++){


		if(strcmp(lowerString(tokens[i]),"use")==0 ){
			command=1;
			executeUSE(tokens[i+1],tokens[i+2]);
			//printf("%s\n",SET_PATH);
			break;
		}else if(strcmp(lowerString(tokens[i]),"select")==0){
            if(strcmp(lowerString(tokens[i+2]),"from")==0 && ( strcmp(lowerString(tokens[i+4]),";")==0 || strcmp(lowerString(tokens[i+4]),";\n")==0 ) ){
                executeSelect(tokens[i+3],tokens[i+1]);
            }
        }else if(strcmp(lowerString(tokens[i]),"insert")==0){
            if( strcmp(lowerString(tokens[i+1]),"into")==0 || strcmp(lowerString(tokens[i+3]),"values(")==0 ){
                executeINSERT(tokens[i+2],tokens[i+4]);
                break;
			}
		}else if(strcmp(lowerString(tokens[i]),"create")==0){
            if( strcmp(lowerString(tokens[i+1]),"table")==0 || strcmp(tokens[i+3],"(")==0 || strcmp(tokens[i+5],")")==0){
                createTable(SET_PATH,tokens[i+2],tokens[i+4]);
                writeToFileTable(SET_PATH,tokens[i+2]);
                break;
			}else if(strcmp(lowerString(tokens[i+1]),"database")==0 ){
                createDatabase(tokens[i+2]);
                break;
			}
		}else if( strcmp(lowerString(tokens[i]),"exit\n")==0 || strcmp(lowerString(tokens[i]),"exit")==0 ){
			executeExit();
			break;
		}else if(strcmp(lowerString(tokens[i]),"show")==0){
            if( strcmp(lowerString(tokens[i+1]),"tables\n")==0 || strcmp(lowerString(tokens[i+1]),"tables")==0 ){
                 showTables(SET_PATH);
                 break;
            }else if( strcmp(lowerString(tokens[i+1]),"databases\n")==0 || strcmp(lowerString(tokens[i+1]),"databases")==0 ){
               // printf("database\n");
                verifyPathDB("Databases/",1,0,0);
                break;
            }
        /*this must be the last check*/
		}else if(strcmp(tokens[i],"\n")!=0){
            printf("Syntax Error\n");
            break;
		}
	}

}

