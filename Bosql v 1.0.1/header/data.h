#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<time.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>


#ifndef DATAPRIMAL
#define DATAPRIMAL



	#define BUFFER_SIZE 1000

	#define WORD_MATRIX_ROWS 100
	#define WORD_MATRIX_COLS 100

	#define TINYINT 3
	#define MEDIUMINT 10
	#define BIGINT 15

	#define TINYTEXT 1000
	#define MEDIUMTEXT 10000
	#define BIGTEXT 100000


	struct DB{

		char * DB_name;
		char * DB_location_table;

	};

	struct DB_Despencer{

		char * locationTableHeader;

	};

	struct TABLE_HEADER{

		char *nameTable;
		char *locationTable;

	};
#endif
