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

