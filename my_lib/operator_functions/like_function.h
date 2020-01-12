

void like_function(char * command,int start_COUNT,int finish_COUNT,char * name){
	
	char * save ;
	//char * new_string;
	int column_number=0;
	column_number=atoi(getFunctionParameters(command,2));
	save=allocChar(300);
	//new_string=allocChar(300);
	
	int z=0;	

	/*if(command[0]=="'" || command[strlen(command)]=="'"){
		for(int i=0;command[i]!='\0';i++){
			if(command[i]!="'"){
				new_string[z]=command[i];
				z++;	
			}
		}
	}*/


	for (int il=start_COUNT;il<finish_COUNT+1;il++){
		save=readFromBinaryFile(name,command,il);
		if(save!=NULL){
		//printf("--%s,%s\n",getFunctionParameters(save,column_number),getFunctionParameters(command,1));
			if(strcmp(getFunctionParameters(save,column_number),getFunctionParameters(command,1))==0){
				printf("%s\n",save);
			}
		}
	}
	
	
}





/*
void selectColumnVaLUES_function(char * command,int start_COUNT,int finish_COUNT,char * name){
	
	char * save;
	int column_number=0;
	column_number=atoi(getFunctionParameters(command,2));
	save=allocChar(300);
	printf("\n%d-%d\n",start_COUNT,column_number);
	for (int il=start_COUNT;il<finish_COUNT+1;il++){
		save=readFromBinaryFile(name,command,il);
		if(save!=NULL)
		printf("--%s\n",getFunctionParameters(save,column_number));
		
		
	}
	
	
}

*/
