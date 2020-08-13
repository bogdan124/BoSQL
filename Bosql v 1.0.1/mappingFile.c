#include "mappingFile.h"



/*sa las la final un spatiu de 4096 de bytes destinati metadatelor*/
char *readFileMapped(char * readFile,int scanPageSize){
     int pageSize = getpagesize();

    int fd =open("Database/Database1/TABLES/table1/name.bo", O_RDWR ,S_IRUSR | S_IWUSR);
    struct stat sb;


    if(fstat(fd,&sb)==-1)
    {
        perror("couldn't get file size\n");
    }

    if(sb.st_size-pageSize<0){
            printf("%d\n",pageSize);
            printf("%f",sb.st_size-pageSize);
            char * file_in_memory=mmap(NULL,sb.st_size,PROT_READ, MAP_PRIVATE,fd,0);
            return file_in_memory;
    }else{

            char * file_in_memory=mmap(NULL,sb.st_size,PROT_READ, MAP_PRIVATE,fd,scanPageSize*pageSize);
            return file_in_memory;
    }

}


void appenFileMapped(char * file,char * addedText){


        char * num;
        char * text;

        struct stat sb;
        int pageSize;
        int fd;
        void *addr ;

        num=aloString(100);
        text=aloString(100);

        gets(text);

        pageSize = getpagesize();
        fd = open("Database/Database1/TABLES/table1/name.bo", O_RDWR | O_APPEND , 0600); //6 = read+write for me!


        if(fstat(fd,&sb)==-1)
        {
            perror("couldn't get file size\n");
        }
        sprintf(num,"%d",(sb.st_size));
        strcat(num,",");
        strcat(num,text);
        strcpy(text,num);
        strcat(text,"\n");
        lseek(fd, strlen(text), SEEK_END);
        write(fd, text, strlen(text));

        addr = mmap(NULL, (sb.st_size-pageSize)+strlen(text), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        printf("Mapped at %p\n", addr);


        munmap(addr, (sb.st_size-pageSize)+strlen(text));
        close(fd);


        free(text);
        free(num);

}



