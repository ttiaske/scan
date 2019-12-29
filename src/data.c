#include "data.h"
#include <errno.h>
#include <stdlib.h>


extern int errno;
struct stat st;
i_file file_info;
#define size_i_file sizeof(struct i_file)
FILE *fd;


//
int get_error(void){
        switch (errno)
        {
        case ENOENT:
            fprintf(stderr,"file not found\n");
            return ENOENT;
        case EACCES:
            fprintf(stderr,"ACCESS FAILLURE\n");
            return EACCES;
        default:
        fprintf(stderr,"number erro [%d]\n",errno);
        return errno;
        }

    }

/*return True if the inode file  of the file
  passing in parameter is in the data bin
*/
bool is_inode_bin(char *name_file){
    if((fd = fopen(FILENAME,"ab+"))== NULL)get_error();   
        // verify access file
    if(access(name_file,F_OK|R_OK) != 0){
        if(errno == EACCES){
            fprintf(stderr,"NOT Avaible\n");
            exit(EACCES);
        }
    }


    if((stat(name_file,&st))!= 0){
        get_error();
    }
    //read data in data.bin
    fread(&file_info,size_i_file,1,fd);
    printf("%d = %d\n",file_info.inode,st.st_ino);
    while(feof(fd) == 0){
        if(file_info.inode == st.st_ino)
        {

            fclose(fd);
            return true;

        }
        fread(&file_info,size_i_file,1,fd);
    }
    if(write_data(&st) != 0){
        get_error();
    }
    fclose(fd);
    return false;
}


int write_data(struct stat *st){

    file_info.inode = st->st_ino;
    file_info.time_last_to_access = st->st_atime;
    file_info.time_last_to_modification = st->st_ctime;

    if((fwrite(&file_info,size_i_file,1,fd))!= 1)
    {
        return EXIT_FAILURE;
    }
    puts("writing..");
    sleep(4);
    return EXIT_SUCCESS;
}   
