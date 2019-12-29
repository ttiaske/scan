#ifndef __file__
#define __file__
#define _DEFAULT_SOURCE
#include <dirent.h>
#define SIZE_EXTENTION 14

#define RED "\033[0;31m"         /* 31 == CYAN */
#define RED_BOLD "\033[1;31m"    /* 1 == bold */
#define GREEN "\033[0;32m"
#define GREEN_BOLD "\033[1;32m"
#define WHITE "\033[0;37m"
#define WHITE_BOLD "\033[1;37m"
#define BLUE "\033[0;34m"
#define BLUE_BOLD "\033[1;34m"
#define PURPLE "\033[0;35m"
#define PURPLE_BOLD "\033[1;35m"
#define YELLOW "\033[0;33m"
#define YELLOW_BOLD "\033[1;33m"
#define CYAN "\033[0;36m"
#define CYAN_BOLD "\033[1;36m"
#define RESET "\x1B[0m"





//boolean type
typedef enum bool{
    false,true
}bool;

//for open the directory and get_info
int scan_dir(char *name_directory,struct dirent **name_list);

//know the info on the file
static void scan_file(char *name_file_to_scan);

//verify the 3 last char
static bool is_last_char(char the_[],char tab[]);
#endif
