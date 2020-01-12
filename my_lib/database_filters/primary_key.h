


int primary_key(char * name,char * command){
	
	char * get_first_line ;
	char * gtline;
	char *linej;
	
	get_first_line=allocChar(300);
	linej=allocChar(300);
	get_first_line=readFromBinaryFile(name,command,0);

	int start=0;
	int finish=0;
	int z=0;
	int count=0;
	int error_code=0;
	int count2=0;

	strcpy(gtline,"");
	for(int i=0;i<strlen(get_first_line);i++){
		if(get_first_line[i]=='('){
			start=i;
			finish=0;
			count++;

		}
		if(get_first_line[i]==')'){
			finish=i;
			for(int k=start;k<=finish;k++){	
				gtline[z]=get_first_line[k];
				z++;
				//getFunctionParameters(command,2)
			}
			gtline[z]='\0';
			z=0;
			for(int y=1;y<10;y++){
				//check all function parameters to not find a primary key
				if(strlen(getFunctionParameters(gtline,y))!=0){
					if(strcmp(getFunctionParameters(gtline,y),"PRIMARY_KEY")==0){
						for(int p=1;p<getTheLineNumbers(name);p++){
							for(int m=0;command[m]!=')';m++){	
								if(command[m]==',' && (command[m-1]!=' ' || command[m-1]!='(' || command[m-1]!=',' ) ){
									count2++;
									if(count2==count){
										linej=getFunctionParameters(command,count);
										if(strcmp(linej,"NULL")==0){
											printf("\nERROR 8 : can't have primary key on a NULL column");
											error_code=1;
											break;
										}else{
											for(int u=1;u<getTheLineNumbers(name);u++){
												//printf("\n---%s-%s--",readFromBinaryFile(name,command,u),linej);
												if(strcmp(getFunctionParameters(readFromBinaryFile(name,command,u),count),linej)==0){
													printf("\nERROR 9 : the column is primary key ,we found a dublicate!!");
													error_code=2;
													break;
												}else{
													error_code=0;
												}
											}
										}
									}
								}
							}
						}
					}	
				if(strcmp(getFunctionParameters(gtline,y),"AUTO_INCREMENT")==0)	{
					//printf("auto");	
						//auto_increment();
				    }	
	
				}
			}
			strcpy(gtline,"");
			start=0;	
		}
			
	}

	return error_code;
}
