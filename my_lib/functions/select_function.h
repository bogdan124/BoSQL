

//#include "/home/bogdan/Desktop/sql_lang/my_lib/operator_functions/get_parameters_func.h" 


void select_function(char * b,int i,char *a){


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



	if (strcmp(b,"SELECT")==0){
		
		name = getTheCommand(a,i+2);

		int start_COUNT=1;
		int finish_COUNT=getTheLineNumbers(name);

		if(locateBinFile(name)==1){
			command=getTheCommand(a,i+1);
			if(strcmp(command,"*")==0){
			
				
			}else if(command[0]=='(' && command[strlen(command)-1]==')'){
				
				
				getnumber1=extractNumbers(command,1);
				start_COUNT=atoi(getnumber1);
				if(start_COUNT==0)
				{
					start_COUNT=1;
					
				}
				getnumber1=extractNumbers(command,2);
				finish_COUNT=atoi(getnumber1);
				if(finish_COUNT==0){
					finish_COUNT=getTheLineNumbers(name);
				}
				
				
			}//else if(command[0]=='[' && command[strlen(command)-1]==']'){
			//		selectColumnVaLUES_function(command,start_COUNT,finish_COUNT,name);
			//}
			midd_command1=getTheCommand(a,i+3);
			//simple select * <table> ;
			if(strcmp(midd_command1,";")==0){
				
				if(start_COUNT < finish_COUNT ){
					for (int il=start_COUNT;il<finish_COUNT+1;il++){
						if(readFromBinaryFile(name,midd_command1,il)!=NULL)
						printf("%s\n",readFromBinaryFile(name,midd_command1,il));
					}
				}else{
					printf("\nERROR %d > %d : False",start_COUNT,finish_COUNT);
				}
			}else {
					//if is like 
					like_function(midd_command1,start_COUNT,finish_COUNT,name);
			}
			
		}else{
			ERROR_4
		}
	}

}
