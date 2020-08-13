#include "externvar.h"
#include "data.h"
#include "useless.h"
#include "database.h"
#include "table.h"
#ifndef MAPPING_FILE
#define MAPPING_FILE
    char *readFileMapped(char * readFile,int scanPageSize);
    void appenFileMapped(char * file,char * addedText);
#endif
