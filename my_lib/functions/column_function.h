


void column_function(char * b,int i,char *a){



	char * getnumber1;
	char * name;
	char * end_file;
	char * command;		
	char * midd_command1;
	
	
	getnumber1=allocChar(300);
	midd_command1=allocChar(300);
	command=allocChar(300);
	name=allocChar(300);
	end_file=allocChar(300);


if (strcmp(b,"COLUMN")==0){
		//printf("%s",b);
		name=getTheCommand(a,i+1);
		if(locateBinFile(name)==1){
			
			if(readFromBinaryFile(name,midd_command1,0)!=NULL)
					printf("%s\n",readFromBinaryFile(name,midd_command1,0));
			end_file=getTheCommand(a,i+2);
		}else{
			ERROR_4
		}
			if(strcmp(end_file,";")!=0){
				ERROR_1
			}

	}


}
