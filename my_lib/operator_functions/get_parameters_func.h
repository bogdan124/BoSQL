



char * getFunctionParameters( char * command ,int parameter_number){
	
	char * parameter,* save_para;
	parameter=allocChar(300);
	save_para=allocChar(300);
	int inside=0;
	int z=0;
	int count_parameter_number=1;

	for(int i=0;i<strlen(command);i++){
		
		if((command[i]=='(' || command[i-1]==',' ) || inside==1){
			inside=1;
			for(int j=i;j<strlen(command);j++){
				if(command[j]==',' || command[j]==')'){
					inside=0;
					break;		
				}else{
					if(command[j]!='('){
						save_para[z]=command[j];
						save_para[z+1]='\0';
						z++;
					}
				}	
			}
			z=0;
			if(count_parameter_number==parameter_number){
				strcpy(parameter,save_para);
				//printf("\n--%s--",save_para);
			}
			count_parameter_number++;
			
			//for(int k=0;k<strlen(save_para);k++){
			//	save_para[k]=' ';
			//}
		}else{
			//printf("ERROR 5 : no ) ");
		}
	}	


	return parameter;

}


