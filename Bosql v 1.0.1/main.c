

#include "data.h"
#include "externvar.h"
#include "useless.h"
#include "commandExecute.h"
#include "commands.h"
#include "database.h"
#include "table.h"
#include "storeDef.h"

void executeCommands();
void testFile();



int main()
{

    //dataCompressionBase64();
   // testWriteFile();
   // testReadFile();
	executeCommands();
	//createDatabase("Database2");

	return 0;
}

void executeCommands(){
	int number;
	char ** tokens;
	char *command;

    createDBstoreFiles("Database");
	command=aloString(BUFFER_SIZE+1);
	printf("+-------------------------------------------+\n");
    printf("|                                           |\n");
    printf("|                                           |\n");
    printf("|   XXXXX         XXXXXX           X        |\n");
    printf("|   X   X         X        XXXX    X        |\n");
    printf("|   XXXXX         X      XX   XX   X        |\n");
    printf("|   X    X  XXXX  XXXXX  X  X  X   X        |\n");
    printf("|   X    X X   X      X  X    X    X        |\n");
    printf("|   XXXXXX  XXX   XXXXX   XXXXX    XXXXXX   |\n");
    printf("|                             XX            |\n");
    printf("|                                           |\n");
    printf("+-------------------------------------------+\n");
	while(1){
		printf("bosql>");
		tokens=matrixAloc();
		fgets(command,BUFFER_SIZE,stdin);
		tokens=splitWords(command,' ',&number);
		commandsDetect(tokens,number);
        //freeMatrix(tokens,WORD_MATRIX_ROWS);
	}
}



