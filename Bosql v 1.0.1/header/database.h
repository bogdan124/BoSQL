
#include "externvar.h"
#include "data.h"
#include "useless.h"

#ifndef DATABASEHV
#define DATABASEHV
	void createDatabase(char * DB_name);
	void setDBpath(char * dbname);
	void verifyPathDB(const char *path,int listNume,int listPath,int listConfig);
	void createDBstoreFiles(char * databaseFolder);
#endif
