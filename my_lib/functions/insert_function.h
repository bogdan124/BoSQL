 



void insert_function(char * b,int i,char *a){


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

if(strcmp(b,"INSERT")==0){
		name=getTheCommand(a,i+1);

		if(locateBinFile(name)==1){
			command=getTheCommand(a,i+2);
			if(command[0]!='(' ){
			
				printf("\nERROR 3: missing ( : %s",command);			
			}
			if( command[strlen(command)-1]!=')'){
				printf("\nERROR 3: missing ) : %s",command);
			}
			
			//look in file to be present rows
			appendToBinaryFile(name,command);
			
			end_file=getTheCommand(a,i+3);
			
			if(strcmp(end_file,";")!=0){
				ERROR_1
			}

			//here put into bin file data
				
		}else{
			ERROR_4
		}
		
		
	}



}
