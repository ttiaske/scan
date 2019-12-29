#ifndef __data__
#define __data__
#define FILENAME ".data.bin"

#include "file.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>


//keep the data
typedef struct i_file{
    int inode;
    int time_last_to_modification;
    int time_last_to_access;
}i_file;

//write stat data in the file
int write_data(struct stat *st);

//read stat data
int read_stat_data(struct stat *st);

// return nm the files
int get_number_file(void);


// is inode is in the databin
bool is_inode_bin(char *file_name);

//return the number error
int get_error(void);
#endif