
#include "externvar.h"
#include "data.h"
#include "useless.h"
#include "database.h"
#ifndef TABLE_FILE
#define TABLE_FILE
	void createTable(char * DatabasePath,char * tableName,char * columns);
	void checkIfTableFolderExistAndCreate(char * path);
	void createColumnsData(char * path,char * columns,char * tablename);
#endif
