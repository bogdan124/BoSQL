#include<stdio.h>
#include<stdlib.h>
#include<string.h>






#include "my_lib/errors_codes.h"

void show_start();
void * detectCommand(char * b,int i,char * a);
char * getAnWordInText(char * a,int i);
char * allocChar(int i);
void createBinFile(char *name);
char * getTheCommand(char * a,int i);
char * writeToBinaryFile(char * a ,char * command);
int getTheLineNumbers(char * filename);
char * extractNumbers(char * command,int which_number);
int locateBinFile(char * a);
char * readFromBinaryFile(char * a ,char * command,int i);
char * appendToBinaryFile(char * a ,char * command);
//get number between (12,12)
char * extractNumbers(char * command,int which_number);

//my includes

#include "my_lib/include_dependences.h" 




int main(){

	char a[300];
	
	show_start(1);
	gets(a);
	for(int i=0;i<getTheLineNumbers(a)*4;i++){
			getAnWordInText(a,i);
		}
	while(1){	
		show_start(0);
		gets(a);
		
		for(int i=0;i<getTheLineNumbers(a)*4;i++){
			getAnWordInText(a,i);
		}
		//printf("%s",b);
	}

	return 0;
}


void show_start(int i){
	
	if(i==0){
		printf("\n>");
	}else{
		printf("\tWELCOME TO BOGDAN'S SQL!");
		printf("\n>");
	}
}


int getTheLineNumbers(char * filename){
	int number_lines=0;
	char gh;
	FILE * f;
	f=fopen(filename,"rt");		
		
	while(!feof(f)){
		gh=fgetc(f);
		if(gh=='\n'){
			number_lines++;
		}
	
	}
	
	return number_lines;
}

//i=linia
char * getAnWordInText(char * a,int i){

	char * b;
	b=allocChar(300);
			
	FILE * f;

	f=fopen(a,"rt");
	int l=0;	
	while(fscanf(f,"%300s",b)==1){
		if(l==i){
			detectCommand(b,i,a);
			//printf("%s",b);
		}	
	l++;	
	}
	fclose(f);

	return b;
}
void createBinFile(char *name){
	FILE *f;
	f=fopen(name,"wb");
	fclose(f);
}

char * getTheCommand(char * a,int i){
	char * b,*g;
	b=allocChar(300);
	g=allocChar(300);	
	
			
	FILE * f;

	f=fopen(a,"rt");
	int l=0;	
	while(fscanf(f,"%300s",b)==1){
		if(l==i){
		     strcpy(g,b);
		}	
	l++;	
	}
	fclose(f);

	return g;
}
int locateBinFile(char * a){
	FILE *f;
	f=fopen(a,"rb");
	if(f==NULL){
		printf("ERROR 2:File %s needs to be created,doesn't exist!",a);
		return 0;	
	}else{
		return 1;
	}
}


char * writeToBinaryFile(char * a ,char * command){
	FILE * f;
	f=fopen(a,"wt");
	//fwrite(command,sizeof(command),1,f);
	fprintf(f,"%s\n",command);
	fclose(f);
	
}

char * appendToBinaryFile(char * a ,char * command){
	FILE *f;
	f=fopen(a,"at");
	//fwrite(command,sizeof(command),1,f);
	fprintf(f,"%s\n",command);
	fclose(f);
}	

char * readFromBinaryFile(char * a ,char * command,int i){

	//printf("%s",a);
	FILE * f1;
	f1=fopen(a,"rt");
	char * s;
	char * save;
	s=allocChar(300);	
	//fread(s1,sizeof(s1),1,f1);
	//printf("%s",s1);
	int j=0;
	while(fscanf(f1,"%s",s)==1)
	{	
		
		if(i==j && i>=0){
			//printf("%s\n",s);
			return s;
		//	strcpy(save,s);
		}else if (i==-1){
			printf("%s\n",s);
			//return s;
			//strcpy(save,s);
		}	
		j++;
	}	

	fclose(f1);
	//return save;

}


void * detectCommand(char * b,int i,char *a){
	
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

	
	
	create_function(b,i,a);
	content_function(b,i,a);
	show_function(b,i,a);
	column_function(b,i,a);
	insert_function(b,i,a);
	select_function(b,i,a);
	//primaryKey(b,i,a);

	if (strcmp(b,"##")==0){
	
	}

}




//get number between (12,12)
char * extractNumbers(char * command,int which_number){

	int start  = 0;
	int finish = 0;
	char * getnum;
	getnum=allocChar(300);
	for(int i=0;i<strlen(command);i++){
		if(which_number==1){
			if(command[i]=='('){
				start=i+1;	
			}else if(command[i]==','){
				finish=i;	
				break;	
			}			
		}
		 if(which_number==2){
			if(command[i]==')'){
				finish=i;
				break;	
			}else if(command[i]==','){
				start=i+1;	
				
			}	
		}
	}
	
	int q=0;
	for(int i=start;i<finish;i++){
		getnum[q]=command[i];
		q++;
	}
	getnum[q]='\0';
	//printf("\n--%s--\n",getnum);
	return getnum;
}


char * allocChar(int i){
	char *b;

	b=(char *)malloc(i * sizeof(char));
	if(b==NULL){
		printf("Alocare esuataa!");
	}
	return b;
}




