

//GENERATE <table_name> 1000 ;
void generate_function(char * b,int i,char *a){

	char * name;
	char * end_file;
	char * command;		
	
	command=allocChar(300);
	name=allocChar(300);
	end_file=allocChar(300);


	if(strcmp(b,"GENERATE")==0){
		name=getTheCommand(a,i+1);
		
		if(locateBinFile(name)==1){
			command=getTheCommand(a,i+2);
			
		}else{
			printf("Unable to locate the table!");
		}
		
		end_file=getTheCommand(a,i+3);
		if(end_file==';'){
			printf("Error");
		}

	}




}
