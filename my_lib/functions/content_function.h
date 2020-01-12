




void content_function(char * b,int i,char *a){

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

if(strcmp(b,"CONTENT")==0){
		name=getTheCommand(a,i+1);
		
		if(locateBinFile(name)==1){

			command=getTheCommand(a,i+2);
			
			for(int ji=1;ji<strlen(command)-1;ji++){
						  midd_command1[ji-1]=command[ji];				
			}
			//midd_command1[strlen(command)]='\0';
			//printf("\n%s---%s",midd_command1,name);
			writeToBinaryFile(name,midd_command1);
			
			
		}else{
			ERROR_4
		}
		
		if(strcmp(end_file,";")!=0){
			//ERROR_1
		}
	}


}
