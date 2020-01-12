




void create_function(char * b,int i,char *a){


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


	//CREATE <name> ;
	if (strcmp(b,"CREATE")==0){
		name=getTheCommand(a,i+1);
		createBinFile(name);
		
		if (strcmp(getTheCommand(a,i+2),";")==0){
			//printf("\nCREATE-->Succes");
		}else{
			ERROR_1
		}
	}
}
