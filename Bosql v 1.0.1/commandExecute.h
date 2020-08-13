#include "externvar.h"
#include "data.h"
#include "useless.h"
#include "database.h"
#include "table.h"
#ifndef COMMANDS_FILE_EXECUTE
#define COMMANDS_FILE_EXECUTE
    void executeUSE(char * dbname,char * semicolon);
	void executeINSERT(char * tableName,char * dataToInsert);
	void insertDataFile(char * file,char * index,char *pathFile,char *data);
	void showTables(char * getDatabase);
	void writeToFileTable(char * path,char *nameFile);
	void executeSelect(char *getTable,char * columns);
	void executeExit();
#endif
