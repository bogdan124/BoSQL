



void addElementsToColumn(FILE *f , char * row_column)
{



}



//NOTE: functia nu e testata
void generate_struct_h(char * name_file ,char * extract_dir_name,char * row_column)
{
	

	FILE *f;
	
	char * dirname;
	
	dirname=allocChar(300);
	
	strcpy(dirname,extract_dir_name);
	
	strcat(extract_dir_name,name_file);
	
	f=fopen(extract_dir_name,"w");
	
	if(f==NULL){
		printf("ERROR 7 : can't create row with attributes");
	}	
	
	fprintf(f,"struct column{");
	addElementsToColumn(f,row_column);
	fprintf(f,"};");
	fprintf(f,"typedef struct column column");
	fclose(f);

	/*
	   cum pot sa accesez elementele din fisierul creat
	   adica pot sa folosesc un string venit de la o functie in fisierul c
	   ex :  funct(read_file_with_Struct_generated) => o variabila <nume>
	   sa scriu <nume>.id  

	*/
}







